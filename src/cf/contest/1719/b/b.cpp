/*
    Created by rdstihz at 2022-08-16 22:47:07
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    if(k % 4 == 0) {
        printf("NO\n");
    }else if(k % 2 == 0) {
        printf("YES\n");
        for(int i = 2; i <= n; i += 4) {
            printf("%d %d\n", i, i - 1);
        }
        for(int i = 4; i <= n; i += 4) {
            printf("%d %d\n", i - 1, i);
        }
        
    }else {
        printf("YES\n");
        for(int i = 1; i <= n; i += 2) {
            printf("%d %d\n", i, i + 1);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}