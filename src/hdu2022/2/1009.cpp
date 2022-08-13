#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int maxn = 2000000 + 100;

void solve() {
    LL p, q, e;
    scanf("%lld%lld%lld", &p, &q, &e);

    LL t = p * q - 1;
    for(LL i = 2; i * i <= t; i++) {
        while(t % i == 0) t /= i;
    }

    if(t <= p || t <= q) {
        printf("shuanQ\n");
    }else {
        printf("%lld\n", e * q % t );
        //printf("%lld\n", t);
    }

}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}