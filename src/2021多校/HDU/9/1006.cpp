#include <bits/stdc++.h>
#define lc (o << 1)
#define rc (o << 1 | 1)
using namespace std;

const int maxn = 200000 + 100;
const int N = 200000;
typedef long long LL;
typedef pair<LL, LL> PII;
LL val[maxn];

PII operator+(const PII& a, const PII& b) {
    return make_pair(a.first + b.first, a.second + b.second + a.first * b.first);
}

struct SegmentTree {
    LL sumv[4 * maxn];
    LL ansv[4 * maxn];

    void maintain(int o) {
        sumv[o] = sumv[lc] + sumv[rc];
        ansv[o] = ansv[lc] + ansv[rc] + sumv[lc] * sumv[rc];
    }

    void build(int o, int L, int R) {
        sumv[o] = ansv[o] = 0;
        if (L == R) {
            val[L] = 0;
            return;
        }
        int M = L + R >> 1;
        build(lc, L, M);
        build(rc, M + 1, R);
    }

    void update(int o, int L, int R, int x, int w) {
        if (L == R) {
            sumv[o] += w;
            val[L] += w;
            return;
        }
        int M = L + R >> 1;
        if (x <= M)
            update(lc, L, M, x, w);
        else
            update(rc, M + 1, R, x, w);
        maintain(o);
    }

    LL query_sum(int o, int L, int R, int l, int r) {
        if (l <= L && r >= R)
            return sumv[o];
        int M = L + R >> 1, res = 0;
        if (l <= M) res += query_sum(lc, L, M, l, r);
        if (r > M) res += query_sum(rc, M + 1, R, l, r);
        return res;
    }

    PII query_ans(int o, int L, int R, int l, int r) {
        if (l <= L && r >= R)
            return make_pair(sumv[o], ansv[o]);
        int M = L + R >> 1;
        PII res = make_pair(0, 0);
        if (l <= M) res = res + query_ans(lc, L, M, l, r);
        if (r > M) res = res + query_ans(rc, M + 1, R, l, r);
        return res;
    }

} T;

void print(LL a, LL b) {
    LL d = __gcd(a, b);
    a /= d, b /= d;
    printf("%lld/%lld\n", a, b);
}

void solve() {
    int n, q;
    scanf("%d%d", &n, &q);
    T.build(1, 1, N);
    int op, x, w;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w);
        T.update(1, 1, N, w, 1);
    }
    while (q--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d", &x, &w);
            T.update(1, 1, N, w, x);
        } else {
            int L = 1, R = N;
            int M;
            LL SL, SR;
            while (L < R) {
                M = L + R >> 1;
                SL = T.query_sum(1, 1, N, 1, M);
                SR = T.query_sum(1, 1, N, M + 1, N);
                if (SL >= SR)
                    R = M;
                else
                    L = M + 1;
            }
            int p = L;
            SL = T.query_sum(1, 1, N, 1, p);
                SR = T.query_sum(1, 1, N, p + 1, N);
            LL delta = SL - SR;
            if (p > 1 && delta > (SR + val[p]) - (SL - val[p])) {
                p--;
            }
            PII A = T.query_ans(1, 1, N, 1, p), B = T.query_ans(1, 1, N, p + 1, N);
            //printf("%d --", p);
            print(A.second + B.second + 2 * A.first * B.first, T.sumv[1] * (T.sumv[1] - 1));
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();

    return 0;
}