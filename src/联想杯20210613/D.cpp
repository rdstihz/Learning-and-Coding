#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 610;
const LL INF = 0x3f3f3f3f3f3f3f3f;

int n, m, x, y, z, s, t;
LL G[maxn][maxn];
LL w[maxn], dap[maxn];
bool vis[maxn];
int ord[maxn];
LL proc(LL x) {
    memset(vis, 0, sizeof(vis));
    memset(w, 0, sizeof(w));
    w[0] = -1;
    for (int i = 1; i <= n - x + 1; i++) {
        int mx = 0;
        for (int j = 1; j <= n; j++) {
            if (!dap[j] && !vis[j] && w[j] > w[mx]) {
                mx = j;
            }
        }
        vis[mx] = 1, ord[i] = mx;
        for (int j = 1; j <= n; j++) {
            if (!dap[j] && !vis[j]) {
                w[j] += G[mx][j];
            }
        }
    }
    s = ord[n - x], t = ord[n - x + 1];
    return w[t];
}
LL solve() {
    LL res = INF;
    for (int i = 1; i < n; i++) {
        res = min(res, proc(i));
        dap[t] = 1;
        for (int j = 1; j <= n; j++) {
            G[s][j] += G[t][j];
            G[j][s] += G[j][t];
        }
    }
    return res;
}

int readIn() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int main() {
    n = readIn();
    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            G[i][j] = readIn();
            ans += G[i][j];
        }
    }

    printf("%lld\n", ans - 2 * solve());
    return 0;
}