/*
    Created by godlei at 2021-12-01 22:54:57
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000000 + 100;
int a[maxn];
void solve() {
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }

    sort(a + 1, a + 1 + n);
    
    int j = 1;
    for(int i = 1; i <= n / 2; i++) {
        printf("%d %d\n", a[++j], a[1]);
    }


}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}