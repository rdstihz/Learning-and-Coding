#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 200;
char a[maxn], b[maxn];

int dp[maxn][maxn];

int main() {

    ios_base::sync_with_stdio(false);

    while (cin >> (a + 1) >> (b + 1)) {
        int n = strlen(a + 1);
        int m = strlen(b + 1);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (a[i] == b[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

        if (dp[n][m] == m)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        cout << flush;
    }

    return 0;
}