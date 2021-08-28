#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int a, b, c, d, n;

LL f(int x) {
    int xx = x;
    int g = 0;
    while (xx) {
        g += xx % 10;
        xx /= 10;
    }

    return 1ll * a * x * x * g + 1ll * b * x * x + 1ll * c * x * g * g + 1ll * d * x * g;
}

void solve() {
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);
    LL ans = 1e18;

    for (int i = 1; i <= n; i++) {
        ans = min(ans, f(i));
    }
    printf("%lld\n", ans);
}

int main() {
    freopen("in", "r", stdin);
    freopen("ans", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}