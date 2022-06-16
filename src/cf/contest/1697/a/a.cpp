/*
    Created by rdstihz at 2022-06-12 22:36:46
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000;
int a[maxn];

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        if(m < a[i]) {
            ans += a[i] - m;
            m = 0;
        }else {
            m -= a[i];
        }
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