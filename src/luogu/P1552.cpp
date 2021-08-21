#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 10;
typedef long long LL;
int b[maxn], c[maxn];
vector<int> G[maxn];
int root[maxn], dis[maxn], lc[maxn], rc[maxn];
int cnt[maxn];
LL cost[maxn], ans;

int n, m;

int merge(int x, int y) {
    if (!x || !y) return x | y;
    if (c[x] < c[y]) swap(x, y);
    rc[x] = merge(rc[x], y);
    if (dis[lc[x]] < dis[rc[x]]) swap(lc[x], rc[x]);
    dis[x] = dis[rc[x]] + 1;
    return x;
}

void dfs(int u) {
    cnt[u] = 1, cost[u] = c[u];
    for (int v : G[u]) {
        dfs(v);
        root[u] = merge(root[u], root[v]);
        cnt[u] += cnt[v], cost[u] += cost[v];
    }
    while (cost[u] > m) {
        cnt[u]--, cost[u] -= c[root[u]];
        root[u] = merge(lc[root[u]], rc[root[u]]);
    }
    ans = max(ans, 1ll * b[u] * cnt[u]);
}

int main() {

    scanf("%d%d", &n, &m);
    int f;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &f, c + i, b + i);
        G[f].push_back(i);
        root[i] = i, dis[i] = 1;
        cnt[i] = 1, cost[i] = c[i];
    }
    ans = 0;
    dfs(1);
    printf("%lld\n", ans);
    return 0;
}
