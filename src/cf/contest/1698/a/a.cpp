/*
    Created by godlei at 2022-06-28 22:36:33
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;
int a[maxn];

void solve() {
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }

    printf("%d\n", a[1]);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}