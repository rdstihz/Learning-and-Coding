#include <iostream>

using namespace std;

bool dp[30][700];

int main() {

    int n;
    cin >> n;
    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int p = 0; p <= n * n; p++) {
            for (int j = 1; j <= i; j++) {
                if (p >= (i - j) * j)
                    dp[i][p] |= dp[i - j][p - (i - j) * j];
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= n * n; i++)
        ans += dp[n][i];
    cout << ans << endl;

    return 0;
}