/*
    Created by rdstihz at 2021-06-26 00:04:39
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;

int a[maxn];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", a + i);

        long long ans = 0;

        for (int i = 1; i <= n; i++) {
            int t = ((a[i] - i) % a[i] + a[i]) % a[i];
            for (int j = t; j < i; j += a[i])
                if (i + j == a[i] * a[j])
                    ans++;
        }

        printf("%lld\n", ans);
    }

    return 0;
}