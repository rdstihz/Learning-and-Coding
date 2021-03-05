#include <iostream>

using namespace std;

typedef long long LL;


const LL P = 999911659;

LL a[8], b[8];

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
    if(m == 0) return 1;
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
    int n, q;
    cin >> n >> q;
    int p = P - 1;

    //将p分解质因数
    int k = 0, pp = p;
    for (int i = 2; i * i <= pp; i++) {
        if (pp % i == 0) {
            a[++k] = i;
            while (pp % i == 0) {
                pp /= i;
            }
        }
    }
    if (pp > 1)
        a[++k] = pp;

    for (int i = 1; i <= k; i++)
        cout << a[i] << " ";
    cout << endl;

    for (int i = 1; i <= k; i++) {
        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                b[i] = (b[i] + lucas(n, d, a[i]));
                if (d * d != n)
                    b[i] = (b[i] + lucas(n, n / d, a[i])) % a[i];
            }
        }
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
    //cout << ans << endl;
    cout << pow_mod(q, ans, P) << endl;
    return 0;
}