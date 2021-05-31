#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000000 + 10;
bool flag[maxn];
int primes[maxn], tot;
int phi[maxn];

void init() {
    int N = 1000000;
    phi[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!flag[i]) {
            primes[++tot] = i;
            phi[i] = i - 1;
        }

        for (int j = 1; j <= tot && i * primes[j] <= N; j++) {
            flag[i * primes[j]] = true;
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
            if (i % primes[j] == 0) {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
        }
    }
}

long long get_phi(long long n) {
    if (n <= 1000000) return phi[n];
    long ans = n;
    for (int i = 1; i <= tot && primes[i] <= n; i++) {
        int t = primes[i];
        if (n % t == 0) {
            ans = ans / t * (t - 1);
            while (n % t == 0)
                n /= t;
        }
    }
    if (n > 1)
        ans = ans / n * (n - 1);
    return ans;
}

int main() {

    init();
    long long n;
    cin >> n;

    long long ans = 0;
    for (long long d = 1; d * d <= n; d++)
        if (n % d == 0) {
            ans += d * get_phi(n / d);
            if (d * d != n) ans += n / d * get_phi(d);
        }

    cout << ans << endl;

    return 0;
}