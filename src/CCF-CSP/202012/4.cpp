#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 110;

int w[maxn][maxn];
int n, m, k;
vector<int> G[13];

int get_price(int x, int s) {
    int sum = 0, maxv = 0;
    for (int v : G[x]) {
        sum += w[s][v];
        maxv = max(maxv, w[s][v]);
    }
    return 2 * sum - maxv;
}

int ans;
int point[13];
bool ispoint[maxn];
void dfs(int d, int ms, int maxt) {

    if (d > k) {
        ans = min(ans, maxt);
        return;
    }
    if (maxt >= ans) return;

    //首先考虑已有的检查点
    for (int i = 1; i <= ms; i++) {
        int p = get_price(d, point[i]);
        dfs(d + 1, ms, max(maxt, p));
        if (p <= maxt) break;
    }

    //新建检查点
    if (ms < m)
        for (int i = 1; i <= n; i++) {
            if (!ispoint[i]) {
                int p = get_price(d, i);
                ispoint[i] = true;
                point[ms + 1] = i;

                dfs(d + 1, ms + 1, max(maxt, p));
                ispoint[i] = false;
            }
        }
}

int main() {
    memset(w, 0x3f, sizeof w);
    cin >> n >> m >> k;
    int t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> t;
            if (t) {
                G[j].push_back(i);
            }
        }
    }

    int a, b, c;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        w[a][b] = w[b][a] = c;
    }
    for(int i = 1;i <= n;i++) {
        w[i][i] = 0;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) {
            cout << w[i][j] << " ";
        }
        cout << endl;
    }

    ans = INF;
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}