/*
    Created by rdstihz at 2021-08-30 00:50:40
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
int a[maxn], b[maxn], d[maxn];
int s[maxn], pos[maxn];
int sum[maxn];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", b + i);
    }
    for (int i = 1; i <= n; i++)
        d[i] = b[i] - a[i];
    int m = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] * s[m] > 0)
            s[m] += d[i], b[i] = m;
        else
            s[++m] = d[i], b[i] = m;
    }

    return 0;
}