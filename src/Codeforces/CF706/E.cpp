#include <cstdio>

using namespace std;

const int maxn = 510;
char s[maxn][maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%s", s[i] + 1);

        for (int i = 1; i <= n; i += 3) {
            for (int j = 1; j <= m; j++)
                s[i][j] = 'X';

            if (i >= n - 2) break;

            bool flag = false;
            for (int j = 1; j <= m; j++) {
                if (s[i + 1][j] == 'X' || s[i + 2][j] == 'X') {
                    s[i + 1][j] = 'X';
                    s[i + 2][j] = 'X';
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                s[i + 1][1] = s[i + 2][1] = 'X';
            }
        }
        if (n % 3 == 0) {
            for (int j = 1; j <= m; j++)
                if (s[n][j] == 'X') {
                    s[n - 1][j] = 'X';
                }
        }
        for (int i = 1; i <= n; i++)
            printf("%s\n", s[i] + 1);
    }

    return 0;
}