// luogu P3807
#include <iostream>

using namespace std;
typedef long long LL;

const int maxn = 100000 + 100;
LL n, m, p;
LL prod[maxn], aprod[maxn];

LL pow_mod(LL a, LL b, LL p) {
    LL res = 1;
    while (b) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res % p;
}

LL C(int n, int m) {
    if (n > m)
        return 0;
    LL res = 1;
    for (int i = n + 1; i <= m; i++)
        res = res * i % p;
    for (int i = 1; i <= m - n; i++)
        res = res * pow_mod(i, p - 2, p) % p;
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> p;
        m += n;

        LL ans = 1;
        while (n || m) {
            ans = ans * C(n % p, m % p) % p;
            n /= p;
            m /= p;
        }
        cout << ans << endl;
    }

    return 0;
}