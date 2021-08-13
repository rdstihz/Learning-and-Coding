#include <bits/stdc++.h>
using namespace std;
const int N = 5001;
const long long INF = 1e18;
int n, m, vis[N];
long long G[N][N], x[N], y[N];
long long dis[N];
long long Prim() {
    int minpos;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    dis[1] = 0;
    vis[1] = 0;

    //
    dis[0] = INF;
    for (int i = 1; i <= n; i++) {
        minpos = 0;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && dis[j] < dis[minpos]) minpos = j;

        ans = max(ans, dis[minpos]);
        vis[minpos] = 1;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && G[minpos][j] < dis[j]) dis[j] = G[minpos][j];
    }
    //for (int i = 1; i <= n; i++)
    //    ans = max(ans, dis[i]);
    return ans;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld%lld", &x[i], &y[i]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                G[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
        printf("%lld\n", Prim());
    }
    return 0;
}
