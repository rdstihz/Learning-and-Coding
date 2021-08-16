#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 100000 + 100;
int f[maxn], p[maxn];
int d[maxn];

void tree2prufer(int n, int* f, int* p) {
    for (int i = 1; i < n; i++)
        d[f[i]]++;
    for (int i = 0, j = 1; i < n - 2 && j <= n; j++) {
        while (d[j])
            j++;
        p[++i] = f[j];
        d[p[i]]--;
        while (i < n - 2 && p[i] < j && !d[p[i]])
            p[++i] = f[p[i]], d[p[i]]--;
    }
}

void prufer2tree(int n, int* f, int* p) {
    p[n - 1] = n;
    for (int i = 1; i < n; i++)
        d[p[i]]++;
    for (int i = 0, j = 1; i < n - 1 && j <= n; j++) {
        while (d[j])
            j++;
        f[j] = p[++i];
        d[p[i]]--;
        while (i < n - 1 && p[i] < j && !d[p[i]]) {
            f[p[i]] = p[i + 1];
            i++;
            d[p[i]]--;
        }
    }
}

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
int n;
vector<int> G[2000];
int dep[2000];
void create(LL S) {
    for (int i = 1; i <= n - 2; i++) {
        p[i] = (S % n) + 1;
        S /= n;
    }
    prufer2tree(n, f, p);

    for (int i = 1; i <= n; i++)
        G[i].clear();
    for (int i = 1; i <= n - 1; i++) {
        G[i].push_back(f[i]);
        G[f[i]].push_back(i);
    }
}

int poi, len;
void dfs(int u, int f) {
    if (dep[u] > len) {
        poi = u;
        len = dep[u];
    }
    for (int v : G[u])
        if (v != f) {
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
}

int main() {

    scanf("%d", &n);

    LL N = pow_mod(n, n - 2, P);
    LL ans = 0;
    for (LL S = 0; S < N; S++) {
        create(S);
        //memset(dep, 0, sizeof(dep));
        poi = 0, len = 0;
        dfs(1, 0);
        
        //memset(dep, 0, sizeof(dep));
        dep[poi] = 0, len = 0;
        dfs(poi, 0);
        
        ans += len;
    }
    printf("%lld\n", ans);

    main();

    return 0;
}