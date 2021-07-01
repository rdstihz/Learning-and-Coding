#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000;

int a[maxn];

int dfn;

void dfs(int o, int l, int r) {
    dfn++;
    if (l == r) return;
    if (a[r] - a[l - 1] <= 1) return;
    int m = l + r >> 1;
    dfs(o << 1, l, m);
    dfs(o << 1 | 1, m + 1, r);
}

int main() {
    int n, k;
    cin >> n >> k;
    int v;
    for (int i = 1; i <= k; i++) {
        cin >> v;
        a[v]++;
    }

    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];

    dfn = 0;
    dfs(1, 1, n);
    cout << dfn << endl;

    return 0;
}