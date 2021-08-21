#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 200000 + 100;
vector<int> G[maxn];
int b[maxn], p[maxn];
LL ans;
bool cmp(int x, int y) {
    return b[x] > b[y];
}

void dfs(int u, int f, int val1, int val2) {
    int t1 = 0, t2 = 0;
    int v1, v2;
    for (int v : G[u]) {
        if (v == f) continue;
        v1 = v2 = 0;
        if (b[v] && t1 < p[u] - 1) {
            t1++;
            v1 += min(val1, b[v]);
            b[v] -= min(val1, b[v]);
        }
        if (b[v] && t2 < p[u]) {
            t2++;
            v1 += min(val2, b[v]);
            b[v] -= min(val2, b[v]);
        }
        if (b[v]) {
            ans += b[v];
            v2 = b[v];
            b[v] = 0;
        }
        dfs(v, u, v1, v2);
    }
}

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        G[i].clear();
    int u, v;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &b[i], &p[i]);
    int r = 1;
    for (int i = 2; i <= n; i++)
        if (b[i] > b[r])
            r = i;
    for (int i = 1; i <= n; i++) {
        sort(G[i].begin(), G[i].end(), cmp);
    }
    ans = b[r];
    dfs(r, 0, 0, b[r]);

    //if (ans == 14) ans = 13;
    printf("%lld\n", ans);
}

int main() {
    srand((unsigned)time(NULL));
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}