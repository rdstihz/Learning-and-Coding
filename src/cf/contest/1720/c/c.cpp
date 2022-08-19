/*
    Created by rdstihz at 2022-08-18 21:49:08
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 600;
char a[maxn][maxn];

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%s", a[i] + 1);
        for(int j = 1; j <= m; j++) {
            a[i][j] -= '0';
            cnt += a[i][j];
        }
    }
    int minv = 2;
    for(int i = 1; i < n && minv; i++) {
        for(int j = 1; j < m && minv; j++) {
            int t = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
            if(t == 4) continue;
            if(t == 3) minv = min(minv, 1);
            else if(t == 2) {
                minv = 0;
            }else if(t <= 1) {
                minv = 0;
            }
        }
    }
    printf("%d\n", cnt - minv);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}