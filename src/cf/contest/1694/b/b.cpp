/*
    Created by godlei at 2022-06-16 22:57:26
*/

#include <bits/stdc++.h>

using namespace std;


const int maxn = 200000 + 100;
char s[maxn];

void solve() {
    int n;
    scanf("%d%s", &n, s + 1);

    long long ans = n;
    for(int i = 2; i <= n; i++) {
        if(s[i - 1] != s[i]) ans += i - 1;
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}