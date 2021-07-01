#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 2010;

typedef long long LL;

LL a[maxn];

LL dp[maxn][maxn];

int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);

    for (int l = n; l >= 1; l--) {
        for (int r = l; r <= n; r++) {
            if (l == r)
                dp[l][r] = 0;
            else {
                dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + a[r] - a[l];
            }
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}