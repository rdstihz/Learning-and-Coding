#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
const LL P = 998244353;
const LL g = 3;

inline int readIn() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

LL pow_mod(LL a, LL b, LL p) {
    LL res = 1;
    while (b) {
        if (b & 1)
            res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}

LL F[maxn], G[maxn];
LL T[maxn];
int rev[maxn];
void ntt(LL* A, int N, int type) {
    for (int i = 0; i < N; i++)
        if (i < rev[i])
            swap(A[i], A[rev[i]]);

    for (int len = 2; len <= N; len <<= 1) {
        int m = len / 2;
        LL wn = pow_mod(g, (P - 1) / len, P);
        if (type == -1)
            wn = pow_mod(wn, P - 2, P);

        for (int j = 0; j < N; j += len) {
            LL w = 1;
            for (int i = 0; i < m; i++) {
                LL u = A[j + i];
                LL v = A[j + i + m];

                A[j + i] = (u + w * v % P) % P;
                A[j + i + m] = (P + u - w * v % P) % P;
                w = w * wn % P;
            }
        }
    }
}

int main() {
    int n;
    n = readIn();
    n--;

    for (int i = 0; i <= n; i++)
        F[i] = readIn();

    G[0] = pow_mod(F[0], P - 2, P);
    int t = 1;
    //G[x] * F[x] = 1 (mod x^t)
    while (t < n + 1) {
        t <<= 1;
        int N = 1, l = 0;

        while (N <= t) {
            N <<= 1;
            l++;
        }
         
        for (int i = 0; i < N; i++)
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << (l - 1);

        for (int i = 0; i < t; i++)
            T[i] = F[i];
        for (int i = t; i < N; i++)
            T[i] = 0;

        ntt(G, N, 1);
        ntt(T, N, 1);

        for (int i = 0; i < N; i++) {
            G[i] = (2 * G[i] % P - (T[i] * G[i] % P) * G[i] % P + P) % P;
        }

        ntt(G, N, -1);
        LL aN = pow_mod(N, P - 2, P);
        for (int i = 0; i < N; i++) {
            G[i] = G[i] * aN % P;
        }
        for (int i = t; i < N; i++)
            G[i] = 0;
    }

    for (int i = 0; i <= n; i++)
        printf("%lld ", G[i]);
    printf("\n");

    return 0;
}