#include <bits/stdc++.h>

using namespace std;

const int maxn = 150000 + 100;

int p[maxn];

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int n, k;

bool judge(int op, int a, int b) {
    if (a > n || b > n)
        return true;

    if (op == 1) { //同类
        if (find(b) == find(a + n) || find(b) == find(a + 2 * n))
            return true;
        p[find(b)] = find(a);
        p[find(b + n)] = find(a + n);
        p[find(b + 2 * n)] = find(a + 2 * n);
    } else if (op == 2) { // a 吃 b
        if (find(b) == find(a) || find(b) == find(a + n))
            return true;
        p[find(b)] = find(a + 2 * n);
        p[find(b + n)] = find(a);
        p[find(b + 2 * n)] = find(a + n);
    }
    return false;
}

int main() {

    cin >> n >> k;

    for (int i = 1; i <= 3 * n; i++) {
        p[i] = i;
    }

    int op, a, b;
    int cnt = 0;

    while (k--) {
        cin >> op >> a >> b;
        if (judge(op, a, b))
            cnt++;
    }
    cout << cnt << endl;

    return 0;
}