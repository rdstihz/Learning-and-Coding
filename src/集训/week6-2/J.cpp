#include <iostream>

using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
LL P = 1e9 + 7;

LL dp[2][maxn];

int main() {

    int s, t, k;
    cin >> s >> t >> k;

    LL ans = 0;

    dp[0][s] = 1;
    ans += dp[0][t];
    int p = 0;
    for (int i = 1; i <= k; i++) {
        dp[p ^ 1][0] = dp[p][1];
        if (t == 0)
            ans += dp[p ^ 1][0];

        for (int j = 1; j <= s + k; j++) {
            dp[p ^ 1][j] = (dp[p][j - 1] + dp[p][j + 1]) % P;
            if (j == t)
                ans = (ans + dp[p ^ 1][j]) % P;
        }

        p ^= 1;
    }
    cout << ans << endl;
    return 0;
}