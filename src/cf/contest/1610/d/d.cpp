/*
    Created by rdstihz at 2021-11-27 22:21:38
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL P = 1e9 + 7;
const int maxn = 200000 + 100;
LL B[maxn];
int cnt[32];


int main() {
    int n;
    scanf("%d", &n);
    B[0] = 1;

    for(int i = 1; i <= n; i++)
        B[i] = 2 * B[i - 1] % P;
    
    int x;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        int r = 0;
        while(x % 2 == 0) {
            r++;
            x /= 2;
        }
        cnt[r]++;
    }

    LL ans = B[n] - 1;
    for(int i = 1; i <= 30; i++) {
        //printf("%lld\n", ans);
        if(!cnt[i]) continue;
        int tot = 0;
        for(int j = i + 1; j <= 30; j++)
            tot += cnt[j];
        ans = (ans - B[cnt[i] - 1 + tot] + P) % P;

    }
    printf("%lld\n", ans);
    return 0;
}