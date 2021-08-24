/*
    Created by $%U%$ at $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 200000 + 100;

LL ans[maxn];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    memset(ans, 0, sizeof(ans));
    ans[1] = 1;
    LL cur = 1;
    for (int i = 2; i <= n; i++) {
        ans[i] = cur;
        for (int x = 2, y; x <= i; x = y + 1) {
            y = i / (i / x);
            ans[i] += (y - x + 1) * ans[i / x] % m;
            ans[i] %= m;
        }
        cur = (cur + ans[i]) % m;
    }
    printf("%lld\n", ans[n]);
    //main();
    return 0;
}
