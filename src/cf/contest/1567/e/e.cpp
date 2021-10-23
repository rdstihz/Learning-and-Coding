/*
    Created by rdstihz at 2021-10-15 15:17:56
*/

#include <bits/stdc++.h>
#define lc (o << 1)
#define rc (o << 1 | 1)

using namespace std;
typedef long long LL;
const int maxn = 800000 + 100;
int a[maxn];

struct SegmentTree {
    LL ans[maxn];
    int lv[maxn], rv[maxn];

    void maintain(int o, int L, int R) {
        int M = L + R >> 1;
        ans[o] = ans[lc] + ans[rc];
        if (a[M] <= a[M + 1])
            ans[o] += 1ll * rv[lc] * lv[rc];

        lv[o] = lv[lc];
        if (lv[lc] == M - L + 1 && a[M] <= a[M + 1])
            lv[o] += lv[rc];
        rv[o] = rv[rc];
        if (rv[rc] == R - M && a[M] <= a[M + 1])
            rv[o] += rv[lc];
    }

    void build(int o, int L, int R) {
        if (L == R) {
            ans[o] = lv[o] = rv[o] = 1;
            return;
        }
        int M = L + R >> 1;
        build(lc, L, M);
        build(rc, M + 1, R);
        maintain(o, L, R);
    }

    LL query(int o, int L, int R, int l, int r) {
        if (l <= L && r >= R) {
            return ans[o];
        }
        LL ans = 0;
        int M = L + R >> 1;
        if (l <= M) ans += query(lc, L, M, l, r);
        if (r > M) ans += query(rc, M + 1, R, l, r);
        if (l <= M && r > M && a[M] <= a[M + 1]) {
            int t1 = min(rv[lc], M - l + 1);
            int t2 = min(lv[rc], r - M);
            ans += 1ll * t1 * t2;
        }
        return ans;
    }

    void update(int o, int L, int R, int p, int v) {
        if (L == R) {
            a[L] = v;
            return;
        }
        int M = L + R >> 1;
        if (p <= M)
            update(lc, L, M, p, v);
        else
            update(rc, M + 1, R, p, v);
        maintain(o, L, R);
    }

} T;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    T.build(1, 1, n);
    while (m--) {
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);
        if (op == 2) {
            printf("%lld\n", T.query(1, 1, n, a, b));
        } else {
            T.update(1, 1, n, a, b);
        }
    }

    return 0;
}