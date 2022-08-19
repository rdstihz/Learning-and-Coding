/*
    Created by rdstihz at 2022-08-18 21:43:07
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;
int a[maxn];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    sort(a + 1, a + 1 + n);
    printf("%d\n", a[n] + a[n - 1] - a[1] - a[2]);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}