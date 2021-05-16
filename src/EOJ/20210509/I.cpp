#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

unordered_map<LL, LL> M;

LL n, a, b, c;

LL dfs(LL n) {
    if (n == 0) return 0;
    if (n == 1) return a;

    if (M.count(n))
        return M[n];

    if (n % 2 == 1) {
        return M[n] = min(dfs(n + 1) + c, dfs(n - 1) + a);
    } else if (n % 2 == 0) {
        return M[n] = min(dfs(n / 2) + b, a * n);
    }
}

int main() {

    while (cin >> n >> a >> b >> c) {
        M.clear();
        cout << dfs(n) << endl;
    }
    return 0;
}