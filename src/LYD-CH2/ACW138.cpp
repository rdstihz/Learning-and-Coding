//
// Created by rdstihz on 2020/12/23.
//

#include <bits/stdc++.h>


using namespace std;

const int maxn = 1000000 + 10;
typedef unsigned long long ull;

char s[maxn];
ull h[maxn];
ull B[maxn];

int main() {

    scanf("%s", s + 1);
    int n, m;
    scanf("%d", &m);

    int l1, r1, l2, r2;

    n = strlen(s + 1);
    B[0] = 1;
    h[0] = 0;
    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] * 131 + s[i] - 'a';
        B[i] = B[i - 1] * 131;
    }

    while (m--) {
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);

        if (r1 - l1 != r2 - l2) {
            printf("No\n");
            continue;
        }

        if(l1 > l2) {
            int t = l1; l1 = l2; l2 = t;
            t = r1; r1 = r2; r2 = t;
        }
        if(h[r2] - h[l2 - 1] * B[r2 - l2 + 1] == h[r1] - h[l1 - 1] * B[r1 - l1 + 1] ) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }


    return 0;
}