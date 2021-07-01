#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;
const int maxm = 2 * maxn;

int v[maxn], t[maxn], delta[maxn];

int to[maxm], nxt[maxm];
int fir[maxn], tot;
int color[maxn];

void add_edge(int a, int b) {
    tot++;
    to[tot] = b, nxt[tot] = fir[a], fir[a] = tot;
}

bool dfs(int u, int c) {
    color[u] = c;

    for (int e = fir[u]; e; e = nxt[e]) {
        int v = to[e];
        if (color[v] && color[v] == c)
            return false;
        else if (!color[v] && !dfs(v, 3 - c))
            return false;
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        tot = 0;
        memset(color, 0, sizeof(color));
        memset(fir, 0, sizeof(fir));

        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", v + i);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", t + i);
        }

        int a, b;
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &a, &b);
            add_edge(a, b);
            add_edge(b, a);
        }

        long long S = 0;
        for (int i = 1; i <= n; i++) {
            delta[i] = t[i] - v[i];
            S += delta[i];
        }
        if (S % 2) {
            printf("NO\n");
            continue;
        }

        if (dfs(1, 1)) {
            long long S1 = 0, S2 = 0;
            for (int i = 1; i <= n; i++) {
                if (color[i] == 1)
                    S1 += delta[i];
                else
                    S2 += delta[i];
            }
            printf("%s\n", S1 == S2 ? "YES" : "NO");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}