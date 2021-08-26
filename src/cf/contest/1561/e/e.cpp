/*
    Created by rdstihz at 2021-08-25 13:52:37
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 3000;
int a[maxn];

void rev(int x, int y) {
    printf("%d ", y);
    while (x < y) {
        swap(a[x], a[y]);
        x++, y--;
    }
}

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);

    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 != i % 2) {
            printf("-1\n");
            return;
        }
    }

    printf("%d\n", (n - 1) / 2 * 5);
    while (n > 1) {
        //找到n翻到第一个
        int pos = 1;
        while (a[pos] != n)
            pos++;
        rev(1, pos);
        //找到n - 1, 把n翻到n-1前
        pos = 1;
        while (a[pos] != n - 1)
            pos++;
        rev(1, pos - 1);
        //全翻
        rev(1, n);
        //找到n翻到第一个
        pos = 1;
        while (a[pos] != n)
            pos++;
        rev(1, pos);
        //全翻
        rev(1, n);
        n -= 2;
    }
    puts("");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}