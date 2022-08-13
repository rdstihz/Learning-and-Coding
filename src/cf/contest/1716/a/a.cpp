/*
    Created by godlei at 2022-08-04 22:35:56
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int q = n / 3;
    int ans=  0;
    if(n % 3 == 0)
        ans = q;
    else if(n % 3 == 2 || n % 3 == 1)
        ans = q + 1;
    
    if(n == 1)
        ans = 2;
    
    printf("%d\n", ans);

}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}