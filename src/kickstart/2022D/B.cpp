#include <bits/stdc++.h>

using namespace std;

const int maxn = 6000 + 10;
typedef long long LL;
int a[maxn], b[maxn];
LL sa1[maxn], sa2[maxn], sa[maxn];
LL sb1[maxn], sb2[maxn], sb[maxn];

void solve() {
    int n, m, k;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) 
        scanf("%d", a + i);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) 
        scanf("%d", b + i);
    scanf("%d", &k);

    sa1[0] = 0, sa2[0] = 0;
    for(int i = 1; i <= n; i++)
        sa1[i] = sa1[i - 1] + a[i];
    for(int i = 1; i <= n; i++)
        sa2[i] = sa2[i - 1] + a[n + 1 - i];
    

    sb1[0] = 0, sb2[0] = 0;
    for(int i = 1; i <= m; i++)
        sb1[i] = sb1[i - 1] + b[i];
    for(int i = 1; i <= m; i++)
        sb2[i] = sb2[i - 1] + b[m + 1 - i];
    

    for(int i = 1; i <= n; i++) {
        sa[i] = 0;
        for(int j = 0; j <= i; j++) {
            sa[i] = max(sa[i], sa1[j] + sa2[i - j]);
        }
    }

    for(int i = 1; i <= m; i++) {
        sb[i] = 0;
        for(int j = 0; j <= i; j++) {
            sb[i] = max(sb[i], sb1[j] + sb2[i - j]);
        }
    }
    
    // for(int i = 1; i <= n; i++) {
    //     printf("%lld ", sa1[i]);
    // }
    // printf("\n");
    // for(int i = 1; i <= n; i++) {
    //     printf("%lld ", sa2[i]);
    // }
    // printf("\n");
    // for(int i = 1; i <= n; i++) {
    //     printf("%lld ", sa[i]);
    // }
    // printf("\n");
    // for(int i = 1; i <= n; i++) {
    //     printf("%lld ", sb[i]);
    // }
    // printf("\n");

    LL ans = 0;
    for(int i = max(0, k - m); i <= min(k, n); i++) {
        ans = max(ans, sa[i] + sb[k - i]);
    }
    printf("%lld\n", ans);
}


int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}