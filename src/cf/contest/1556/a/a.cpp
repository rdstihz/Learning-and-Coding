/*
    Created by rdstihz at 2021-08-29 22:37:59
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == b && a == 0) {
        printf("0\n");
        return;
    }
    int d = a - b;
    if (d % 2) {
        printf("-1\n");
    } else if (d == 0) {
        printf("1\n");
    } else {
        printf("2\n");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}