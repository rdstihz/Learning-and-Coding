/*
    Created by rdstihz at 2021-11-05 14:22:02
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000;
char s[maxn];

void solve() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    int ans = 0;
    for (int i = 1; i < n; i++)
        if (s[i] != '0')
            ans += s[i] - '0' + 1;
    ans += s[n] - '0';
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}