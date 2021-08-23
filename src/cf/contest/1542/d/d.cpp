/*
    Created by rdstihz at 2021-07-03 22:48:41
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000;
typedef long long LL;
const LL P = 998244353;
LL f[maxn][maxn];
/*

f[i][j] 前i次操作后， 堆有j个数 <= a[x] 的方案数


*/
int a[maxn];
int op[3];
int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%s", op);
        if (*op == '-')
            a[i] = -1;
        else
            scanf("%d", a + i);
    }
    LL ans = 0;
    for (int k = 1; k <= n; k++) {
        if (a[k] == -1)
            continue;

        memset(f, 0, sizeof(f));
        f[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == k) {
                    if (j)
                        f[i][j] = f[i - 1][j - 1];
                    else
                        f[i][j] = 0;
                    continue;
                }

                f[i][j] = f[i - 1][j]; // 不选

                //选
                if (a[i] == -1) {
                    if (j == 0 && i > k) continue;
                    f[i][j] = (f[i][j] + f[i - 1][j + 1]) % P;
                    if (!j) f[i][j] = (f[i][j] + f[i - 1][j]) % P;
                } else if (a[i] < a[k] || (a[i] == a[k] && i <= k)) {
                    if (j) f[i][j] = (f[i][j] + f[i - 1][j - 1]) % P;
                } else {
                    f[i][j] = (f[i][j] + f[i - 1][j]) % P;
                }
            }
        }
        LL s = 0;
        for (int j = 1; j <= n; j++)
            s = (s + f[n][j]) % P;
        ans = (ans + s * a[k] % P) % P;
    }
    printf("%lld\n", ans);
    return 0;
}