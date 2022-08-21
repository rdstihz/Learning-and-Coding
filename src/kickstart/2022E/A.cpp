#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++) {
        int n;
        scanf("%d", &n);
        n--;
        int ans = 1 + n / 5;
        printf("Case #%d: %d\n",kase, ans);
    }
    
    return 0;
}