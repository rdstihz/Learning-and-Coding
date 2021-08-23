/*
    Created by rdstihz at 2021-08-15 23:59:05
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL P = 998244353;
const int maxn = 60;
const int maxm = 100000 + 10;
int l[maxn], r[maxn];
int ll[maxn], rr[maxn];
int n, m;

bool flag[maxm];
int primes[maxm], mu[maxm];
int tot;
void init(int N) {
    mu[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!flag[i]) {
            primes[++tot] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= tot && i * primes[j] <= N; j++) {
            flag[i * primes[j]] = 1;
            mu[i * primes[j]] = -mu[i];
            if (i % primes[j] == 0) {
                mu[i * primes[j]] = 0;
                break;
            }
        }
    }
}

LL f[maxn][maxm];
LL dp(int k) {
    for (int i = 1; i <= n; i++) {
        ll[i] = (l[i] + k - 1) / k;
        rr[i] = r[i] / k;
        if (ll[i] > rr[i])
            return 0;
    }

    int mm = m / k;
    for (int j = 0; j <= mm; j++)
        f[0][j] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= mm; j++) {
            if (j < ll[i])
                f[i][j] = 0;
            else if (j <= rr[i])
                f[i][j] = f[i - 1][j - ll[i]];
            else
                f[i][j] = (f[i - 1][j - ll[i]] - f[i - 1][j - rr[i] - 1] + P) % P;
            if (j > 0) f[i][j] = (f[i][j] + f[i][j - 1]) % P;
        }
    }
    assert(f[n][mm] >= 0);
    return f[n][mm];
}

int main() {

    scanf("%d%d", &n, &m);
    init(m);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", l + i, r + i);
    }

    LL ans = 0;
    for (int d = 1; d <= m; d++)
        ans = (ans + dp(d) * mu[d] % P + P) % P;

    printf("%lld\n", ans);
    return 0;
}

/*
25 10000
4 9998
4 9999
4 9998
10 10000
4 9994
4 9997
3 9994
1 9994
5 10000
3 9996
10 10000
8 9999
10 10000
9 9999
10 10000
3 9998
8 9999
8 9999
7 10000
4 9998
2 9995
6 9996
5 9995
7 9997
10 10000


517149743
*/