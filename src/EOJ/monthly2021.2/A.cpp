#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 50000 + 100;
typedef pair<int, int> PII;

vector<PII> G[maxn];

int dep[maxn];
int dist[maxn];
int dfn[maxn];
int tot;

int st[maxn][16];

void dfs(int u, int f) {
    dfn[u] = ++tot;
    for (PII e : G[u])
        if (e.first != f) {
            dep[e.first] = dep[u] + 1;
            dist[e.first] = dist[u] + e.second;
            st[e.first][0] = u;
            dfs(e.first, u);
        }
}

void st_init(int n) {

    for (int k = 1; k <= 15; k++) {
        for (int i = 1; i <= n; i++)
            st[i][k] = st[st[i][k - 1]][k - 1];
    }
}

bool cmp(int a, int b) {
    return dfn[a] < dfn[b];
}

int LCA(int a, int b) {
    if (dep[a] < dep[b]) {
        swap(a, b);
    }

    int dd = dep[a] - dep[b];

    for (int i = 0; i <= 15; i++)
        if ((dd >> i) & 1)
            a = st[a][i];

    if (a == b)
        return a;

    for (int i = 15; i >= 0; i--) {
        if (st[a][i] != st[b][i]) {
            a = st[a][i];
            b = st[b][i];
        }
    }
    return st[a][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    int u, v, w;
    for (int i = 1; i < n; i++) {

        cin >> u >> v >> w;
        u++;
        v++;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    dep[1] = 1;
    dist[1] = 0;

    dfs(1, 0);

    st_init(n);

    int a[7];
    int m;
    cin >> m;
    while (m--) {
        for (int i = 1; i <= 5; i++) {
            cin >> a[i];
            a[i]++;
        }
        sort(a + 1, a + 6, cmp);
        a[6] = a[1];

        int ans = 0;

        for (int i = 2; i <= 6; i++) {
            int lca = LCA(a[i - 1], a[i]);
            ans += dist[a[i - 1]] + dist[a[i]] - 2 * dist[lca];
        }
        cout << ans / 2 << endl;
    }

    return 0;
}
/*

6
4 0 4
0 1 2
1 3 9
3 5 1
3 2 5
2
4 0 3 5 2
0 4 1 3 5


*/