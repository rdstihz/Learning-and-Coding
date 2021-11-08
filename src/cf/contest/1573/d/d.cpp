/*
    Created by rdstihz at 2021-11-05 15:19:01
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;
int a[maxn];
void solve() {
    int n;
    scanf("%d", &n);
    int s = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        s += a[i];
    }
    if (s % 2) {
        printf("NO\n");
        return;
    }

    if (n % 2) {
        printf("YES\n%d\n", n / 2 + n / 2 - 1);
        for (int i = 1; i <= n - 2; i += 2)
            printf("%d ", i);
        for (int i = n - 4; i >= 1; i -= 2)
            printf("%d ", i);
        printf("\n");
        return;
    }

    int t = 0;
    for (int m = 1; m <= n; m++) {
        t += a[m];
        if (t % 2 == 0 && m % 2 == 1) {
            int cnt = 0;
            if (m > 1)
                cnt += m / 2 + m / 2 - 1;
            if (n - m > 1)
                cnt += (n - m) / 2 + (n - m) / 2 - 1;
            printf("YES\n%d\n", cnt);
            for (int i = 1; i <= m - 2; i += 2)
                printf("%d ", i);
            for (int i = m - 4; i >= 1; i -= 2)
                printf("%d ", i);
            for (int i = m + 1; i <= n - 2; i += 2)
                printf("%d ", i);
            for (int i = n - 4; i >= m + 1; i -= 2)
                printf("%d ", i);
            printf("\n");
            return;
        }
    }

    printf("NO\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}