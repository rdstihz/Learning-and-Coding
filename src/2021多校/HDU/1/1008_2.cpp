#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000 + 10;
int a[maxn][maxn];
int up[maxn];
int st[maxn], top;
int h[maxn][maxn];
int l[maxn][maxn], r[maxn][maxn];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                scanf("%d", &a[i][j]);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] >= a[i - 1][j])
                    h[i][j] = h[i - 1][j] + 1;
                else
                    h[i][j] = 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            top = 0;
            st[0] = 0;
            for (int j = 1; j <= m; j++) {
                while (top > 0 && h[i][st[top]] >= h[i][j])
                    top--;
                l[i][j] = st[top] + 1;
                st[++top] = j;
            }
        }

        for (int i = 1; i <= n; i++) {
            top = 0;
            st[0] = m + 1;
            for (int j = m; j >= 1; j--) {
                while (top > 0 && h[i][st[top]] >= h[i][j])
                    top--;
                r[i][j] = st[top] - 1;
                st[++top] = j;
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                ans = max(ans, h[i][j] * (r[i][j] - l[i][j] + 1));
        printf("%d\n", ans);
    }

    return 0;
}