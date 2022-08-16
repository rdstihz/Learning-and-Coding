#include <bits/stdc++.h>


using namespace std;
const int P = 998244353;
const int maxn = 600;



void solve() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    int x;
    
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        ans = ((ans + x) % P + 1ll *  ans * x % P) % P;
    }
    printf("%d\n", ans);
}


int main() {
    int T;
    scanf("%d", &T);
    while(T--)
        solve();
    return 0;
}