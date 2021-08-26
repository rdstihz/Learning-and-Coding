/*
    Created by rdstihz at 2021-08-26 23:24:45
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 300000 + 100;
char s[maxn];
int a[maxn];
void solve() {
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
        a[i] = s[i] == '+' ? 1 : -1;
    for (int i = 2; i <= n; i += 2)
        a[i] = -a[i];
    for (int i = 2; i <= n; i++)
        a[i] += a[i - 1];
    int l, r;
    while (q--) {
        scanf("%d%d", &l, &r);
        if (a[r] - a[l - 1] == 0)
            puts("0");
        else {
            int len = r - l + 1;
            puts(len % 2 ? "1" : "2");
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}