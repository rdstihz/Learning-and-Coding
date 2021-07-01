#include <bits/stdc++.h>


using namespace std;


const int maxn = 103;

int a[maxn], b[maxn];

int dp[2][maxn][maxn * maxn];

int main() {

    int n;
    int m = 0;
    int total = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        m += a[i];
        total += b[i];
    }

    memset(dp, 0x80, sizeof(dp));

    dp[0][0][0] = 0;
    dp[1][0][0] = 0;
    int p = 0;
    for (int i = 1; i <= n; i++) {
        p ^= 1;
        for (int k = 1; k <= i; k++) {
            for (int A = 0; A <= m; A++) {
                dp[p][k][A] = dp[p ^ 1][k][A];
                if (A >= a[i] && dp[p ^ 1][k - 1][A - a[i]] + b[i] > dp[p][k][A]) {
                    dp[p][k][A] = dp[p ^ 1][k - 1][A - a[i]] + b[i];
                }
            }
        }
    }
    for(int k = 1; k <= n; k++) {
        int ans = 0;
        for(int A = 1;A <= m; A++) {
            ans = max ( ans, min( 2*A, total + dp[p][k][A]) );
        }
        cout << ans / 2.0 << " ";
    }
    cout << endl;

    return 0;
}