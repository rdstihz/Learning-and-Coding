/*
    Created by rdstihz at 2021-07-15 21:49:41
*/

#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

const LL P = 1e9 + 7;
const int maxn = 400000 + 100;

LL a[maxn];

struct mat {
    LL a, b, c, d;

    mat() {
        a = b = c = d = 0;
    }

    mat(LL a, LL b, LL c, LL d) : a(a), b(b), c(c), d(d) {
    }

    mat operator+(const mat& phs) const {
        mat res(0, 0, 0, 0);
        res.a = (a + phs.a) % P;
        res.b = (b + phs.b) % P;
        res.c = (c + phs.c) % P;
        res.d = (d + phs.d) % P;
        return res;
    }
    mat operator*(const mat& phs) const {
        mat res(0, 0, 0, 0);
        res.a = (a * phs.a % P + b * phs.c % P) % P;
        res.b = (a * phs.b % P + b * phs.d % P) % P;
        res.c = (c * phs.a % P + d * phs.c % P) % P;
        res.d = (c * phs.b % P + d * phs.d % P) % P;
        return res;
    }
};

mat E(1, 0, 0, 1);
mat fib(0, 1, 1, 1);

mat mat_pow(mat a, LL b) {
    mat res = E;
    while (b) {
        if (b & 1)
            res = res * a;
        b >>= 1;
        a = a * a;
    }
    return res;
}

struct SegmentTree {
    mat sumv[maxn], mulv[maxn];

    void maintain(int o) {
        sumv[o] = sumv[(o << 1)] + sumv[(o << 1 | 1)];
    }

    void pushdown(int o) {
        sumv[(o << 1)] = sumv[(o << 1)] * mulv[o];
        mulv[(o << 1)] = mulv[(o << 1)] * mulv[o];
        sumv[(o << 1 | 1)] = sumv[(o << 1 | 1)] * mulv[o];
        mulv[(o << 1 | 1)] = mulv[(o << 1 | 1)] * mulv[o];

        mulv[o] = E;
    }

    void build(int o, int L, int R) {
        mulv[o] = E;
        if (L == R) {
            sumv[o] = mat_pow(fib, a[L]);
            return;
        }
        int M = L + R >> 1;
        build((o << 1), L, M);
        build((o << 1 | 1), M + 1, R);
        maintain(o);
    }

    void update(int o, int L, int R, int l, int r, const mat& a) {
        if (l <= L && r >= R) {
            sumv[o] = sumv[o] * a;
            mulv[o] = mulv[o] * a;
            return;
        }
        pushdown(o);
        int M = L + R >> 1;
        if (l <= M) update((o << 1), L, M, l, r, a);
        if (r > M) update((o << 1 | 1), M + 1, R, l, r, a);
        maintain(o);
    }

    mat query(int o, int L, int R, int l, int r) {
        if (l <= L && r >= R) {
            return sumv[o];
        }
        pushdown(o);
        mat res = mat(0, 0, 0, 0);
        int M = L + R >> 1;
        if (l <= M) res = res + query((o << 1), L, M, l, r);
        if (r > M) res = res + query((o << 1 | 1), M + 1, R, l, r);
        return res;
    }

} T;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    T.build(1, 1, n);
    int op, l, r, v;
    while (m--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d%d", &l, &r, &v);
            T.update(1, 1, n, l, r, mat_pow(fib, v));
        } else {
            scanf("%d%d", &l, &r);
            mat res = T.query(1, 1, n, l, r);
            printf("%lld\n", res.c);
        }
    }

    return 0;
}