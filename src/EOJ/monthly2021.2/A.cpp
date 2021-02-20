#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 50000 + 10;
const int N = 15;

int to[maxn * 2], nxt[maxn * 2], len[maxn * 2];
int fir[maxn];
int tot;

int n;

void add(int u, int v, int w) {
    tot++;
    to[tot] = v, len[tot] = w;
    nxt[tot] = fir[u], fir[u] = tot;

    tot++;
    to[tot] = u, len[tot] = w;
    nxt[tot] = fir[v], fir[v] = tot;
}

int dep[maxn], st[maxn][N + 1];
int dist[maxn]; //去父节点的距离
bool vis[maxn];

void dfs(int u, int f) {

    for (int e = fir[u]; e; e = nxt[e]) {
        int v = to[e];
        if (!dep[v]) {
            dep[v] = dep[u] + 1;
            st[v][0] = u;
            dist[v] = len[e];
            dfs(v, u);
        }
    }
}

void st_init() {
    for (int k = 1; k <= N; k++)
        for (int i = 0; i <= n; i++)
            st[i][k] = st[st[i][k - 1]][k - 1];
}

int LCA(int a, int b) {
    if (dep[a] < dep[b])
        swap(a, b);
    int dh = dep[a] - dep[b];
    for (int i = N; i >= 0; i--)
        if (dh & (1 << i)) {
            a = st[a][i];
            dh -= 1 << i;
        }
    if (a == b) return a;
    for (int i = N; i >= 0; i--) {
        if (st[a][i] != st[b][i]) {
            a = st[a][i];
            b = st[b][i];
        }
    }
    return st[a][0];
}

int main() {

    cin >> n;
    int u, v, w;

    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        u++;
        v++;
        add(u, v, w);
    }
    dep[1] = 1;
    dfs(1, 0);
    st_init();

    int q;
    cin >> q;
    int a[5];
    while (q--) {
        for (int i = 0; i < 5; i++) {
            cin >> a[i];
            a[i]++;
        }
        int lca = a[0];
        for (int i = 1; i < 5; i++) {
            lca = LCA(lca, a[i]);
        }

        int ans = 0;
        memset(vis,0,sizeof(vis));
        vis[lca] = true;
        for(int i = 0;i < 5;i++) {
            int u = a[i];
            while(!vis[u]) {
                ans += dist[u];
                vis[u] = true;
                u = st[u][0];
                
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}