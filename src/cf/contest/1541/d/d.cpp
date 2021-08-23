/*
    Created by rdstihz at 2021-06-26 01:02:47
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 210;
const LL P = 1e9 + 7;

vector<int> G[maxn];

LL f[maxn][maxn];
int n;

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

const LL inv2 = pow_mod(2, P - 2, P);

int dep[maxn], st[maxn][8];

void dfs(int u, int f) {
    dep[u] = dep[f] + 1;
    st[u][0] = f;
    for (int v : G[u])
        if (v != f) {
            dfs(v, u);
        }
}

void init_lca(int r) {
    memset(dep, 0, sizeof(dep));
    memset(st, 0, sizeof(st));
    dfs(r, 0);
    for (int k = 1; k <= 7; k++)
        for (int i = 1; i <= n; i++)
            st[i][k] = st[st[i][k - 1]][k - 1];
}

int LCA(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    int dd = dep[a] - dep[b];
    for (int i = 0; i <= 7; i++)
        if ((dd >> i) & 1)
            a = st[a][i];
    if (a == b) return a;
    for (int i = 7; i >= 0; i--)
        if (st[a][i] != st[b][i]) {
            a = st[a][i];
            b = st[b][i];
        }
    return st[a][0];
}

int main() {
    scanf("%d", &n);
    int a, b;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        f[0][i] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = (f[i - 1][j] + f[i][j - 1]) * inv2 % P;

    LL ans = 0;
    //枚举根
    for (int r = 1; r <= n; r++) {

        //初始化lca
        init_lca(r);

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                int l = LCA(i, j);
                int a = dep[i] - dep[l];
                int b = dep[j] - dep[l];
                ans = (ans + f[a][b]) % P;
            }
        }
    }

    printf("%lld\n", ans * pow_mod(n, P - 2, P) % P);

    return 0;
}