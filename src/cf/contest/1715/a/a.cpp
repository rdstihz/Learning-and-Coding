/*
    Created by rdstihz at 2022-08-20 22:37:56
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    int ans = n - 1 + m - 1 + min(n, m);
    if(n == 1 && m == 1) ans--;
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}