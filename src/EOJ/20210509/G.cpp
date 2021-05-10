#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;
const int maxn = 5003;
const LL P = 998244353;

int to[maxn * 2], nxt[maxn * 2], fir[maxn];
int tot;

LL dp[maxn][maxn];

void add(int a, int b) {
    tot++;
    to[tot] = b, nxt[tot] = fir[a], fir[a] = tot;
}

int dfs(int u, int f) {

    int sz = 1;

    dp[u][1] = 1;

    for (int e = fir[u]; e; e = nxt[e]) {
        int v = to[e];

        if (v == f) continue;

        int t = dfs(v, u);

        for (int j = sz + t; j >= 1; j--) {
            //dp[u][j] = 0;
            for (int k = max(1, j - sz); k <= t && k < j; k++) {
                dp[u][j] += dp[u][j - k] * dp[v][k] % P;
                dp[u][j] %= P;
            }
        }

        sz += t;
    }

    return sz;
}

LL pow_mod(LL a, LL b, LL p) {
    LL res = 1;
    while (b) {
        if (b & 1)
            res = res * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;

    while (~scanf("%d", &n)) {

        memset(fir, 0, sizeof(fir));
        tot = 0;
        int t;
        for (int i = 2; i <= n; i++) {
            scanf("%d", &t);
            add(t, i);
            add(i, t);
        }

        memset(dp, 0, sizeof(dp));

        dfs(1, -1);

        LL a = 0, b = 0;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                a += j * dp[i][j] % P;
                a %= P;

                b += dp[i][j];
                b %= P;
            }
        printf("%lld\n", a * pow_mod(b, P - 2, P) % P);
    }

    return 0;
}