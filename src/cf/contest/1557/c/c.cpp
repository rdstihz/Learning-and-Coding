/*
    Created by rdstihz at 2021-08-16 22:49:17
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL P = 1e9 + 7;
const int maxn = 200000 + 100;
LL frac[maxn], afrac[maxn];
LL B[maxn];
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

void init() {
    int N = 200000;
    frac[0] = 1;
    for (int i = 1; i <= N; i++)
        frac[i] = frac[i - 1] * i % P;
    afrac[N] = pow_mod(frac[N], P - 2, P);
    for (int i = N - 1; i >= 0; i--)
        afrac[i] = afrac[i + 1] * (i + 1) % P;
    B[0] = 1;
    for (int i = 1; i <= N; i++)
        B[i] = 2 * B[i - 1] % P;
}

LL C(int n, int m) {
    return frac[n] * afrac[n - m] % P * afrac[m] % P;
}
LL f[maxn];
void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    if (n % 2 == 1) {
        LL t = 1;
        for (int i = 0; i < n; i += 2)
            t = (t + C(n, i)) % P;
        printf("%lld\n", pow_mod(t, k, P));
    } else {
        LL t = 0;
        for (int i = 0; i < n; i += 2)
            t = (t + C(n, i)) % P;
        f[0] = 1;
        for (int i = 1; i <= k; i++) {
            f[i] = (pow_mod(B[i - 1], n, P) + t * f[i - 1] % P) % P;
        }
        printf("%lld\n", f[k]);
    }
}

int main() {
    int T;
    init();

    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}