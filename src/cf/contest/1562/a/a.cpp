/*
    Created by rdstihz at 2021-08-26 22:35:25
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l, r;
    scanf("%d%d", &l, &r);
    int m = max(r / 2 + 1, l);
    printf("%d\n", r % m);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}