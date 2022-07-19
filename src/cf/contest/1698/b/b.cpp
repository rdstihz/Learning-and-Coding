/*
    Created by godlei at 2022-06-28 22:41:59
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;
int a[maxn];

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    if(k == 1) {
        printf("%d\n", (n + 1) / 2 - 1);
    }else {
        int ans = 0;
        for(int i = 2; i < n; i++) {
            if(a[i] > a[i - 1] + a[i + 1]) ans++;
        }
        printf("%d\n", ans);
    }

}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}