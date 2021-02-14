#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long LL;
const int maxn = 1000000 + 100;

int tprime[maxn], tot, flag[maxn];
int prime[maxn], n;

void init() {
    int N = 100000;
    for (int i = 2; i <= N; i++) {
        if (!flag[i]) {
            tprime[++tot] = i;
        }
        for (int j = 1; j <= tot && i * tprime[j] <= N; j++) {
            flag[i * tprime[j]] = true;
            if (i % tprime[j] == 0) break;
        }
    }
}

int main() {
    init();

    LL l, r;
    while (~scanf("%lld%lld", &l, &r)) {
        l--;
        memset(flag, 0, sizeof(flag));
        n = 0;

        for (int i = 1; i <= tot && tprime[i] <= sqrt(r); i++) {
            LL t = tprime[i];
            for (LL j = max(t, l / t + 1); t * j <= r; j++) {
                flag[t * j - l] = true;
            }
        }
        if(!l) flag[1] = true;

        for (int i = 1; l + i <= r; i++)
            if (!flag[i])
                prime[++n] = l + i;

        if (n < 2) {
            printf("There are no adjacent primes.\n");
        } else {
            int mind = maxn, a, b;
            int maxd = 0, c, d;
            for (int i = 1; i < n; i++) {
                if (prime[i + 1] - prime[i] < mind) {
                    mind = prime[i + 1] - prime[i];
                    a = prime[i];
                    b = prime[i + 1];
                }
                if (prime[i + 1] - prime[i] > maxd) {
                    maxd = prime[i + 1] - prime[i];
                    c = prime[i];
                    d = prime[i + 1];
                }
            }
            printf("%d,%d are closest, %d,%d are most distant.\n", a, b, c, d);
        }
    }
}
