#include <iostream>

using namespace std;

const int maxn = 1010;
const int P = 10007;

int C[maxn][maxn];

int pow_mod(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % P;
        a = (a * a) % P;
        b >>= 1;
    }
    return res % P;
}

int main() {
    int a, b, n, m, k;
    cin >> a >> b >> k >> n >> m;

    C[0][0] = 1;

    for (int i = 1; i <= k; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
        }
    }

    int ans = ((pow_mod(a, n) * pow_mod(b, m) % P) * C[k][n]) % P;

    cout << ans << endl;

    return 0;
}