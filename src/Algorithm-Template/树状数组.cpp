#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 1000000 + 100;

LL C[maxn];

int n;

inline int lowbit(int x) {
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

    int q;
    int v;
    int op;
    int l, r;

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> v;
        add(i, v);
    }

    while (q--) {
        cin >> op >> l >> r;

        if (op == 2) {
            cout << sum(r) - sum(l - 1) << endl;
        } else {
            add(l, r);
        }
    }

    return 0;
}