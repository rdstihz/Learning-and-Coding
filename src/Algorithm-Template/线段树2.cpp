#include <iostream>
#include <cstring>

#define lc (o<<1)
#define rc (o<<1|1)


using namespace std;

typedef long long LL;
const int maxn = 400000 + 100;

LL v[maxn];

struct SegmentTree {
    LL sumv[maxn], addv[maxn], mulv[maxn];

    void maintain(int o) {
        sumv[o] = sumv[lc] + sumv[rc];
    }

    void pushdown(int o, int L, int R) {
        int M = L + R >> 1;

        //锟饺乘猴拷锟�
        if (mulv[o] != 1) {
            mulv[lc] *= mulv[o];
            addv[lc] *= mulv[o];
            sumv[lc] *= mulv[o];

            mulv[rc] *= mulv[o];
            addv[rc] *= mulv[o];
            sumv[rc] *= mulv[o];

            mulv[o] = 1;
        }

        if (addv[o]) {
            addv[lc] += addv[o];
            sumv[lc] += addv[o] * (M - L + 1);

            addv[rc] += addv[o];
            sumv[rc] += addv[o] * (R - M);

            addv[o] = 0;
        }

    }

    void build(int o, int L, int R) {
        addv[o] = 0;
        mulv[o] = 1;
        if (L == R) {
            sumv[o] = v[L];
            return;
        }

        int M = L + R >> 1;
        build(lc, L, M);
        build(rc, M + 1, R);
        maintain(o);
    }

    LL query(int o, int L, int R, int l, int r) {
        if (l <= L && r >= R) return sumv[o];
        pushdown(o, L, R);
        int M = L + R >> 1;
        LL sum = 0;
        if (l <= M) sum += query(lc, L, M, l, r);
        if (r > M) sum += query(rc, M + 1, R, l, r);
        return sum;
    }

    void update_add(int o, int L, int R, int l, int r, int x) {
        if (l <= L && r >= R) {
            addv[o] += x;
            sumv[o] += x * (R - L + 1);
            return;
        }
        pushdown(o, L, R);
        int M = L + R >> 1;
        if (l <= M) update_add(lc, L, M, l, r, x);
        if (r > M) update_add(rc, M + 1, R, l, r, x);
        maintain(o);
    }

    void update_mul(int o, int L, int R, int l, int r, int x) {
        if (l <= L && r >= R) {
            mulv[o] *= x;
            addv[o] *= x;
            sumv[o] *= x;
            return;
        }
        pushdown(o, L, R);
        int M = L + R >> 1;
        if (l <= M) update_mul(lc, L, M, l, r, x);
        if (r > M) update_mul(rc, M + 1, R, l, r, x);
        maintain(o);
    }


} T;

int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> v[i];
    int op, l, r, x;
    T.build(1, 1, n);
    while (m--) {
        cin >> op;
        if (op == 1) { //锟斤拷锟�
            cin >> l >> r;
            cout << T.query(1, 1, n, l, r) << endl;
        } else if (op == 2) { //锟斤拷锟斤拷锟�
            cin >> l >> r >> x;
            T.update_add(1, 1, n, l, r, x);
        } else if (op == 3) { //锟斤拷锟斤拷锟�
            cin >> l >> r >> x;
            T.update_mul(1, 1, n, l, r, x);
        } else { //锟斤拷锟斤拷
            for (int i = 1; i <= n; i++)
                cout << T.query(1, 1, n, i, i) << " ";
            cout << endl;
        }

    }


    return 0;
}
