/*
    Created by godlei at 2021-12-01 23:02:50
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 200;
typedef long long LL;
LL a[maxn];
LL h;
int n;
LL calc(LL k) {
    LL last = 0;
    LL res = 0;
    for(int i = 1; i <= n; i++) {
        res += a[i] + k - max(a[i], last);
        last = a[i] + k;
    }
    return res;
}

void solve() {
    scanf("%d%lld", &n, &h);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
    }
    LL L = 0, R = 1e18 + 1;
    LL M;
    while(L < R) {
        M = L + R >> 1;
        if(calc(M) >= h)
            R = M;
        else 
            L = M + 1;
    }

    printf("%lld\n", L);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}