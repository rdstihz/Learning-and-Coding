#include <cstdio>

typedef long long LL;
const LL P = 1e9 + 7;
LL a[30];
LL prod[30], aprod[30];
LL n, m;

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

inline LL C(LL n, LL m) {
    LL a = 1, b = 1;

    for (LL i = n; i > n - m; i--)
        a = a * (i % P) % P;
    // for (LL i = 1; i <= m; i++)
    //     b = b * i % P;
    b = prod[m];
    return a * pow_mod(b, P - 2, P) % P;
}

template <typename T>
void read(T& x) {
    x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
}

int main() {

    read(n);
    read(m);

    prod[0] = aprod[i] = 1;
    for (int i = 1; i <= n; i++) {
        prod[i] = prod[i - 1] * i % P;
        aprod[i] = pow_mod(prod[i], P - 2, P);
    }

    for (int i = 0; i < n; i++)
        read(a[i]);
    LL ans = 0;
    for (int S = 0; S < 1 << n; S++) {
        LL t = n + m - 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (S >> i & 1) {
                cnt++;
                t -= a[i] + 1;
            }
        if (t <= 0)
            continue;
        if (cnt % 2 == 0) {
            ans = (ans + C(t, n - 1)) % P;
        } else {
            ans = (ans + P - C(t, n - 1)) % P;
        }
    }
    printf("%lld\n", ans);
    return 0;
}