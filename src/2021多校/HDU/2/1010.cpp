#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

LL mul(LL a, LL b, LL p) {
    return __int128(a) * b % p;
}

LL pow_mod(LL a, LL b, LL p) {
    LL res = 1;
    while (b) {
        if (b & 1)
            res = mul(res, a, p);
        b >>= 1;
        a = mul(a, a, p);
    }
    return res;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        long long a, p;
        scanf("%lld%lld", &a, &p);
        printf("%d\n", pow_mod(a, (p - 1) / 2, p) % 2 ? 0 : 1);
    }
    return 0;
}