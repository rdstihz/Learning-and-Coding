#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 10000000 + 10;
bool flag[maxn];
int primes[maxn], tot;
LL S[maxn];
void init() {
    int N = 10000000;
    for (int i = 2; i <= N; i++) {
        if (!flag[i]) {
            primes[++tot] = i;
        }
        for (int j = 1; j <= tot && i * primes[j] <= N; j++) {
            flag[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
    for (int i = 1; i <= tot; i++) {
        S[i] = S[i - 1] + primes[i];
    }
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        int i = upper_bound(primes + 1, primes + 1 + tot, n) - primes - 1;
        //printf("%d %lld\n", i, S[i]);
        long long  ans = S[i] - 2 + 1ll * (n - 2) * (n + 3) / 2;
        printf("%lld\n", ans);
    }
    return 0;
}