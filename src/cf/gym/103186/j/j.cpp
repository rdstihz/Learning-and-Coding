/*
    Created by rdstihz at 2021-07-15 23:23:28
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 100000 + 100;
LL a[maxn];
int n;

int main() {

    scanf("%d", &n);
    LL S = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        S += a[i];
    }
    if (S < 0)
        sort(a + 1, a + 1 + n);
    else
        sort(a + 1, a + 1 + n, greater<LL>());

    LL A = 0;
    for (int i = 1; i <= n; i += 2)
        A += a[i];

    printf("%lld\n", abs(A) - abs(S - A));
    return 0;
}