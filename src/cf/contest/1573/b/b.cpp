/*
    Created by rdstihz at 2021-11-05 14:25:58
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
int a[maxn], b[maxn];

int pos[maxn * 2]; //第一个小于i的数的位置

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
        scanf("%d", b + i);

    for (int i = 0; i <= 2 * n; i++)
        pos[i] = n;

    for (int i = 1; i <= n; i++)
        pos[a[i]] = i;

    for (int i = 2; i <= 2 * n; i++)
        pos[i] = min(pos[i], pos[i - 1]);

    // for (int i = 1; i <= 2 * n; i++)
    //     printf("%d ", pos[i]);
    // printf("\n");

    int ans = 2 * n;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, i + pos[b[i]] - 2);
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