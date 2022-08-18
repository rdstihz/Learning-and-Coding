/*
    Created by rdstihz at 2022-08-16 23:14:03
*/

#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 5001;
int a[maxn];
int f[2][8192][2], g[maxn];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for(int i = 0; i <= n; i++) {
        g[i] = INF;
    }

    f[0][0][1] = 0;
    g[0] = 0;
    int p = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 8191; j++)
            f[p][j][0] = f[p][j][1] = INF;
        f[p][a[i]][0] = f[p][a[i]][1] = g[i - 1];
        for(int j = 0; j <= 8191; j++) {
            //单独
            if(g[i - 1] < INF) f[p][j][0] = min(f[p][j][0], g[i - 1] + 1);
            //与上一个一起
            if(f[p ^ 1][a[i] ^ j][0] < INF) f[p][j][1] = min(f[p][j][1] ,f[p ^ 1][a[i] ^ j][0] + 1);
            if(f[p ^ 1][a[i] ^ j][1] < INF) f[p][j][1] = min(f[p][j][1] ,f[p ^ 1][a[i] ^ j][1] + 1);
        }

        g[i] = min(g[i], f[p][0][0]);
        g[i] = min(g[i], f[p][0][1]);
        p ^= 1;
    }

    printf("%d\n", g[n]);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}