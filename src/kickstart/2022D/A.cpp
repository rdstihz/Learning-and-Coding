#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000 + 100;
int a[maxn];

int main() {
    int T;
    scanf("%d", &T);
    
    for(int kase = 1; kase <= T; kase++) {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        sort(a + 1, a + 1 + n, greater<int>());
        double ans = 0;
        for(int i = 1; i < m; i++) 
            ans += a[i];
        
        int t = n - m + 1;
        if(t % 2 == 1) {
            ans += a[m - 1 + (t + 1) / 2];
        }else {
            ans += (a[m - 1 + t / 2] + a[m - 1 + t / 2 + 1]) / 2.0;
        }
        printf("Case #%d: %.1lf\n", kase, ans);
    }
    
    return 0;
}