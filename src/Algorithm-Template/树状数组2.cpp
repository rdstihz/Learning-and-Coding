#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 1000000 + 100;

LL a[maxn], C[maxn];
int n, q;

int lowbit(int x) {
    return x & -x;
}

LL sum(int x) {
    LL res = 0;
    for (; x; x -= lowbit(x))
        res += C[x];

    return res;
}

void add(int x, LL v) {
    for (; x <= n; x += lowbit(x))
        C[x] += v;
}

int main() {
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--) {
        a[i] -= a[i - 1];
        add(i, a[i]);
    }

    int op, l, r, v;

    for (int i = 1; i <= q; i++) {
        cin >> op;

        if (op == 1) {
            cin >> l >> r >> v;
            add(l, v);
            add(r + 1, -v);
        }

        if (op == 2) {
            cin >> v;
            cout << sum(v) << endl;
        }
    }

    return 0;
}