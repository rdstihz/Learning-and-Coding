/*
    Created by rdstihz at 2022-08-19 13:29:05
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 510;
int a[maxn][maxn];
int bd[maxn * maxn][4];
int s[maxn][maxn];

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n * n; i++) {
        bd[i][0] = bd[i][1] = n + 1;
        bd[i][2] = bd[i][3] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            int t = a[i][j];
            bd[t][0] = min(bd[t][0], i);
            bd[t][1] = min(bd[t][1], j);
            bd[t][2] = max(bd[t][2], i);
            bd[t][3] = max(bd[t][3], j);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n * n; i++)
        if (bd[i][0] <= n) cnt++;

    if (cnt <= k) {
        printf("%d\n", k - cnt);
        return;
    }

    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n * n; i++) {
            if (bd[i][0] == n + 1) continue;
            int mix = bd[i][0], miy = bd[i][1], mxx = bd[i][2], mxy = bd[i][3];
            mix = min(mix, n - len + 1);
            miy = min(miy, n - len + 1);
            mxx = max(1, mxx - len + 1);
            mxy = max(1, mxy - len + 1);

            if (mxx <= mix && mxy <= miy) {
                s[mxx][mxy]++;
                s[mix + 1][miy + 1]++;
                s[mxx][miy + 1]--;
                s[mix + 1][mxy]--;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            }
        }

        for (int i = 1; i <= n - len + 1; i++) {
            for (int j = 1; j <= n - len + 1; j++) {
                if (cnt - s[i][j] == k || cnt - s[i][j] + 1 == k) {
                    printf("1\n");
                    return;
                }
            }
        }

        for (int i = 0; i <= n + 1; i++)
            for (int j = 0; j <= n + 1; j++)
                s[i][j] = 0;
    }
    printf("2\n");
}

int main() {
    int T;
    // scanf("%d", &T);
    T = 1;
    while (T--)
        solve();
    return 0;
}