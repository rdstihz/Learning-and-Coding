#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;
const int maxm = 10020;
const int INF = 0x3f3f3f3f;

int to[maxm], cap[maxm], tot;
int fir[maxn], cur[maxn], nxt[maxm];

int q[maxn], dep[maxn];

void add(int a, int b, int c) {
    tot++;
    to[tot] = b, cap[tot] = c;
    nxt[tot] = fir[a], fir[a] = tot;
}

int s, t, n, m;

bool bfs() {
    int l, r;
    l = r = 0;

    memset(dep, 0, sizeof(dep));
    dep[s] = 1;
    q[++r] = s;

    while (l < r) {
        int u = q[++l];
        for (int e = fir[u]; e; e = nxt[e]) {
            int v = to[e];
            if (cap[e] && dep[v] == 0) {
                dep[v] = dep[u] + 1;
                q[++r] = v;

                if (v == t) return true;
            }
        }
    }
    return false;
}

int dfs(int u, int rest) {
    if (u == t) return rest;
    int fl = 0;

    for (int e = cur[u]; e && rest; e = nxt[e]) {
        cur[u] = e;

        int v = to[e];
        if (cap[e] && dep[v] == dep[u] + 1) {
            int k = dfs(v, min(rest, cap[e]));

            fl += k, rest -= k;
            cap[e] -= k, cap[e ^ 1] += k;

            if (!k) dep[v] = -1;
        }
    }
    return fl;
}

int Dinic() {
    int res = 0;
    while (bfs()) {
        for (int i = 1; i <= n + 2; i++)
            cur[i] = fir[i];

        res += dfs(s, INF);
    }
    return res;
}

int main() {
    cin >> m >> n;

    s = n + 1, t = n + 2;

    tot = 1;
    for (int i = 1; i <= m; i++) {
        add(s, i, 1);
        add(i, s, 0);
    }
    for (int i = m + 1; i <= n; i++) {
        add(i, t, 1);
        add(t, i, 0);
    }
    int a, b;
    int st = tot + 1;
    while (cin >> a >> b && a != -1) {
        add(a, b, 1);
        add(b, a, 0);
    }

    cout << Dinic() << endl;

    for(int i = st; i <= tot; i += 2) {
        if(!cap[i]) {
            cout << to[i^ 1] << " " << to[i] << endl;
        }
    }

    return 0;
}