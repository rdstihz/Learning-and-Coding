#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL P = 1e9 + 7;
const int maxn = 3010;
LL f[maxn][maxn];
LL frac[maxn];
int main() {
    int N = 3001;
    f[0][0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j] * j % P) % P;
    frac[0] = 1;
    for (int i = 1; i <= N; i++)
        frac[i] = frac[i - 1] * i % P;
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        LL s = 0;
        for (int i = 1; i <= m + 1; i++)
            s = (s + f[n][i]) % P;
        printf("%lld\n", frac[m] * s % P);
    }

    return 0;
}