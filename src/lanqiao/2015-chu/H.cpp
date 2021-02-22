#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 50000 + 100;
const int maxm = 200000 + 20;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& phs) const {
        return w < phs.w;
    }
} edge[maxm];

int n, m, q;

vector<pair<int, int>> G[maxn]; //最小生成树

int p[maxn];
int findf(int x) {
    return p[x] == x ? x : p[x] = findf(p[x]);
}

void MST() {
    for (int i = 1; i <= n; i++)
        p[i] = i;
    sort(edge + 1, edge + 1 + m);
    int cnt = 0;
    cout << endl << endl;
    for (int i = 1; i <= m; i++) {
        int a = findf(edge[i].u);
        int b = findf(edge[i].v);
        if (a == b) continue;

        //加入边edge[i]
        p[a] = b;
        G[edge[i].u].push_back(make_pair(edge[i].v, edge[i].w));
        G[edge[i].v].push_back(make_pair(edge[i].u, edge[i].w));
        cnt++;
        cout << edge[i].u << " " << edge[i].v << " " << edge[i].w << endl;
        if (cnt == n - 1) break;
    }
}

int dep[maxn];
int dist[maxn][16], st[maxn][16];

void dfs(int u, int f) {

    for (auto e : G[u]) {
        if (e.first == f) continue;
        int v = e.first;
        dep[v] = dep[u] + 1;
        st[v][0] = u;
        dist[v][0] = e.second;
        dfs(v, u);
    }
}

void lca_init() {
    dep[1] = 0;
    dfs(1, 0);

    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= 15; k++) {
            st[i][k] = st[st[i][k - 1]][k - 1];
            dist[i][k] = max(dist[i][k - 1], dist[st[i][k - 1]][k - 1]);
        }
}

int l, r, k, c;
int ans;

int LCA(int a, int b) {
    if (dep[a] < dep[b]) {
        swap(a, b);
    }
    int dd = dep[a] - dep[b];

    for (int i = 15; i >= 0; i--)
        if (dd & (1 << i)) {
            ans = max(ans, dist[a][i]);
            a = st[a][i];
        }
    if (a == b) return a;

    for (int i = 15; i >= 1; i--)
        if (st[a][i] != st[b][i]) {
            ans = max(ans, dist[a][i]);
            ans = max(ans, dist[b][i]);
            a = st[a][i];
            b = st[b][i];
        }

    ans = max(ans, dist[a][0]);
    ans = max(ans, dist[b][0]);
    return st[a][0];
}

int main() {
    
    cin >> n >> m >> q;

    for (int i = 1; i <= m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }

    //构造最小生成树
    MST();
    

    while (q--) {
        cin >> l >> r >> k >> c;
        ans = 0;
        int lca = (l - c - 1) / k + 1;
        lca = lca * k + c;
        if (l <= c) lca = c;

        for (int j = lca + k; j <= r; j += k) {
            lca = LCA(lca, j);
        }
        cout << ans << endl;
    }

    return 0;
}