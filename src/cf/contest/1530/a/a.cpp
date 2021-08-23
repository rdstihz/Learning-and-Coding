/*
    Created by rdstihz at 2021-07-17 22:37:39
*/

#include <bits/stdc++.h>

using namespace std;


int main() {
    int T;
    int n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        //int m = 11111111;
        int ans = 0;
        while(n) {
            ans = max(ans, n % 10);
            n /= 10;
        }
        printf("%d\n", ans);
    }
    return 0;
}