/*
    Created by rdstihz at 2021-08-18 15:03:18
*/

#include <bits/stdc++.h>
#define lc (o << 1)
#define rc (o << 1 | 1)

using namespace std;
typedef long long LL;
const int maxn = 200000 + 100;
LL a[maxn], b[maxn];

struct SegmentTree {
    LL gcdv[4 * maxn];

    void maintain(int o) {
        gcdv[o] = __gcd(gcdv[lc], gcdv[rc]);
    }

    void build(int o, int L, int R) {
        if (L == R) {
            gcdv[o] = b[L];
            return;
        }
        int M = L + R >> 1;
        build(lc, L, M);
        build(rc, M + 1, R);
        maintain(o);
    }

    LL query(int o, int L, int R, int l, int r) {
        if (l <= L && r >= R) {
            return gcdv[o];
        }
        int M = L + R >> 1;
        LL res = 0;
        if (l <= M) res = __gcd(res, query(lc, L, M, l, r));
        if (r > M) res = __gcd(res, query(rc, M + 1, R, l, r));
        return res;
    }

} T;

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    for (int i = 1; i < n; i++)
        b[i] = abs(a[i + 1] - a[i]);
    if (n == 1) {
        printf("1\n");
        return;
    }
    n--;
    T.build(1, 1, n);
    
    int ans = 0;
    int j = 0;
    for (int i = 1; i <= n && j < n; i++) {
        j = max(j, i - 1);
        while (j < n && T.query(1, 1, n, i, j + 1) >= 2)
            j++;
        ans = max(ans, j - i + 1);
    }
    printf("%d\n", ans + 1);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}