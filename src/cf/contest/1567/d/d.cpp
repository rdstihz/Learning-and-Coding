/*
    Created by rdstihz at 2021-10-05 19:06:49
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;

int a[maxn], b[maxn];

void solve() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int s, n;
    scanf("%d%d", &s, &n);
    int sum = 0;
    while (s) {
        a[++a[0]] = s % 10;
        s /= 10;
        sum += a[a[0]];
    }
    while (sum < n)
        for (int i = 2; sum < n && i <= a[0]; i++) {
            if (sum <= n && a[i]) {
                a[i]--;
                a[i - 1] += 10;
                sum += 9;
                i = max(1, i - 2);
                //break;
            }
        }

    int cur = 1;
    for (int i = 1, j = 1; i <= a[0]; i++) {

        while (a[i] && j < n) {
            b[j] = cur;
            j++;
            a[i]--;
        }
        if (j == n) {
            b[j] += a[i] * cur;
            a[i] = 0;
        }
        cur *= 10;
    }

    for (int i = 1; i <= n; i++)
        printf("%d%c", b[i], i == n ? '\n' : ' ');
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}