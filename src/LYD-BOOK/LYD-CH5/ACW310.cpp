#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 30;

LL f[maxn][4];

void init() {
    f[0][0] = 1;
    for (int i = 1; i <= 20; i++) {
        f[i][0] = 9 * (f[i - 1][0] + f[i - 1][1] + f[i - 1][2]);
        f[i][1] = f[i - 1][0];
        f[i][2] = f[i - 1][1];
        f[i][3] = 10 * f[i - 1][3] + f[i - 1][2];
    }
}

int main() {

    init();

    int T;
    cin >> T;
    while (T--) {
        LL X;
        cin >> X;
        int n = 0;
        while (f[n][3] < X)
            n++;

        int cnt = 0; //前半部分末尾6的个数
        for (int i = n; i >= 1; i--) {

            for (int j = 0; j <= 9; j++) {
                LL cur = f[i - 1][3];

                if (cnt == 3 || j == 6) {
                    for (int k = max(0, 3 - cnt - (j == 6)); k < 3; k++)
                        cur += f[i - 1][k];
                }

                if (cur < X) {
                    X -= cur;
                } else {
                    printf("%d", j);

                    if (cnt < 3) {
                        if (j == 6)
                            cnt++;
                        else
                            cnt = 0;
                    }

                    break;
                }
            }
        }
        cout << endl;
    }

    return 0;
}