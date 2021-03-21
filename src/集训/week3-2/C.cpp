#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 310;

int g[maxn][maxn];

int main() {
    int n, m, T;
    cin >> n >> m >> T;
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = w;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], max(g[i][k], g[k][j]));
    while (T--) {
        int a,b;
        cin >> a >> b;
        if(g[a][b] == INF) {
            cout << -1 << endl;
        }else{
            cout << g[a][b] << endl;
        }
    }
}
