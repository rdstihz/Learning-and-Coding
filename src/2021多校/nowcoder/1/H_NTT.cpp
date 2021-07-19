#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 2000000 + 100;
const LL P = 998244353;
const LL g = 3;
LL A[maxn], B[maxn];
int rev[maxn];
bool del[maxn];
LL pow_mod(LL a, LL b, LL p) {
    LL res = 1;
    while (b) {
        if (b & 1)
            res = res * a % P;
        b >>= 1;
        a = a * a % P;
    }
    return res;
}

void NTT(LL* A, int N, int type) {
    for (int i = 0; i < N; i++)
        if (i < rev[i])
            swap(A[i], A[rev[i]]);
    for (int len = 2; len <= N; len <<= 1) {
        int m = len >> 1;
        LL wn = pow_mod(g, (P - 1) / len, P);
        if (type == -1) {
            wn = pow_mod(wn, P - 2, P);
        }
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

void remove(int x) {
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0)
            del[i] = del[x / i] = true;
    }
}

int main() {
    int n, v;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v);
        A[v] = B[500000 - v] = 1;
    }
    int N = 1, l = 0;
    while (N <= 1000000) {
        N <<= 1;
        l++;
    }

    for (int i = 0; i < N; i++)
        rev[i] = rev[i >> 1] >> 1 | (i & 1) << (l - 1);

    NTT(A, N, 1), NTT(B, N, 1);
    for (int i = 0; i < N; i++)
        A[i] = A[i] * B[i] % P;
    NTT(A, N, -1);
    LL aN = pow_mod(N, P - 2, P);
    for (int i = 0; i < N; i++)
        A[i] = A[i] * aN % P;

    for (int i = 500001; i <= 1000000; i++) {
        if (A[i] && !del[i - 500000])
            remove(i - 500000);
    }

    int ans = n;
    while (del[ans])
        ans++;
    printf("%d\n", ans);
    return 0;
}