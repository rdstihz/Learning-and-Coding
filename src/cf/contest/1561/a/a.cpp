/*
    Created by $%U%$ at $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000;
int a[maxn];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[i] > a[j])
                cnt++;

    int k = 0;
    while (cnt) {
        k++;
        if (k % 2) {
            for (int i = 1; i < n; i += 2)
                if (a[i] > a[i + 1]) {
                    cnt--;
                    swap(a[i], a[i + 1]);
                }
        } else {
            for (int i = 2; i < n; i += 2)
                if (a[i] > a[i + 1]) {
                    swap(a[i], a[i + 1]);
                    cnt--;
                }
        }
    }
    printf("%d\n", k);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}