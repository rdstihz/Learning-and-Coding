#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5001;
const LL P = 1e9 + 7;
LL g[N][N], f[N], ans;

LL pow_mod(LL a, LL b, LL p) {
    LL res = 1;
    while (b)
        res = res * a % p;
    return res;
}

int main() {
    for (int i = 1; i < N; i++) {
        g[i][1] = 1;
        for (int j = 2; j <= i; j++) {
            g[i][j] = (g[i - 1][j - 1] + 1ll * j * g[i - 1][j]) % P;
        }
    }

    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = (f[i - 1] * i) % P;
    int T, n, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        ans = 0;
        for (int i = 0; i <= min(n, k); i++) {
            ans += ((g[n + 1][i + 1] * g[k + 1][i + 1] % P) * (f[i] * f[i] % P)) % P;
            ans %= P;
        }

        printf("%lld\n", ans);
    }
    return 0;
}
