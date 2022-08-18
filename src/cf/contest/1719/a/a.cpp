/*
    Created by rdstihz at 2022-08-16 22:35:33
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    scanf("%d%d", &a, &b);
    if(((a ^ b) & 1) == 0) {
        puts("Tonya");
    }else puts("Burenka");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}