/*
    Created by rdstihz at 2021-07-17 22:55:08
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 300000 + 100;

int a[maxn], b[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", a + i);
        for (int i = 1; i <= n; i++)
            scanf("%d", b + i);
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);

        int t = n - n / 4;
        int A = 0, B = 0;
        for (int i = n - t + 1; i <= n; i++) {
            A += a[i];
            B += b[i];
        }

        int ans = 0;
        
        int i = n - t + 1;
        int j = n - t;
        while (A < B) {
            n++;
            ans++;
            if (n - n / 4 > t) {
                A += 100;
                if (j > 0) B += b[j--];
            }else {
                A += 100 - a[i++];
            }
            t = n - n / 4;
        }

        printf("%d\n", ans);
    }

    return 0;
}