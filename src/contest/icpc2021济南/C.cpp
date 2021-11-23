#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 1000000 + 100;
const LL P = 998244353;
int a[maxn], c[maxn];

LL fact[maxn * 2], ifact[maxn * 2];
LL f[maxn];
LL pow_mod(LL a, LL b, LL p) {
    LL res = 1;
    while(b) {
        if(b & 1)
            res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res % p;
}

void init() {
    int n = 2000000;
    fact[0] = 1;
    for(int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % P; 
    ifact[n] = pow_mod(fact[n], P - 2, P);
    for(int i = n - 1; i >= 0; i--)
        ifact[i] = ifact[i + 1] * (i + 1 ) % P;
}

LL C(int n,int m) {
    return fact[n] * ifact[m] % P * ifact[n - m] % P;
}


int main() {
    int n;
    scanf("%d", &n);
    init();
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        c[a[i]]++;
    }

    f[0] = 1;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * fact[c[i]] % P * C(cnt + c[i] / 2, c[i] / 2) % P;
        cnt += c[i];
    }
    printf("%lld\n", f[n]);

    return 0;
}