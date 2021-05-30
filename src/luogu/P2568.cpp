#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 10000000 + 10;

typedef long long LL;

LL mu[maxn];

int primes[maxn], tot;
bool flag[maxn];

void init(int N) {
    mu[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!flag[i]) {
            primes[++tot] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= tot && i * primes[j] <= N; j++) {
            flag[i * primes[j]] = true;
            mu[i * primes[j]] = -mu[i];
            if (i % primes[j] == 0) {
                mu[i * primes[j]] = 0;
                break;
            }
        }
    }
    for (int i = 1; i <= N; i++)
        mu[i] += mu[i - 1];
}

int main() {

    int N;
    scanf("%d", &N);
    init(N);

    // for(int i = 1; i <= 10; i++)
    //     printf("%lld\n", mu[i]);

    LL res = 0;
    for (int i = 1; i <= tot; i++) {
        int n = N / primes[i];
        for (int x = 1, y; x <= n; x = y + 1) {
            y = min(n, n / (n / x));
            res += (mu[y] - mu[x - 1]) * (n / x) * (n / x);
        }
        
    }
    printf("%lld\n", res);

    return 0;
}