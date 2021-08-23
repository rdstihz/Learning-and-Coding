/*
    Created by rdstihz at 2021-08-15 22:35:46
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int ans = (1 << 31) - 1;
    int n;
    scanf("%d", &n);
    int v;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &v);
        ans &= v;
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