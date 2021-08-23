/*
    Created by rdstihz at 2021-08-16 21:40:11
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 100000 + 100;
int a[maxn];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    sort(a + 1, a + 1 + n);
    double s = 0;
    for (int i = 1; i < n; i++)
        s += a[i];
    printf("%.9f\n", s / (n - 1) + a[n]);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}