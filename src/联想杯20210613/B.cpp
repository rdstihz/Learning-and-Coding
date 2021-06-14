#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL P = 1e9 + 7;

const int maxn = 2010;

LL f[maxn][maxn];

int main() {
    int n, m;

    scanf("%d%d", &n, &m);

    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        LL s = 0;
        for (int j = 0; j <= m; j++) {
            s = (s + f[i - 1][j]) % P;
            f[i][j] = s;
        }
    }



    LL ans = 1;


    for (int i = 1; i <= n; i++) {
        LL s = 0;
        for (int j = 0; j <= m; j++) {
            ans = (ans + f[i][j] * s % P) % P;
            s = (s + f[n - i][j]) % P;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
