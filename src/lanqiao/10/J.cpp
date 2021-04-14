#include <iostream>

#include <cmath>

using namespace std;

typedef long long LL;

const LL P = 1e9 + 7;

LL k, K;
LL T;

const int maxn = 200;
LL p[maxn], q[maxn];

void divide(LL x, LL* p) {
    p[0] = 0;

    while (x) {
        p[++p[0]] = x % k;
        x /= k;
    }
}

LL pow_mod(LL a, LL b, LL p) {
    LL res = 1;

    while (b) {
        if (b & 1)
            res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }

    return res % p;
}

LL getnums(LL n, LL m) {

    n++;
    if (n <= m) { // 1 + 2 + 3 + ... + n
        return (n * (n + 1) / 2) % P;
    } else {
        LL res = (m * (m + 1) / 2) % P; // 1 + 2 + 3 + ... + m

        n -= m;
        res = (res + n * (m + 1) % P) % P;
        return res;
    }
}

LL dfs(int pos) {

    if (pos == 0)
        return 1;

    LL t1 = getnums(p[pos], q[pos]);
    LL t2 = min(p[pos], q[pos]) + 1;

    LL res = (t1 - t2) * pow_mod(K, pos - 1, P) % P;
    res = (res + (t2 * dfs(pos - 1)) % P ) % P;

    return res;
}

int main() {

    int T;
    cin >> T >> k;
    K = (k * (k + 1) / 2) % P;

    while (T--) {
        LL n, m;
        cin >> n >> m;
        if (m > n) {
            m = n;
        }
        divide(n, p);
        divide(m, q);


        LL res = dfs(p[0]);

        LL total = getnums(n, m);

        LL ans = (total + P - res) % P;
        cout << ans << endl;
    }

    return 0;
}