/*
    Created by godlei at 2022-08-04 23:02:15
*/

#include <bits/stdc++.h>

using namespace std;
const int P = 998244353;
const int maxn = 200000 + 100;
int f[maxn];
int g[maxn];
void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    f[0] = 1;

    for(int i = 0; i * i <= n; i++) {
        // k + i的倍数
        memset(g, 0, sizeof(g));
        int t = k + i;
        for(int j = t; j <= n; j++) {
            f[j] = (f[j] + f[j - t]) % P;
        }

        for(int j = 1; j <= n; j++) {
            printf("%d ", f[j]);
        }
        printf("\n");
    }

    for(int i = 1; i <= n; i++)
        printf("%d ", f[i]);
    printf("\n");
}

int main() {
    solve();
    return 0;
}