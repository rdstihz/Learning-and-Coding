/*
    Created by rdstihz at 2022-08-20 22:57:26
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 100000 + 100;
int a[maxn];
LL f[maxn];

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }

    LL ans = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] != a[i - 1]) {
            f[i] = 1ll * i * (n - i + 1);
        }else {
            f[i] = n - i + 1;
        }
        ans += f[i];
    }

    //printf("init %lld\n", ans);

    while(m--) {
        int i, x;
        scanf("%d%d", &i, &x);
        
        LL g;
        if(x != a[i - 1])
            g = 1ll * i * (n - i + 1);
        else 
            g = n - i + 1;
        
        ans += g - f[i];
        f[i] = g;
        a[i] = x;

        if(i < n) {
            i++;
            if(a[i] != a[i - 1])
                g = 1ll * i * (n - i + 1);
            else
                g = n - i + 1;
            
            ans += g - f[i];
            f[i] = g;
        }
        printf("%lld\n", ans);
    }

}

int main() {
    int T;
    T = 1;
    while (T--)
        solve();
    return 0;
}