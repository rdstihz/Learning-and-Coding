#include <iostream>

using namespace std;

const int maxn = 210;
int a[maxn];
int f[maxn][maxn];

int main() {

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    for (int l = 2 * n; l >= 1; l--)
        for (int r = l; r < 2 * n; r++) {
            for (int k = l; k < r; k++)
                f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + a[l] * a[k + 1] * a[r + 1] );
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i][i + n - 1]);
    cout << ans << endl;
    return 0;
}