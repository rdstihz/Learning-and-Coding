#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long LL;
const LL P = 1e9 + 7;
const int maxn = 1010;
const int maxm = 210;

LL f[2][maxm][maxm];
LL g[2][maxm][maxm];

char a[maxn], b[maxm];

int main() {

    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    scanf("%s%s", a + 1, b + 1);

    f[0][0][0] = 1;
    int p = 0;
    for (int i = 1; i <= n; i++) {
        f[p ^ 1][0][0] = 1;
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= q; k++) {
                if (a[i] != b[j]) {
                    f[p ^ 1][j][k] = f[p][j][k];
                    g[p ^ 1][j][k] = 0;
                } else {
                    f[p ^ 1][j][k] = (f[p][j][k] + f[p][j - 1][k - 1] + g[p][j - 1][k]) % P;
                    g[p ^ 1][j][k] = (f[p][j - 1][k - 1] + g[p][j - 1][k]) % P;
                }
            }
        }
        p ^= 1;
    }
    printf("%lld\n", f[p][m][q]);
    return 0;
}