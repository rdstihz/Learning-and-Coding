#include <iostream>

using namespace std;

typedef long long LL;

LL P = 1e9 + 7;

LL a[100], b[100];

void divide(LL x, LL k, LL* p) {
    p[0] = 0;
    while (x) {
        p[++p[0]] = x % k;
        x /= k;
    }
}

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

int main() {
    LL T, k;
    cin >> T >> k;
    LL n, m;
    LL t = k * (k + 1) / 2;
    while (T--) {
        cin >> n >> m;
        divide(n, k, a);
        divide(m, k, b);

        LL res = pow_mod(t, min(a[0], b[0]) - 1, P);
    }

    return 0;
}