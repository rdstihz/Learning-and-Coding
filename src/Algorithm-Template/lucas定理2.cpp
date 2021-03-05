#include <iostream>

using namespace std;

typedef long long LL;

const int maxn = 1000000 + 10;

LL a[maxn], b[maxn];

LL pow_mod(LL a, LL b, LL p) {
    LL res = 1;
    while (b) {
        if (b & 1)
            res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res % p;
}

LL C(LL n, LL m, LL p) {
    if (n < m) return 0;
    LL res = 1;
    LL a = 1, b = 1;
    for (int i = m + 1; i <= n; i++)
        a = a * i % p;
    for (int i = 1; i <= n - m; i++)
        b = b * i % p;
    return a * pow_mod(b, p - 2, p) % p;
}

LL lucas(int n, int m, int p) {
    LL res = 1;
    while (n || m) {
        res = res * C(n % p, m % p, p) % p;
        n /= p;
        m /= p;
    }
    return res;
}

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    //将p分解质因数
    int k = 0, pp = p;
    for (int i = 2; i * i <= pp; i++) {
        if (pp % i == 0) {
            a[++k] = 1;
            while (pp % i == 0) {
                pp /= i;
                a[k] *= i;
            }
        }
    }
    if (pp > 1)
        a[++k] = pp;

    for (int i = 1; i <= k; i++)
        cout << a[i] << " ";
    cout << endl;

    for (int i = 1; i <= k; i++) {
        b[i] = lucas(n, m, a[i]);
    }

    for (int i = 1; i <= k; i++) {
        cout << a[i] << " " << b[i] << endl;
    }

    LL M = 1;
    for (int i = 1; i <= k; i++) {
        M = M * a[i];
    }

    LL ans = 0;
    for (int i = 1; i <= k; i++) {
        LL Mi = M / a[i];
        LL x = (b[i] * Mi % p) * pow_mod(Mi, a[i] - 2, a[i]) % p;
        ans = (ans + x) % p;
    }
    cout << ans << endl;
    return 0;
}