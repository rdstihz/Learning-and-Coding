/*
    Created by rdstihz at 2021-07-14 23:04:41
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;
int a[maxn];

int f[maxn], g[maxn], pre[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", a + i);

        long long ans = 0;
        int pre = 1;
        for (int i = 1; i <= n; i++) {
            int temp = -1;
            for (int j = i - 1; j >= pre; j--) {
                if (a[j] <= temp) {
                    pre = j + 1;
                    break;
                } else if (a[j] <= a[i]) {
                    temp = a[j];
                }
            }

            temp = 1e9 + 10;
            for (int j = i - 1; j >= pre; j--) {
                if (a[j] >= temp) {
                    pre = j + 1;
                    break;
                } else if (a[j] >= a[i]) {
                    temp = a[j];
                }
            }

            ans += i - pre + 1;
        }

        printf("%lld\n", ans);
    }

    return 0;
}