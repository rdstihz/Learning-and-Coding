#include <iostream>

using namespace std;

const int maxn = 200;
const int P = 1000007;

int f[maxn][maxn];
int a[maxn];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    f[0][0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        f[i][0] = 1;
        for (int j = 1; j <= m; j++) {
            f[i][j] = 0;
            for (int k = 0; k <= a[i] && k <= j; k++)
                f[i][j] = (f[i][j] + f[i - 1][j - k]) % P;
            
        }
    }
    cout << f[n][m] << endl;
    return 0;
}