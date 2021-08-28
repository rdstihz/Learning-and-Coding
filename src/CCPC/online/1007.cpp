#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
vector<LL> p[100];
void init() {
    int N = 1000000;
    for (int i = 1; i <= N; i++) {
        int x = i, s = 0;
        while (x) {
            s += x % 10;
            x /= 10;
        }
        p[s].push_back(i);
    }
}

LL A, B, C, D, n, g;

LL f(LL a, LL b, LL x) {
    return 1ll * a * x * x + 1ll * b * x;
}

void solve() {
    scanf("%lld%lld%lld%lld%lld", &A, &B, &C, &D, &n);
    LL ans = LONG_MAX;
    for (g = 1; g <= 60; g++) {
        if (p[g].size() && p[g].front() <= n) {
            LL a = 1ll * A * g + B;
            LL b = 1ll * C * g * g + 1ll * D * g;
            auto st = p[g].begin();
            auto ed = upper_bound(p[g].begin(), p[g].end(), n);

            //f(x) = a * x * x + b * x
            if (a <= 0) {
                LL l = *st;
                LL r = *(ed - 1);
                ans = min(ans, f(a, b, l));
                ans = min(ans, f(a, b, r));
            } else {
                LL t = -b / 2 / a;
                if (t < 1) {
                    ans = min(ans, f(a, b, *st));
                } else if (t > n) {
                    ans = min(ans, f(a, b, *(ed - 1)));
                } else {
                    auto it = lower_bound(st, ed, t);
                    if (it != ed) ans = min(ans, f(a, b, *it));
                    if (it != st) {
                        it--;
                        ans = min(ans, f(a, b, *it));
                    }
                }
            }
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    init();
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}