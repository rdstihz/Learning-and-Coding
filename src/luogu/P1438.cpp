#include <iostream>

#define lc (o << 1)
#define rc (o << 1 | 1)

using namespace std;

const int maxn = 400000 + 100;

int a[maxn / 4];

struct SegmentTree {
    int sumv[maxn], addv[maxn];

    void maintain(int o) {
        sumv[o] = sumv[lc] + sumv[rc];
    }

    void pushdown(int o, int L, int R) {
        if (addv[o]) {
            int M = L + R >> 1;
            addv[lc] += addv[o], sumv[lc] += (M - L + 1) * addv[o];
            addv[rc] += addv[o], sumv[rc] += (R - M) * addv[o];
            addv[o] = 0;
        }
    }

    void build(int o, int L, int R) {
        if (L == R) {
            sumv[o] = a[L];
            return;
        }
        int M = L + R >> 1;
        build(lc, L, M);
        build(rc, M + 1, R);
        maintain(o);
    }

    void update(int o, int L, int R, int l, int r, int v) {
        if (l <= L && r >= R) {
            sumv[o] += v * (R - L + 1);
            addv[o] += v;
            return;
        }

        pushdown(o, L, R);
        int M = L + R >> 1;
        if (l <= M) update(lc, L, M, l, r, v);
        if (r > M) update(rc, M + 1, R, l, r, v);
        maintain(o);
    }

    int query(int o, int L, int R, int l, int r) {
        if (l <= L && r >= R) {
            return sumv[o];
        }
        pushdown(o, L, R);
        int res = 0;
        int M = L + R >> 1;
        if (l <= M) res += query(lc, L, M, l, r);
        if (r > M) res += query(rc, M + 1, R, l, r);
        return res;
    }
} T;

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--)
        a[i] -= a[i - 1];

    T.build(1, 1, n);

    int op, l, r, k, d;

    while (m--) {
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> k >> d;

            T.update(1, 1, n, l, l, k - d);
            T.update(1, 1, n, l, r, d);

            if (r < n) {
                T.update(1, 1, n, r + 1, r + 1, -k - (r - l) * d);
            }
        }else{
            cin >> l;
            cout << T.query(1, 1, n, 1, l) << endl;
        }
    }

    return 0;
}