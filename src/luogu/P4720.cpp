//这份代码不能AC
//可能是因为爆了long long
//python代码可以过


#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL pow_mod(LL a, LL b, LL p) {
    LL res = 1;
    while (b) {
        if (b & 1)
            res = res * a % p;

        b >>= 1;
        a = a * a % p;
    }
    return res;
}

void exgcd(LL a, LL b, LL& x, LL& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    } else {
        exgcd(b, a % b, y, x);
        y -= a / b * x;
        
    }
}

LL inv(LL a, LL b) {
    
    LL x, y;
    exgcd(a, b, x, y);
    return (x % b + b) % b;
}

LL T;

LL f(LL n, LL p, LL pk) {
    if (n == 0)
        return 1;

    LL res = f(n / p, p, pk);
    res = res * pow_mod(T, n / pk, pk) % pk;
    for (LL i = n / pk * pk + 1; i <= n; i++)
        if (i % p != 0)
            res = res * (i % pk) % pk;
    
    return res;
}

LL g(LL n, LL p) {
    if (n == 0)
        return 0;
    else
        return g(n / p, p) + n / p;
}

int primes[200], alphas[200];

LL a[200], b[200];

int main() {
    LL n, m, P;

    cin >> n >> m >> P;
    int tot = 0;
    LL p2 = P;
    for (int i = 2; i * i <= P; i++) {
        if (P % i == 0) {
            primes[++tot] = i;
            alphas[tot] = 0;
            while (P % i == 0) {
                alphas[tot]++;
                P /= i;
            }
        }
    }
    if (P > 1) {
        primes[++tot] = P;
        alphas[tot] = 1;
    }
    P = p2;

    for (int i = 1; i <= tot; i++) {
        b[i] = pow_mod(primes[i], alphas[i], 998244353ll);
        LL pk = b[i];
        LL p = primes[i];
        T = 1;
        for (LL j = 1; j <= pk; j++)
            if (j % p != 0)
                T = T * j % pk;
        a[i] = f(n, p, pk) * ((inv(f(m, p, pk), pk)) * inv(f(n - m, p, pk), pk) % pk) % pk;
        a[i] = a[i] * pow_mod(p, g(n, p) - g(m, p) - g(n - m, p), pk) % pk;
    }

    LL ans = 0;

    for (int i = 1; i <= tot; i++) {
        LL Mi = P / b[i];
        ans += (a[i] * (Mi * inv(Mi, b[i])) % P) % P;
        ans %= P;
    }

    cout << ans << endl;

    return 0;
}