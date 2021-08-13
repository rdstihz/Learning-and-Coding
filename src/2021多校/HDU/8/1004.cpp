#include <bits/stdc++.h>
#define lc (o << 1)
#define rc (o << 1 | 1)
using namespace std;
typedef long long LL;
const int maxn = 400000 + 100;
const LL P = 998244353;
LL lowbit(LL x) {
    return x & -x;
}

LL a[100000 + 10], b[100000 + 10];

struct SegmentTree {
    LL sumv1[maxn], sumv2[maxn]; //低位、最高位
    LL mulv[maxn];
    bool tag[maxn];
    void maintain(int o) {
        sumv1[o] = (sumv1[lc] + sumv1[rc]) % P;
        sumv2[o] = (sumv2[lc] + sumv2[rc]) % P;
        tag[o] = tag[lc] & tag[rc];
    }

    void pushdown(int o, int L, int R) {
        if (mulv[o] != 1) {
            mulv[lc] = mulv[lc] * mulv[o] % P;
            sumv2[lc] = sumv2[lc] * mulv[o] % P;
            mulv[rc] = mulv[rc] * mulv[o] % P;
            sumv2[rc] = sumv2[rc] * mulv[o] % P;

            mulv[o] = 1;
        }
    }

    void build(int o, int L, int R) {
        sumv1[o] = sumv2[o] = 0;
        mulv[o] = 1;
        tag[o] = false;
        if (L == R) {
            sumv1[o] = a[L], sumv2[o] = b[L] % P;
            return;
        }
        int M = L + R >> 1;
        build(lc, L, M);
        build(rc, M + 1, R);
        maintain(o);
    }

    void add(LL& a, LL b) {
        a = (a + b) % P;
    }

    LL query(int o, int L, int R, int l, int r) {
        if (l <= L && r >= R) {
            return (sumv1[o] + sumv2[o]) % P;
        }
        pushdown(o, L, R);
        LL res = 0;
        int M = L + R >> 1;
        if (l <= M) add(res, query(lc, L, M, l, r));
        if (r > M) add(res, query(rc, M + 1, R, l, r));
        return res;
    }

    void update1(int o, int L, int R, int l, int r) {
        if (tag[o]) return;
        if (L == R) {
            if (sumv1[o])
                sumv1[o] -= lowbit(sumv1[o]);
            else
                tag[o] = true, sumv2[o] = 0;
            return;
        }
        pushdown(o, L, R);
        int M = L + R >> 1;
        if (l <= M) update1(lc, L, M, l, r);
        if (r > M) update1(rc, M + 1, R, l, r);
        maintain(o);
    }

    void update2(int o, int L, int R, int l, int r) {
        if (l <= L && r >= R) {
            mulv[o] = mulv[o] * 2 % P;
            sumv2[o] = sumv2[o] * 2 % P;
            return;
        }
        pushdown(o, L, R);
        int M = L + R >> 1;
        if (l <= M) update2(lc, L, M, l, r);
        if (r > M) update2(rc, M + 1, R, l, r);
        maintain(o);
    }

} T;

void solve() {
    int n;
    LL x;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &x);
        b[i] = 1;
        while (b[i] << 1 <= x)
            b[i] <<= 1;
        a[i] = x - b[i];
    }

    // for(int i = 1; i <= n; i++)
    //     printf("%lld%c", a[i], i == n ? '\n' : ' ');
    // for(int i = 1; i <= n; i++)
    //     printf("%lld%c", b[i], i == n ? '\n' : ' ');

    T.build(1, 1, n);
    int q;
    scanf("%d", &q);
    int op, l, r;
    while (q--) {
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1) {
            printf("%lld\n", T.query(1, 1, n, l, r));
        } else if (op == 2) {
            T.update1(1, 1, n, l, r);
        } else {
            T.update2(1, 1, n, l, r);
        }
    }
}

int main() {
    //freopen("../src/2021多校/HDU/HDU8/data/1004/data.in", "r", stdin);
    //freopen("../src/2021多校/HDU/HDU8/data/1004/data.ans", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}