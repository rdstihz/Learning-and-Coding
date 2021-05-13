#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long LL;

const LL P = 998244353;
const LL g = 3;
const int maxn = 300000 + 100;

int n, m, N, l;

LL a[maxn], b[maxn];
int rev[maxn];

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

void fft(LL* A, int N, int type) {
    for (int i = 0; i < N; i++)
        if (rev[i] < i)
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
                A[j + i + m] = (u - w * v % P + P) % P;

                w = w * wn % P;
            }
        }
    }
}

int main() {

    scanf("%d%d", &n, &m);

    for (int i = 0; i <= n; i++)
        scanf("%lld", a + i);
    for (int i = 0; i <= m; i++)
        scanf("%lld", b + i);

    N = 1, l = 0;
    while (N < n + m + 1) {
        N <<= 1;
        l++;
    }

    for (int i = 0; i < N; i++)
        rev[i] = rev[i >> 1] >> 1 | (i & 1) << (l - 1);

    fft(a, N, 1);
    fft(b, N, 1);

    for (int i = 0; i < N; i++)
        a[i] = a[i] * b[i] % P;

    fft(a, N, -1);

    LL aN = pow_mod(N, P - 2, P);

    for (int i = 0; i <= n + m; i++)
        printf("%lld ", a[i] * aN % P);

    return 0;
}
