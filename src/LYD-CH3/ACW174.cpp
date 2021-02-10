#include <cstdio>

const int maxn = 25;

char str[maxn][maxn];
int n, m;
int tx, ty;
int bx, by;
int sx, sy;

int main() {

    while (scanf("%d%d", &n, &m), n) {
        for (int i = 1; i <= n; i++)
            scanf("%s", str[i] + 1);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (str[i][j] == 'T') {
                    tx = i;
                    ty = j;
                } else if (str[i][j] == 'B') {
                    bx = i;
                    by = j;
                } else if (str[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
            }
        
        
    }

    return 0;
}