/*
    Created by rdstihz at 2021-07-14 22:48:46
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000;
char s[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, a, b;
        scanf("%d%d%d", &n, &a, &b);
        scanf("%s", s + 1);
        if (b >= 0) {
            printf("%d\n", a * n + b * n);
        } else {
            int cnt = 1;
            for (int i = 2; i <= n; i++) {
                if (s[i] != s[i - 1])
                    cnt++;
            }
            printf("%d\n", a * n + b * (cnt / 2 + 1));
        }
    }

    return 0;
}