/*
    Created by rdstihz at 2022-08-14 01:02:17
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
LL p[maxn];

int main() {
    LL n, m, x, y;
    scanf("%lld%lld%lld%lld", &n, &m, &x, &y);
    for(int i = 1; i <= m; i++)
        scanf("%lld", p + i);
    p[0] = 0, p[m + 1] = n + 1;
    LL ans = 0, last = 0;
    for(int i = 1; i <= m + 1; i++) {
        LL l = p[i] - p[i - 1] - 1;
        LL a = min(x, y - last);

        LL t = l / (y + 2);
        ans += 2 * t;
        l -= (y + 2) * t;

        if(l <= a) {
            last = l;
            continue;
        }
        l -= a + 1;
        last = l;
        ans++;

    }
    printf("%lld\n", ans);
    return 0;
}