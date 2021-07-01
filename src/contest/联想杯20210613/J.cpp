#include <bits/stdc++.h>

using namespace std;

const int maxn = 20000000 + 10;

int primes[1000000], tot;
int p1[maxn], a1[maxn], pa[maxn];
bool flag[maxn];

void init(int n) {
    for (int i = 2; i <= n; i++) {
        if (!flag[i]) {
            primes[++tot] = i;

            p1[i] = i;
            a1[i] = 1;
            pa[i] = i;
        }

        for (int j = 1; j <= tot && i * primes[j] <= n; j++) {
            int t = i * primes[j];
            flag[t] = true;

            p1[t] = primes[j];
            a1[t] = 1;
            pa[t] = primes[j];

            if (i % primes[j] == 0) {
                a1[t] = a1[i] + 1;
                pa[t] = pa[i] * primes[j];
                break;
            }
        }
    }
}

int pow_mod(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a;
        b >>= 1;
        a = a * a;
    }
    return res;
}

int main() {

    int n, m, L;
    scanf("%d%d%d", &n, &m, &L);
    init(L + n);
    long long ans = 0;
    for (int i = L + 1; i <= L + n; i++) {
        ans += i - i / pa[i] * pow_mod(p1[i], a1[i] / m);
    }
    printf("%lld\n", ans);
    return 0;
}