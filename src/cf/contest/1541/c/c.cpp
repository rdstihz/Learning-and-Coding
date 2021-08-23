/*
    Created by rdstihz at 2021-06-26 00:24:32
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;

LL d[maxn], S[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", d + i);

        sort(d + 2, d + 1 + n);

        for (int i = 1; i <= n; i++)
            S[i] = S[i - 1] + d[i];
        LL ans = d[n];
        for (int i = 2; i <= n; i++) {
            ans += S[i - 1] - (i - 1) * d[i];
        }

        printf("%lld\n", ans);
    }

    return 0;
}