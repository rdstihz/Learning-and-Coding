#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int maxn = 100000 + 100;
const LL P = 998244353;
const LL g = 3;

int v;

LL a[maxn], b[maxn], bak[maxn];
int rev[maxn];
int n, m;

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

void ntt(LL* A, int N, int type) {
    for (int i = 0; i < N; i++)
        if (i < rev[i])
            swap(A[i], A[rev[i]]);

    for (int len = 2; len <= N; len <<= 1) {
        LL wn = pow_mod(g, (P - 1) / len, P);
        if (type == -1)
            wn = pow_mod(wn, P - 2, P);
        int m = len / 2;
        for (int j = 0; j < N; j += len) {
            LL w = 1;

            for (int i = 0; i < m; i++) {
                LL u = A[j + i];
                LL v = A[j + i + m];

                A[j + i] = (u + w * v % P) % P;
                A[j + i + m] = (u + P - w * v % P) % P;

                w = w * wn % P;
            }
        }
    }
}

void mul(LL* a, LL* b, int& n, int& m) {

    int N = 1, l = 0;
    while (N < n + m + 1) {
        N <<= 1;
        l++;
    }

    for (int i = 0; i < N; i++)
        rev[i] = rev[i >> 1] >> 1 | (i & 1) << (l - 1);

    ntt(a, N, 1);
    if (a != b) {
        memcpy(bak, b, sizeof(bak));
        ntt(b, N, 1);
    }

    LL aN = pow_mod(N, P - 2, P);

    for (int i = 0; i < N; i++)
        a[i] = a[i] * b[i] % P;

    ntt(a, N, -1);
    if (a != b) {
        memcpy(b, bak, sizeof(bak));
    }

    for (int i = 0; i < N; i++)
        a[i] = a[i] * aN % P;

    for (int i = 0; i < N; i++) {
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    n = N;
    while (!a[n])
        n--;
}

void work() {
    a[0] = 2;
    b[0] = 2;

    n = m = 0;

    while (v) {
        if (v & 1)
            mul(a, b, n, m);
        mul(b, b, m, m);
        v >>= 1;
    }
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        n = m = 0;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));

        scanf("%d", &v);
        work();
        //除以3
        int r = 0;
        for (int i = n; i >= 0; i--) {
            a[i] += 10 * r;
            r = a[i] % 3;
            a[i] /= 3;
        }
        while (!a[n])
            n--;
        for (int i = n; i >= 0; i--)
            putchar(a[i] + '0');
        putchar('\n');
    }

    return 0;
}