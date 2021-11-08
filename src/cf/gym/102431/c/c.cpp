/*
    Created by rdstihz at 2021-11-05 22:51:36
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 5000 + 100;
const LL INF = 1e14;
LL f[maxn][maxn]; //f(i, j)表示打完前i个，buffer区为最后j个字符的最小花费
LL g[maxn];       //g(i) = min(f[i][j])
int s[maxn];
int pre[maxn][maxn], maxf[maxn][maxn];

int readIn() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

void solve() {
    int n, x, y, z;
    n = readIn(), x = readIn(), y = readIn(), z = readIn();
    for (int i = 1; i <= n; i++)
        s[i] = readIn();

    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            if (s[i] == s[j])
                maxf[i][j] = 1 + maxf[i - 1][j - 1];
            else
                maxf[i][j] = 0;
        }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            maxf[i][j] = min(maxf[i][j], j - i);
        }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++)
            pre[i][j] = 0;
        for (int j = 1; j < i; j++) {
            pre[i][maxf[j][i]] = j;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--)
            pre[i][j] = max(pre[i][j], pre[i][j + 1]);
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= i; j++) {
    //         printf("%d ", pre[i][j]);
    //     }
    //     printf("\n");
    // }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            f[i][j] = INF;
            if (j == 0) { //操作1
                f[i][j] = g[i - 1] + x;
            } else {
                if (pre[i][j]) {
                    int k = pre[i][j];
                    //f[i][j] = min(f[k][j] + z + 1ll * x * (i - j - k), g[i - j] + y + z);
                    if (f[k][j] < INF) f[i][j] = min(f[i][j], f[k][j] + z + 1ll * x * (i - j - k));
                    if (g[i - j] < INF) f[i][j] = min(f[i][j], g[i - j] + y + z);
                }
            }
        }

        g[i] = INF;
        for (int j = 0; j <= i; j++)
            g[i] = min(g[i], f[i][j]);
    }
    printf("%lld\n", g[n]);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}