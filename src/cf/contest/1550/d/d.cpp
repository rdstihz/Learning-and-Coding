/*
    Created by rdstihz at 2021-07-14 23:43:36
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 200000 + 100;
const LL P = 1e9 + 7;
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

LL prod[maxn], aprod[maxn];

void init() {
    int N = 200000;
    prod[0] = 1;
    for (int i = 1; i <= N; i++)
        prod[i] = prod[i - 1] * i % P;
    aprod[N] = pow_mod(prod[N], P - 2, P);
    for (int i = N - 1; i >= 0; i--)
        aprod[i] = aprod[i + 1] * (i + 1) % P;
}

LL C(int n, int m) {
    if (n < m) return 0;
    return (prod[n] * aprod[m] % P) * aprod[n - m] % P;
}

int main() {
    int T;
    init();
    scanf("%d", &T);
    while (T--) {
        int n, l, r;
        scanf("%d%d%d", &n, &l, &r);
        LL ans = 0;

        int t = min(1 - l, r - n);
        t = max(t, 0);
        if (t > 0){
            int ll = 0;
            int rr = n + 1;
            if (ll >= rr) break;

            int n1 = ll, n2 = rr - ll - 1;

            //printf("aa%d %d %d\n", k, n1, n2);

            if (n1 > (n + 1) / 2) break;
            if (n1 + n2 < n / 2) break;

            if (n % 2 == 0) {
                ans += C(n2, n / 2 - n1);
                ans %= P;
            } else {
                ans += C(n2, n / 2 - n1);
                ans += C(n2, n / 2 + 1 - n1);
                ans %= P;
            }
            ans = ans * t % P;
        }
        for (int k = t + 1; k <= r; k++) {
            int ll = max(0, l + k - 1);
            int rr = min(n + 1, r - k + 1);
            if (ll >= rr) break;

            int n1 = ll, n2 = rr - ll - 1;

            //printf("aa%d %d %d\n", k, n1, n2);

            if (n1 > (n + 1) / 2) break;
            if (n1 + n2 < n / 2) break;

            if (n % 2 == 0) {
                ans += C(n2, n / 2 - n1);
                ans %= P;
            } else {
                ans += C(n2, n / 2 - n1);
                ans += C(n2, n / 2 + 1 - n1);
                ans %= P;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}