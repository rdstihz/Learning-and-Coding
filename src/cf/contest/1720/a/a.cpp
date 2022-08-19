/*
    Created by rdstihz at 2022-08-18 21:35:19
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);

    long long A = 1ll * a * d, B = 1ll * b * c;
    if(A == B) puts("0");
    else if(A == 0 || B == 0) puts("1");
    else if(A % B == 0 || B % A == 0) puts("1");
    else puts("2");

}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}