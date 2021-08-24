/*
    Created by $%U%$ at $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 200000 + 10;
bool f[maxn];
int n, a, b;
void proc(int t) {
    int t1 = n - t;
    // int minv = abs(a - t);
    // int maxv = n;
    // if (a > t) n -= a - t;
    // if (b > t) n -= b - t;
    // for (int i = minv; i <= maxv; i += 2)
    //     f[i] = true;

    int minv = 0;
    if (a > t) minv += a - t;
    if (b > t1) minv += b - t1;
    int maxv = n;
    if (a > t1) maxv -= a - t1;
    if (b > t) maxv -= b - t;
    for (int i = minv; i <= maxv; i += 2)
        f[i] = true;
}

void solve() {
    scanf("%d%d", &a, &b);
    n = a + b;
    for (int i = 0; i <= n; i++)
        f[i] = 0;

    if (n % 2 == 0)
        proc(n / 2);
    else
        proc(n / 2), proc(n - n / 2);

    int ans = 0;
    for (int i = 0; i <= n; i++)
        if (f[i])
            ans++;
    printf("%d\n", ans);
    for (int i = 0; i <= n; i++)
        if (f[i])
            printf("%d ", i);
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}