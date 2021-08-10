#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 100000 + 100;

int f[maxn];
int dfn[maxn], low[maxn], color[maxn], num, st[maxn], top, ts;
int sze[maxn];
bool ins[maxn];
int deg[maxn];
LL val[maxn];

void dfs(int u) {
    dfn[u] = low[u] = ++ts;
    st[++top] = u;
    ins[u] = true;
    int v = f[u];
    if (!dfn[v]) {
        dfs(v);
        low[u] = min(low[u], low[v]);
    } else if (ins[v])
        low[u] = min(low[u], dfn[v]);

    if (dfn[u] == low[u]) {
        num++;
        int x;
        do {
            x = st[top--];
            ins[x] = 0;
            color[x] = num;
            sze[num]++;
        } while (x != u);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", f + i);

        ts = top = num = 0;
        for (int i = 1; i <= n; i++) {
            dfn[i] = low[i] = 0;
            color[i] = 0;
            ins[i] = 0;
            val[i] = 0;
            sze[i] = 0;
            deg[i] = 0;
        }

        for (int i = 1; i <= n; i++)
            if (!dfn[i])
                dfs(i);

        for (int i = 1; i <= n; i++)
            val[color[i]] += i;

        for (int i = 1; i <= n; i++) {
            if (color[i] == color[f[i]]) continue;
            deg[color[i]]++;
        }

        vector<int> e;
        for (int i = 1; i <= num; i++) {
            if (deg[i] == 0) {
                e.push_back(i);
            }
        }
        bool flag = true;
        for (int i = 1; i < e.size(); i++) {
            if (val[e[i]] * sze[e[i - 1]] != val[e[i - 1]] * sze[e[i]]) {
                flag = false;
                break;
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }

    return 0;
}