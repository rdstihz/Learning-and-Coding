#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;

int to[maxm], nxt[maxm];
int fir[maxn], tot;
int color[maxn];

int sze[maxn], edges[maxn]; // 各连通分量点的数量， 边的数量
int deg[maxn];

bool bad[maxn];

void add(int a, int b) {
    tot++;
    to[tot] = b, nxt[tot] = fir[a], fir[a] = tot;
}

void dfs(int u, int id) {
    sze[id]++;
    color[u] = id;

    for (int e = fir[u]; e; e = nxt[e]) {
        int v = to[e];
        if (!color[v]) dfs(v, id);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {

        tot = 0;
        memset(fir, 0, sizeof(fir));
        memset(deg, 0, sizeof(deg));
        memset(color, 0, sizeof(color));
        memset(bad, true, sizeof(bad));
        memset(edges, 0, sizeof(edges));
        memset(sze, 0, sizeof(sze));

        int n, m;
        cin >> n >> m;

        int u, v;

        for (int i = 1; i <= m; i++) {
            cin >> u >> v;
            add(u, v);
            add(v, u);
            deg[u]++;
            deg[v]++;
        }

        //划分连通分量
        int cnt = 0;

        for (int i = 1; i <= n; i++) {
            if (!color[i])
                dfs(i, ++cnt);
        }

        //统计各连通分量中边的数量
        for (int i = 1; i <= tot; i += 2) {
            edges[color[to[i]]]++;
        }

        bool fullmap = false;
        for (int i = 1; i <= cnt; i++) {
            if (sze[i] >= 3 && edges[i] == sze[i] * (sze[i] - 1) / 2) {
                fullmap = true;
                break;
            }
        }

        if (fullmap) {
            cout << "NO" << endl;
            continue;
        }

        for (int i = 1; i <= cnt; i++) {
            if (sze[i] < 4) bad[i] = false;
        }
        for (int i = 1; i <= n; i++) {
            if (deg[i] % 2)
                bad[color[i]] = false;
        }
        bool flag = false;
        for (int i = 1; i <= cnt; i++) {
            flag |= bad[i];
        }
        if (flag) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}