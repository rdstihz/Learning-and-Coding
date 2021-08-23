/*
    Created by rdstihz at 2021-07-17 22:44:54
*/

#include <bits/stdc++.h>

using namespace std;

char a[100][100];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(a, 0, sizeof(a));

        //第一行
        for(int i = 1; i <= m; i += 2)
            a[1][i] = 1;
        //最后一行
        for(int i = m; i >= 1; i -= 2)
            a[n][i] = 1;
        //左
        for(int j = 3; j < n - 1; j += 2)
            a[j][1] = 1;
        for(int j = n - 2; j > 2; j -= 2)
            a[j][m] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j ++)
                printf("%d", a[i][j]);
            printf("\n");
        }
        printf("\n");

    }
    return 0;
}