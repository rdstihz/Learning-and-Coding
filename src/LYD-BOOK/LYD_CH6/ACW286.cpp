
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 400;

int to[maxn], fir[maxn], nxt[maxn], tot;

void add_edge(int a, int b) {
    tot++;
    to[tot] = b;
    nxt[tot] = fir[a], fir[a] = tot;
}

int a[maxn];

int dp[maxn][maxn];
int n, m;
int dfs(int u) {

    int sz = 1;

    dp[u][1] = a[u];
    for (int e = fir[u]; e; e = nxt[e]) {
        int v = to[e];
        int t = dfs(v);
        sz += t;

        for (int j = min(m, sz); j >= 2; j--) {
            for (int k = 1; k <= t && k < j; k++) {
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
            }
        }
    }
    return sz;
}

int main() {

    cin >> n >> m;
    m++;
    int u;
    for (int i = 1; i <= n; i++) {
        cin >> u >> a[i];
        add_edge(u, i);
    }

    dfs(0);

    cout << dp[0][m] << endl;

    return 0;
}
