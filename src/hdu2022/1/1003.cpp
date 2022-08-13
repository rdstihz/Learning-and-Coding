#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
const int maxn = 1100;
int w[maxn], v[maxn];
int n, m;

bitset<maxn> f[2][maxn];


void solve() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", v + i, w + i);
    
    for(int i = 0; i < maxn; i++)
        f[0][i] = f[1][i] = 0;
    
    f[0][0][0] = 1;
    int p = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 1024; j++) {
            // for(int k = 0; k <= m; k++) {
            //     if(k >= v[i]) f[j][k] = f[j][k] | f[j ^ w[i]][k - v[i]];
            // }
            f[p][j] = f[p ^ 1][j] | (f[p ^ 1][j ^ w[i]] << v[i]);
        }
        p ^= 1;
    }

    int ans = -1;
    for(int i = 1023; i >= 0; i--)
        if(f[p ^ 1][i][m]) {
            ans = i;
            break;
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

/*
1
5 4
2 4
1 6
2 2
2 12
1 14
*/
