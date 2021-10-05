/*
    Created by rdstihz at 2021-10-05 18:50:16
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int f[12], g[12];

LL dfs(int n, bool a, bool b) { //a当前位进位， b下一位的进位
    if (!n) {
        return a == 0 && b == 0;
    }
    LL res = 0;
    int t = n % 10;
    t -= a;

    if (t == -1) {
        res += f[9] * dfs(n / 10, b, 1);
    } else {
        res += f[t] * dfs(n / 10, b, 0) + g[t] * dfs(n / 10, b, 1);
    }
    return res;
}

void solve() {
    int n;
    scanf("%d", &n);

    LL res = dfs(n, 0, 0);

    printf("%lld\n", res - 2);
}

int main() {
    int T;

    for (int i = 0; i <= 9; i++) {
        f[i] = i + 1;
        g[i] = 9 - i;
    }
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}