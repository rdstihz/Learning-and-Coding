#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1000000 + 100;
LL f[maxn];
LL d[20][100000 + 100];

int t[maxn], len[maxn];

int n;
LL H;
bool check(int m) {
    
    for(int i = 0; i < (1 << n); i++)
        f[i] = -INF;
    f[0] = 0;
    for(int S = 0; S < (1 << n); S++) {
        
        if(f[S] >= H) return true;
        if(f[S] < 0) continue;

        int cur = 0;
        for(int k = 0; k < n; k++)
            if(S >> k & 1)
                cur += t[k]; 
        if(cur >= m) continue;
        for(int i = 0; i < n; i++) {
            if(S >> i & 1) continue;

            int x = min(len[i] - 1, m - cur - 1);
            f[S | (1 << i)] = max(f[S] + d[i][x], f[S | (1 << i)]);
        }
    }

    return false;
}

void solve() {
    scanf("%d%lld", &n, &H);


    for(int i = 0; i < n; i++) {
        scanf("%d%d", t + i, len + i);
        for(int j = 0; j < len[i]; j++) 
            scanf("%lld", &d[i][j]);
        
        for(int j = 1; j < len[i]; j++)
            d[i][j] += d[i][j - 1];

    }
    int l = 0, r =  2000000 + 10;
    int m;
    while(l < r) {
        m = l + r >> 1;
        if(check(m))
            r = m;
        else l = m + 1;
    }
    if(!check(l)) printf("-1\n");
    else printf("%d\n", l - 1);
}


int main() {
    int T;
    scanf("%d", &T);
    while(T--)
        solve();
    return 0;
}