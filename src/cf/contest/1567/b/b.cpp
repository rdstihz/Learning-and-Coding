/*
    Created by rdstihz at 2021-10-05 18:40:21
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 300000 + 100;
int s[maxn];

void solve() {
    int a, b;
    scanf("%d%d", &a, &b);
    int cur = s[a - 1];
    // for (int i = 1; i < a; i++)
    //     cur ^= i;
    cur ^= b;

    if (cur == 0) {
        printf("%d\n", a);
    } else if (cur != a) {
        printf("%d\n", a + 1);
    } else {
        printf("%d\n", a + 2);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= 300010; i++)
        s[i] = s[i - 1] ^ i;
    while (T--)
        solve();
    return 0;
}