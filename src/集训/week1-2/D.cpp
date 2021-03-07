#include <iostream>

const int maxn = 110;
const int maxm = 10000 + 100;

using namespace std;

int a[maxn];
int f[maxn][maxm];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= a[i])
                f[i][j] += f[i - 1][j - a[i]];
        }
    }
    cout << f[n][m] << endl;
    return 0;
}