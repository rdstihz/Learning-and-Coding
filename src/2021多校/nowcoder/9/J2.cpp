#include <bits/stdc++.h>

using namespace std;

int c[4][4];

void solve() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            scanf("%d", &c[i][j]);

    int ans = 0;
    //直走
    for (int i = 0; i < 4; i++) {
        int j = (i + 2) % 4;
        //i -> j,  j -> i, i -> i + 1
        ans += c[i][j];
        int k = min(c[i][j], c[j][i]);
        c[i][j] -= k, c[j][i] -= k;
        k = min(c[i][j], c[i][(i + 1) % 4]);
        c[i][j] -= k, c[i][(i + 1) % 4] -= k;
        c[i][j] = 0;
    }
    //左转
    for (int i = 0; i < 4; i++) {
        int j = (i + 1) % 4;
        ans += c[i][j];
        int ii = (i + 2) % 4;
        int jj = (i + 3) % 4;
        int k = min(c[i][j], c[ii][jj]);
        c[ii][jj] -= k;
        c[i][j] = 0;
    }
    //右转
    for(int i = 0; i < 4; i++) {
        int j = (i + 3) % 4;
        if(c[i][j] > ans) ans = c[i][j];
    }
    printf("%d\n", ans);

}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}