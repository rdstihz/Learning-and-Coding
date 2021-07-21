#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 5010;
const LL P = 998244353;
LL dp[maxn][maxn];
int a[maxn], n;
LL inv[maxn];

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
int S[maxn], C[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        inv[i] = pow_mod(i, P - 2, P);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);

    for (int i = n; i >= 0; i--) {
        LL cnt = 0, sum = 0;
        for (int j = n; j >= 0; j--) {

            if (a[i] > a[j]) {
                if (cnt) dp[i][j] = (sum * inv[cnt] + 1) % P;
                C[j]++;
                S[j] = (S[j] + dp[i][j]) % P;
            } else if (a[j] > a[i]) {

                if (C[j]) dp[i][j] = (S[j] * inv[C[j]] + 1) % P;

                cnt++;
                sum = (sum + dp[i][j]) % P;
            }
        }
    }

    LL ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + dp[i][0] + 1) % P;
    ans = ans * inv[n] % P;
    printf("%lld\n", ans);
    return 0;
}