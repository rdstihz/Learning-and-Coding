#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL P = 998244353;
LL bsgs(LL a, LL b, LL p) {
    b %= p;
    unordered_map<LL, LL> hash;
    LL t = sqrt(p) + 1;
    LL x = 1;
    for (LL j = 0; j < t; j++) {
        LL val = b * x % p;
        hash[val] = j;
        x = x * a % p;
    }
    hash[b * x % p] = t;
    a = x;
    for (LL i = 1; i <= t; i++) {
        if (hash.count(x)) {
            return i * t - hash[x];
        }
        x = x * a % p;
    }
    return -1;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        LL n, x;
        scanf("%lld%lld", &n, &x);
        LL b1 = (x * n % P + (n - 1)) % P;
        LL b2 = (x * n % P + P - (n - 1)) % P;

        LL t1 = bsgs(n - 1, b1, P);
        LL t2 = bsgs(n - 1, b2, P);

        if (t1 % 2 == 1 && t2 % 2 == 0)
            printf("%lld\n", min(t1, t2));
        else if (t1 % 2 == 1)
            printf("%lld\n", t1);
        else if (t2 % 2 == 0)
            printf("%lld\n", t2);
        else
            printf("-1\n");
    }

    return 0;
}