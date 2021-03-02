#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;

int f[maxn][2000];
int t[maxn], c[maxn];

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> c[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= t[i]) {
                f[i][j] = max(f[i][j], f[i - 1][j - t[i]] + c[i]);
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}