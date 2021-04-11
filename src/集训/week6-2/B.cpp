#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL P = 19260817;

LL dp[3000][15];

int main1() {

    dp[0][9] = 1;

    for (int i = 1; i <= 2021; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = j; k <= 9; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % P;
            }
        }
    }

    LL ans = 0;

    for (int i = 1; i <= 9; i++)
        ans = (ans + dp[2021][i]) % P;

    cout << ans << endl;

    return 0;
}

int main() {
    dp[0][1] = 1;

    for (int i = 1; i <= 2022; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = j; k >= 0; k--)
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % P;
        }
    }

    cout << dp[2022][9];

    return 0;
}