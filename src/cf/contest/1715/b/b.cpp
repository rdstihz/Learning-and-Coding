/*
    Created by rdstihz at 2022-08-20 22:41:29
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 200000 + 100;
LL a[maxn];

void solve() {
    int n;
    LL k, b;
    LL s;
    scanf("%d%lld%lld%lld", &n, &k, &b, &s);
    
    if(s < k * b || s > k * b + (k - 1) * n) {
        printf("-1\n");
        return;
    }

    a[1] = k * b;
    s -= k *  b;
    for(int i = 1; i <= n; i++) {
        LL t = min(s, k - 1);
        a[i] += t;
        s -= t;

        printf("%lld ", a[i]);
        a[i] = 0;
    }
    
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}