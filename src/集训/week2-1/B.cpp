#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 360;
const int maxm = 41;

int f[maxn][maxm][maxm][maxm];
int v[maxn];

int main() {
    int n, m;
    int c[5];
    memset(c, 0, sizeof(c));
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", v + i);
    }
    int t;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &t);
        c[t]++;
    }

    f[1][c[1]][c[2]][c[3]] = v[1];

    for (int i = 1; i <= n; i++) {
        for (int a = 0; a <= c[1]; a++)
            for (int b = 0; b <= c[2]; b++)
                for (int d = 0; d <= c[3]; d++) {
                    if (!f[i][a][b][d]) continue;
                    int e = n - i - a - 2 * b - 3 * d;
                    e /= 4;

                    if (a && i + 1 <= n) {
                        f[i + 1][a - 1][b][d] = max(f[i + 1][a - 1][b][d], f[i][a][b][d] + v[i + 1]);
                    }
                    if (b && i + 2 <= n) {
                        f[i + 2][a][b - 1][d] = max(f[i + 2][a][b - 1][d], f[i][a][b][d] + v[i + 2]);
                    }
                    if (d && i + 3 <= n) {
                        f[i + 3][a][b][d - 1] = max(f[i + 3][a][b][d - 1], f[i][a][b][d] + v[i + 3]);
                    }
                    if (e && i + 1 <= n) {
                        f[i + 4][a][b][d] = max(f[i + 4][a][b][d], f[i][a][b][d] + v[i + 4]);
                    }
                }
    }
    printf("%d\n", f[n][0][0][0]);
    return 0;
}