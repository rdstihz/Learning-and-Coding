/*
    Created by rdstihz at 2021-11-04 17:40:49
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL P = 998244353;
const LL g = 3;
const int maxn = 1000000 + 100;

LL F[maxn], G[maxn];
LL fac[maxn], afac[maxn];
int rev[maxn];
LL pow_mod(LL a, LL b, LL p) {
    a %= p;
    LL res = 1;
    while (b) {
        if (b & 1)
            res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}

void init() {
    int n = 100000 + 100;
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % P;
    afac[n] = pow_mod(fac[n], P - 2, P);
    for (int i = n - 1; i >= 0; i--)
        afac[i] = afac[i + 1] * (i + 1) % P;
}

void NTT(LL* A, int N, int type) {
    for (int i = 0; i < N; i++)
        if (rev[i] < i)
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

int main() {
    init();
    int n;
    LL m;
    scanf("%d%lld", &n, &m);
    LL x;
    for (int i = 0; i <= n; i++) {
        scanf("%lld", &x);
        F[n - i] = fac[i] * x % P;
        G[i] = afac[i];
    }

    int N = 1, l = 0;
    while (N < 2 * n + 1) {
        N <<= 1;
        l++;
    }
    LL aN = pow_mod(N, P - 2, P);
    for (int i = 0; i < N; i++)
        rev[i] = rev[i >> 1] >> 1 | (i & 1) << (l - 1);
    NTT(F, N, 1);
    NTT(G, N, 1);
    for (int i = 0; i < N; i++)
        G[i] = (G[i] * F[i]) % P;
    NTT(G, N, -1);
    for (int i = 0; i < N; i++)
        G[i] = G[i] * aN % P;

    for (int i = 0; i <= n; i++)
        G[n - i] = G[n - i] * pow_mod(pow_mod(i + 1, m, P), P - 2, P) % P;
    for (int i = n + 1; i < N; i++)
        G[i] = 0;
    for (int i = 0; i <= n; i++) {
        F[i] = afac[i] * (i % 2 == 0 ? 1 : (P - 1)) % P;
    }
    for (int i = n + 1; i < N; i++)
        F[i] = 0;
    NTT(F, N, 1);
    NTT(G, N, 1);

    for (int i = 0; i < N; i++)
        F[i] = (F[i] * G[i]) % P;
    NTT(F, N, -1);
    for (int i = 0; i < N; i++)
        F[i] = F[i] * aN % P;

    for (int i = 0; i <= n; i++) {
        printf("%lld%c", (F[n - i] * afac[i] % P + P) % P, i == n ? '\n' : ' ');
    }

    return 0;
}