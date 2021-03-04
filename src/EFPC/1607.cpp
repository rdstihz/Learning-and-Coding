#include <cstdio>
#include <cstring>

const int maxn = 1010;
int a[maxn];
int f[maxn];
int g[maxn][maxn];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; k++) {
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        int n;
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int d = gcd(a[i], a[j]);
                g[i][j] = d;
                f[i] = f[i] > d ? f[i] : d;
                f[j] = f[j] > d ? f[j] : d;
            }
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int d = g[i][j];
                if (d >= f[i] && d >= f[j])
                    cnt++;
            }
        }
        printf("Case %d: %d\n", k, cnt);
    }

    return 0;
}