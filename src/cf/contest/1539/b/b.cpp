/*
    Created by rdstihz at 2021-06-20 18:20:28
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;

int S[maxn];
char s[maxn];

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
        S[i] = S[i - 1] + s[i] - 'a' + 1;
    int l, r;
    while (q--) {
        scanf("%d%d", &l, &r);
        printf("%d\n", S[r] - S[l - 1]);
    }

    return 0;
}