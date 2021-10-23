#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 5000000 + 10;

LL P, inv2, inv6;
LL phi[maxn], S[maxn];
int primes[maxn], tot;
bool flag[maxn];
map<int, LL> mp;

LL pow_mod(LL a, LL b, LL p) {
    LL res = 1;
    while(b) {
        if(b & 1)
            res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}

void init() {
    phi[1] = 1;
    for(int i = 2; i < maxn; i++) {
        if(!flag[i]) {
            primes[++tot] = i;
            phi[i] = i - 1;
        }
        for(int j = 1; j <= tot && i * primes[j] < maxn; j++) {
            flag[i * primes[j]] = true;
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
            if(i % primes[j] == 0) {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
        }
    }
    for(int i = 1; i < maxn; i++)
        phi[i] = phi[i] * i % P * i % P;
    for(int i = 1; i < maxn; i++)
        S[i] = (S[i - 1] + phi[i]) % P;
    inv2 = pow_mod(2, P - 2, P);
    inv6 = pow_mod(6, P - 2, P);
}

LL trsum(LL n) { // 1^3 + 2^3 + ... + n^3
    n %= P;
    LL res = n * (n + 1) % P * inv2 % P;
    res = res * res % P;
    return res;
}
LL sqsum(LL n) { // 1^2 + 2^2 + ... + n^2
    n %= P;
    return n * (n + 1) % P * (2 * n + 1) % P * inv6 % P;
}

LL get_S(LL n) {
    if(n < maxn) return S[n];
    if(mp.count(n)) return mp[n];
    LL res = trsum(n);
    for(LL x = 2, y; x <= n; x = y + 1) {
        y = min(n, n / (n / x));
        LL t = (sqsum(y) - sqsum(x - 1) + P) % P * get_S(n / x) % P;
        res = (res - t + P) % P;
    }
    return mp[n] = res;
}



int main() {
    long long n;
    scanf("%lld%lld", &P, &n);
    init();
    LL res = 0;
    for(LL x = 1, y; x <= n; x = y + 1) {
        y = min(n, n / (n / x));
        res = (res + trsum(n / x) * ((get_S(y) - get_S(x - 1) + P) % P ) % P) % P; 
    }
    printf("%lld\n", res);
    return 0;
}