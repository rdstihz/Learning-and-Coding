/*
    Created by rdstihz at 2021-06-20 18:10:21
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long n, x, t;
        scanf("%lld%lld%lld", &n, &x, &t);
        long long k = t / x;

        if (n <= k) {
            long long ans = (0 + n - 1) * n / 2;
            printf("%lld\n", ans);
        } else {
            long long ans = (0 + k - 1) * k / 2;
            n -= k;
            ans += n * k;
            printf("%lld\n", ans);
        }
    }
    return 0;
}