#include <cstring>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;

int dp[(1 << 20) + 5];

int a[110];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> t;
            t--;
            a[i] |= 1 << t;
        }
    }

    memset(dp, 0x3f, sizeof(dp));

    int p = 0;

    for (int i = 1; i <= n; i++) {
        dp[0] = 0;

        for (int S = (1 << m) - 1; S >= 0; S--)
            if (dp[S] != INF) {
                dp[S | a[i]] = min(dp[S | a[i]], dp[S] + 1);
            }
    }

    if (dp[(1 << m) - 1] == INF) {
        cout << -1 << endl;
    } else {
        cout << dp[(1 << m) - 1] << endl;
    }

    return 0;
}