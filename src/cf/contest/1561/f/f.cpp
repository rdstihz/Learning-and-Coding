/*
    Created by rdstihz at 2021-08-25 20:18:42
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long LL;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const LL P = 998244353;
const int maxn = 200000 + 1000;
LL frac[maxn * 2], afrac[maxn * 2];
int x[maxn], y[maxn];
bool vis[maxn];
ordered_set S;
vector<int> del, mark;

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

void init() {
    int N = 400100;
    frac[0] = 1;
    for (int i = 1; i <= N; i++)
        frac[i] = frac[i - 1] * i % P;
    afrac[N] = pow_mod(frac[N], P - 2, P);
    for (int i = N - 1; i >= 0; i--)
        afrac[i] = afrac[i + 1] * (i + 1) % P;

    N = 200000 + 10;
    //建平衡树
    for (int i = 1; i <= N; i++)
        S.insert(i);
}

LL C(int n, int m) {
    return frac[n] * afrac[m] % P * afrac[n - m] % P;
}

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d", x + i, y + i);
    int c = 0;
    for (int i = m; i >= 1; i--) {
        auto p = S.find_by_order(y[i]);
        auto q = next(p);
        if (!vis[*q]) {
            c++;
            vis[*q] = true;
        }
        del.push_back(*p);
        mark.push_back(*q);
        S.erase(p);
    }
    printf("%lld\n", C(2 * n - c - 1, n));
    for (int v : del)
        S.insert(v);
    for (int v : mark)
        vis[v] = false;
    del.clear();
    mark.clear();
}

int main() {
    int T;
    init();
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}