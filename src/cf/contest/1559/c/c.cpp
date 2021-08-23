/*
    Created by rdstihz at 2021-08-15 22:52:48
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 30000;
int a[maxn];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    a[n + 1] = 1;
    int pos = 1;
    while (a[pos] == 0)
        pos++;
    for (int i = 1; i < pos; i++)
        printf("%d ", i);
    printf("%d ", n + 1);
    for (int i = pos; i <= n; i++)
        printf("%d ", i);
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}