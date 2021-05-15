#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const LL P = 998244353;
const LL g = 3;
const int maxn = 300000 + 100;

LL a[maxn], b[maxn], c[maxn], d[maxn];
LL invb[maxn];
int rev[maxn];

int readIn() {
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
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

const LL inv2 = pow_mod(2, P - 2, P);

void NTT(LL* A, int N, int type) {
    for (int i = 0; i < N; i++)
        if (i < rev[i])
            swap(A[i], A[rev[i]]);

    for (int len = 2; len <= N; len <<= 1) {
        int m = len >> 1;
        LL wn = pow_mod(g, (P - 1) / len, P);
        if (type == -1)
            wn = pow_mod(wn, P - 2, P);
        for (int j = 0; j < N; j += len) {
            LL w = 1;
            for (int i = 0; i < m; i++) {
                LL u = A[j + i];
                LL v = A[j + i + m];

                A[j + i] = (u + w * v % P) % P;
                A[j + i + m] = (u - w * v % P + P) % P;

                w = w * wn % P;
            }
        }
    }
}

void Inv(LL* a, LL* b, int n) {
    memset(b, 0, 8 * maxn);
    b[0] = pow_mod(a[0], P - 2, P);
    int t = 1;
    int N, l = 1;
    while (t < n) {
        t <<= 1;
        N = t << 1;
        l++;

        for (int i = 0; i < N; i++)
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << (l - 1);

        for (int i = 0; i < n; i++)
            c[i] = a[i];
        for (int i = t; i < N; i++)
            c[i] = 0;

        NTT(b, N, 1), NTT(c, N, 1);

        for (int i = 0; i < N; i++)
            b[i] = (2 * b[i] % P - c[i] * b[i] % P * b[i] % P + P) % P;

        NTT(b, N, -1);
        LL aN = pow_mod(N, P - 2, P);
        for (int i = 0; i < n; i++)
            b[i] = b[i] * aN % P;
        for (int i = t; i < N; i++)
            b[i] = 0;
    }
}

void Sqrt(LL* a, LL* b, int n) {
    memset(b, 0, 8 * maxn);
    b[0] = 1;
    int t = 1;
    int N, l = 1;

    while (t < n) {
        Inv(b, invb, t << 1);

        
        t <<= 1;
        N = t << 1;
        l++;

        for (int i = 0; i < N; i++)
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << (l - 1);

        for (int i = 0; i < t; i++)
            d[i] = a[i];
        for (int i = t; i < N; i++)
            d[i] = b[i] = invb[i] = 0;


        NTT(invb, N, 1);
        NTT(d, N, 1);
        NTT(b, N, 1);

        for (int i = 0; i < N; i++) {
            b[i] = (d[i] * invb[i] % P + b[i]) % P;
            b[i] = b[i] * inv2 % P;
        }

        NTT(b, N, -1);
        LL aN = pow_mod(N, P - 2, P);

        for (int i = 0; i < t; i++)
            b[i] = b[i] * aN % P;
        for (int i = t; i < N; i++)
            b[i] = 0;
    }
}

int main() {
    int n;
    n = readIn();

    for (int i = 0; i < n; i++)
        a[i] = readIn();

    Sqrt(a, b, n);

    for (int i = 0; i < n; i++)
        printf("%lld ", b[i]);
    printf("\n");

    return 0;
}