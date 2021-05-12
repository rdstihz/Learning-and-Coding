#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000000 + 100;

typedef long long LL;

//delta[i] 表示 a[i], a[i + 1] .... a[n]  都要加上一个数delta[i]
//树状数组 C1用于维护delta[i], 树状数组C2维护 i * delta[i]
//前缀和 sum[i] = (i + 1) sum_delta[i] - sum_i*delta[i] 



LL C1[maxn], C2[maxn];
int n;

int lowbit(int x) {
    return x & -x;
}

void add(int pos, LL v) {

    for (int i = pos; i <= n; i += lowbit(i)) {
        C1[i] += v;
    }

    for (int i = pos; i <= n; i += lowbit(i)) {
        C2[i] += v * pos;
    }
}

LL sum(int pos) {
    LL res = 0;

    for (int i = pos; i; i -= lowbit(i)) {
        res += (pos + 1) * C1[i];
    }

    for (int i = pos; i; i -= lowbit(i)) {
        res -= C2[i];
    }

    return res;
}

int main() {
    int q;
    cin >> n >> q;

    int op, l, r;
    LL v;

    for (int i = 1; i <= n; i++) {
        cin >> v;
        add(i, v);
        add(i + 1, -v);
    }

    while(q--) {
        cin >> op;
        if(op == 1) {
            cin >> l >> r >> v;
            add(l, v);
            add(r + 1, -v);
        }
        else if(op == 2) {
            cin >> l >> r;
            cout << sum(r) - sum(l - 1) << endl;
        }
    }
    return 0;
}