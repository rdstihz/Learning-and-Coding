/*
    Created by rdstihz at 2021-08-26 23:24:40
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 20000 + 100;
char s[maxn];

void solve() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    int pos = 1;
    while (pos <= n && s[pos] == '1')
        pos++;

    if (pos > n) {
        int l = n / 2;
        printf("%d %d %d %d\n", 1, l, n - l + 1, n);
    } else if (pos <= n / 2) {
        printf("%d %d %d %d\n", pos, n, pos + 1, n);
    } else {
        printf("%d %d %d %d\n", 1, pos, 1, pos - 1);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}