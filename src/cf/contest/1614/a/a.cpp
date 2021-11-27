/*
    Created by rdstihz at 2021-11-26 19:17:02
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000;
int a[maxn];

void solve() {
    int n, l, r, k;
    scanf("%d%d%d%d", &n, &l, &r, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(a[i] >= l && a[i] <= r) {
            if(a[i] <= k) {
                ans ++;
                k -= a[i];
            }else break;
        }
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}