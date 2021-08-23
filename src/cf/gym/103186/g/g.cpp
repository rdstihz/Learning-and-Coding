/*
    Created by rdstihz at 2021-07-15 15:15:30
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
const LL P = 998244353;
LL a[maxn];

LL pow_mod(LL a, LL b, LL p) {
    LL res = 1;
    while (b) {
        if (b & 1)
            res = res * a % P;
        b >>= 1;
        a = a * a % P;
    }
    return res;
}

int main() {

    int n;
    scanf("%d", &n);
    LL S = 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        if (a[i] % P == 0) {
            cnt++;
            continue;
        }
        S = S * a[i] % P;
    }

    if (cnt == 0) {
        for (int i = 1; i <= n; i++)
            printf("%lld ", S * pow_mod(a[i], P - 2, P) % P);
    }else if(cnt == 1) {
        for (int i = 1; i <= n; i++)
            printf("%lld ", a[i] % P == 0 ? S : 0);
    }else{
        for(int i = 1; i <= n; i++)
            printf("0 ");
    }
    printf("\n");

    return 0;
}