/*
    Coded by --HY-- & rdstihz & Apojacsleam
*/
#include <cstdio>
#define max(x, y) ((x > y) ? (x) : (y))
#define min(x, y) ((x < y) ? (x) : (y))
#define N 2011
int n, m, T, left[N][N], right[N][N], up[N][N];
int f[N][N];
int main() {
    scanf("%d", &T);
    while (T--) {
        int ans = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                scanf("%d", &f[i][j]);
                up[i][j] = 1;
                left[i][j] = right[i][j] = j;
            }
        for (int i = n; i >= 1; i--)
            for (int j = m; j >= 1; j--)
                f[i][j] = (f[i][j] < f[i - 1][j]);
        for (int i = 1; i <= n; i++)
            for (int j = 2; j <= m; j++)
                if (!f[i][j - 1])
                    left[i][j] = left[i][j - 1];
        for (int i = 1; i <= n; i++)
            for (int j = m - 1; j > 0; j--)
                if (!f[i][j + 1])
                    right[i][j] = right[i][j + 1];

        
        
        for (int j = 1; j <= m; j++)
            for (int i = 1; i <= n; i++)
                if (!f[i][j]) {
                    if (i > 1 && !f[i - 1][j]) {
                        left[i][j] = max(left[i][j], left[i - 1][j]);
                        right[i][j] = min(right[i][j], right[i - 1][j]);
                        up[i][j] = up[i - 1][j] + 1;
                    }
                    int a = right[i][j] - left[i][j] + 1;
                    ans = max(ans, a * (up[i][j] + (up[i][j] < i)));
                
                }
        
        
        printf("%d\n", ans);
    }
    return 0;
}
/*
1
3 3
5 3 2
1 2 3
2 7 8
*/

/*
1
4 4
1 2 1 2
2 1 2 2
3 3 3 3
1 2 2 1
*/