#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL P = 998244353;
const int maxn = 100000 + 100;
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
int a[maxn];
LL f[maxn];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int m = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            m += a[i];
        }
        for (int i = 0; i <= m; i++)
            f[i] = 0;

        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= a[i]; j--)
                f[j] = (f[j] + f[j - a[i]]) % (P - 1);
        }

        LL ans = 1;
        for (int i = 1; i <= m; i++)
            if (f[i]) {
                ans = ans * pow_mod(i, f[i], P) % P;
            }
        printf("%lld\n", ans);
    }
    return 0;
}