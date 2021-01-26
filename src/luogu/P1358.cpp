#include <cstdio>

const int maxn = 10010;
const int P = 10007;

int a[maxn];
int C[maxn][102];


int main() {
    int n, m;
    scanf("%d%d", &n, &m);


    for (int i = 1; i <= m; i++) {
        scanf("%d",a+i);
    }

    //预处理组合数
    C[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= 100; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
    }

    int res = 1;

    for(int i = 1;i <= m;i++){
        res = (res * C[n][a[i]]) % P;
        n -= a[i];
    }
    printf("%d\n", res);
    return 0;
}