/*
    Created by rdstihz at 2021-11-26 19:21:25
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;
pair<int, int> a[maxn];
int ans[maxn];
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }

    sort(a + 1, a + 1 + n, greater<pair<int, int> >());

    
    int cur = 0;
    for(int i = 0; i <= n; i += 2)
        ans[a[i].second] = cur++;
    cur = -1;
    for(int i = 1; i <= n; i += 2)
        ans[a[i].second] = cur--;
    long long res = 0;
    for(int i = 0; i <= n; i++)
        res += 2ll * a[i].first * abs(ans[a[i].second]);
    printf("%lld\n", res);
    for(int i = 0; i <= n; i++)
        printf("%d%c", ans[i], i == n ? '\n': ' ');

}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}