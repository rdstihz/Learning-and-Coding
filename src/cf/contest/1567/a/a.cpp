/*
    Created by rdstihz at 2021-10-05 18:35:57
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;
char s[maxn];

void solve() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'U' || s[i] == 'D') {
            putchar('U' + 'D' - s[i]);
        } else {
            putchar('L');
            putchar('R');
            i++;
        }
    }
    puts("");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}