#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
const LL P = 1e9 + 9;

LL prod[maxn], aprod[maxn];
LL f[maxn];

LL pow_mod(LL a, LL b, LL p) {
    LL res = 1;
    while (b) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res % P;
}

int T(int x, int y, int n) {
    if (n % 2 || x != y)
        return n;
    else
        return n / 2;
}

void init() {
    int N = 100000;
    //预处理阶乘和逆元
    prod[0] = aprod[0] = 1;
    for (int i = 1; i <= N; i++) {
        prod[i] = prod[i - 1] * i % P;
        aprod[i] = pow_mod(prod[i], P - 2, P);
    }

    f[1] = 1;
    for (int i = 2; i <= N; i++)
        f[i] = pow_mod(i, i - 2, P);
}

int p[maxn];
bool vis[maxn];
int l[maxn];

int dfs(int u) {
    vis[u] = 1;
    if (vis[p[u]])
        return 1;
    else
        return dfs(p[u]) + 1;
}

int main() {
    int T;

    init();

    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", p + i);

        int k = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++)
            if (!vis[i]) {
                l[++k] = dfs(i);
            }

        LL ans = 1;
        for (int i = 1; i <= k; i++) {
            ans = ans * f[l[i]] % P;
            ans = ans * aprod[l[i] - 1] % P;
        }
        ans = ans * prod[n - k] % P;
        printf("%lld\n", ans);
    }

    return 0;
}