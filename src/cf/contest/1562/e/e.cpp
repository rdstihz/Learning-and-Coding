/*
    Created by rdstihz at 2021-08-28 20:40:57
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 5010;
int lcp[maxn][maxn];
int dp[maxn];
char s[maxn];
void solve() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);

    lcp[n + 1][n + 1] = lcp[n][n + 1] = lcp[n + 1][n] = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= 1; j--) {
            if (i == j)
                lcp[i][j] = n - i + 1;
            else {
                if (s[i] == s[j])
                    lcp[i][j] = 1 + lcp[i + 1][j + 1];
                else
                    lcp[i][j] = 0;
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     printf("%d ", lcp[1][i]);
    // }
    // printf("\n");
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = n - i + 1;
        for (int j = 1; j < i; j++) {
            int x = lcp[i][j];
            if (i + x <= n && s[i + x] > s[j + x])
                dp[i] = max(dp[i], dp[j] + n - (i + x) + 1);
        }
        ans = max(ans, dp[i]);
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