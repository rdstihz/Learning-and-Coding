/*
    Created by rdstihz at 2022-08-14 00:08:56
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL a[30];
LL x;
int n;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) 
        scanf("%lld", a + i);
    scanf("%lld", &x);


    sort(a, a + n, greater<LL>());

    LL ans = 0;

    for(int S = 0; S < (1 << n); S++) {
        LL t = x;
        for(int i = 0; i < n; i++)
            if(S >> i & 1) t %= a[i];
        t %= a[n - 1];
        ans = max(ans, t);
    }

    printf("%lld\n", ans);
    return 0;
}