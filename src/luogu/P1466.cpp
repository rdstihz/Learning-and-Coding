#include <bits/stdc++.h>

using namespace std;

long long dp[40][2000];

int main() {
    int n;
    cin >> n;
    int S = n * (n + 1) / 2;

    if (S % 2 == 1) {
        cout << 0;
        return 0;
    }

    S /= 2;
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int s = 0; s <= S; s++) {
            dp[i][s] = dp[i - 1][s];
            if(s >= i)
                dp[i][s] += dp[i - 1][s - i];
        }
    }
    cout << dp[n][S] / 2 << endl;
    return 0;
}