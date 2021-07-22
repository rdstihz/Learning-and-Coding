#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 40000 + 100;
const int maxv = 80000 + 10;
const LL PP = 100000000000031;

char buf[1 << 20], *p1 = buf, *p2 = buf;
char get() {
    if (p1 == p2) {
        p1 = buf;
        p2 = buf + std::fread(buf, 1, 1 << 20, stdin);
    }
    if (p1 == p2) {
        return EOF;
    }
    return *p1++;
}

template <typename T>
void readIn(T& x) {
    x = 0;
    char c = get();
    while (c < '0' || c > '9')
        c = get();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = get();
    }
}

int n, k;
LL P;
int x[maxn];
LL f[maxv], fp[maxv];
LL C[maxn][32], Cp[maxn][32];
vector<int> primes;
bool flag[10000000 + 10];

void init() {
    //1e7以内的质数
    int N = 10000000;
    for (int i = 2; i <= N; i++) {
        if (!flag[i])
            primes.push_back(i);
        for (int j = 0; j < primes.size() && i * primes[j] <= N; j++) {
            flag[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

LL get_phi(LL P) {
    LL ans = P;
    for (int v : primes) {
        if (P % v == 0) {
            ans = ans / v * (v - 1);
            while (P % v == 0)
                P /= v;
        }
    }
    if (P > 1)
        ans = ans / P * (P - 1);
    return ans;
}

LL mul(LL a, LL b, LL p) {
    return (__int128)a * b % p;
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
    readIn(T);
    init();

    Cp[0][0] = 1;
    for (int i = 1; i <= 40000; i++) {
        Cp[i][0] = 1;
        for (int j = 1; j <= min(i, 30); j++) {
            Cp[i][j] = (Cp[i - 1][j] + Cp[i - 1][j - 1]) % PP;
        }
    }

    while (T--) {
        readIn(n), readIn(k), readIn(P);

        int mx = 0;
        for (int i = 1; i <= n; i++) {
            readIn(x[i]);
            mx = max(x[i], mx);
        }

        LL phi = get_phi(P);
        //预处理组合数
        C[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= min(i, k); j++) {
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % phi;
            }
        }

        for (int i = 1; i <= mx; i++)
            f[i] = 0;

        for (int i = 1; i <= n; i++)
            f[x[i]]++;

        for (int i = 1; i <= mx; i++) {
            for (int j = 2 * i; j <= mx; j += i)
                f[i] += f[j];
        }

        for (int i = 1; i <= mx; i++) {
            fp[i] = Cp[f[i]][k];
            f[i] = C[f[i]][k];
        }
        for (int i = mx; i >= 1; i--) {
            for (int j = 2 * i; j <= mx; j += i) {
                f[i] -= f[j];
                if (f[i] < 0) f[i] += phi;
                fp[i] -= f[j];
                if (fp[i] < 0) fp[i] += PP;
            }
        }

        LL ans = 1;
        for (int i = 1; i <= mx; i++) {
            if (f[i] != fp[i])
                f[i] += phi;
            ans = mul(ans, pow_mod(i, f[i], P), P);
        }

        printf("%lld\n", ans);
    }
}