#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL P = 998244353;
const int maxn = 10000 + 100;

LL w[12];
int c[12];
LL dp[2][maxn];
LL pow_mod(LL a, LL b, LL p) {
    LL res = 1;
    while(b) {
        if(b & 1)
            res = res * a % p;
        b >>= 1;
        a = a * a % P;
    }
    return res;
}

int main() {
    int S, T, n, m;
    scanf("%d%d%d%d", &S, &T, &n, &m);
    int d = 0;
    LL invN = pow_mod(10000, P - 2, P);
    for(int i = 1; i <= m; i++) {
        scanf("%d%d", w + i, c + i);
        w[i] = w[i] * invN % P;
        d = __gcd(d, c[i]);
    }
    d = abs(d);
    for(int i = 1; i <= m; i++) {
        c[i] /= d;
    }
    int s = (S - 1) / d + 1;
    int t = s + (T - S - 1) / d + 1;

    //printf("%d %d %d\n", s, t, d);

    dp[0][s] = 1;
    int p = 0;
    LL res = 0;
    for(int i = 1; i <= n; i++) {
        memset(dp[p ^ 1], 0, sizeof(dp[p ^ 1]));
        for(int j = 1; j < t; j++) {
            if(!dp[p][j]) continue;
            for(int k = 1; k <= m; k++) {
                if(j + c[k] <= 0) continue;
                else if(j + c[k] < t) {
                    dp[p ^ 1][j + c[k]] = (dp[p ^ 1][j + c[k]] + dp[p][j] * w[k] % P) % P;
                }else if(j + c[k] >= t) {
                    res = (res + dp[p][j] * w[k] % P) % P;
                }
            }
        }
        p ^= 1;
    }

    printf("%lld\n", res % P);
    return 0;
}