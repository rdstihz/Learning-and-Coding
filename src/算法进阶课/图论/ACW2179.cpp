#include <bits/stdc++.h>

const int maxn = 1000;
const int maxm = 200000 + 100;
const int INF = 0x3f3f3f3f;

using namespace std;

int to[maxm], cap[maxm], tot;
int fir[maxn], cur[maxn], nxt[maxm];

int dep[maxn], q[maxn];

void add(int a, int b, int c) {
    tot++;
    to[tot] = b, cap[tot] = c;
    nxt[tot] = fir[a], fir[a] = tot;
}

int n, m, s, t;

bool bfs() {
    memset(dep, 0, sizeof(dep));
    int l, r;
    l = r = 0;

    dep[s] = 1;
    q[++r] = s;

    while (l < r) {
        int u = q[++l];

        for (int e = fir[u], v = to[e]; e; e = nxt[e], v = to[e]) {
            if (cap[e] && !dep[v]) {
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
            int v = to[e];
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
        for (int i = 1; i <= n + m + 2; i++)
            cur[i] = fir[i];
        res += dfs(s, INF);
    }
    return res;
}

int main() {

    cin >> m >> n;

    s = n + m + 1;
    t = n + m + 2;

    int S = 0;
    tot = 1;

    //m个单位
    int v;
    for (int i = 1; i <= m; i++) {
        cin >> v;
        add(s, i, v);
        add(i, s, 0);
        S += v;
    }

    //n张圆桌
    for (int i = 1; i <= n; i++) {
        cin >> v;
        add(m + i, t, v);
        add(t, m + i, 0);
    }

    for (int i = 1; i <= m; i++) {
        for (int j = m + 1; j <= n + m; j++) {
            add(i, j, 1);
            add(j, i, 0);
        }
    }

    int f = Dinic();

    if (f == S) {
        cout << 1 << endl;

        for (int u = 1; u <= m; u++) {
            for (int e = fir[u]; e; e = nxt[e])
                if (to[e] > m && to[e] <= n + m && cap[e] == 0) {
                    cout << to[e] - m << " ";
                }
            cout << endl;
        }

    } else {
        cout << 0 << endl;
    }

    return 0;
}