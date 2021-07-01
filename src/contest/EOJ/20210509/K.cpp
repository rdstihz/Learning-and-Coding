#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
const int INF = 0x3f3f3f3f;

int w[12][maxn];
int dp[maxn][12];

int main() {

    
    int n, m;
    while (cin >> n) {
        int t, p, k;
        m = 0;
        memset(w, 0, sizeof(w));
        
        for (int i = 1; i <= n; i++) {
            cin >> t >> p >> k;
            if (k == 0)
                w[p][t] += 1;
            else if (k == 1)
                w[p][t] -= 1;
            m = max(m, t);
        }

        memset(dp, ~0x3f, sizeof(dp)); // -INF
        dp[0][5] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j <= 10; j++) {
                dp[i][j] = dp[i - 1][j] + w[j][i];
                if (j > 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + w[j][i]);
                if (j < 10)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + w[j][i]);
            }
        }

        int ans = -INF;
        for (int i = 0; i <= 10; i++)
            ans = max(ans, dp[m][i]);
        cout << ans << endl;
    }

    return 0;
}