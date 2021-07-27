#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2000000 + 100;
const LL P = 998244353;
const LL g = 3;

char S[maxn], T[maxn];
LL A[maxn], B[maxn], C[maxn];
LL a[maxn], b[maxn];
int rev[maxn];

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

int main() {
    int n, m;
    scanf("%d%d", &m, &n);
    scanf("%s%s", T, S);

    for (int i = 0; i < n; i++) {
        a[i] = S[i] == '*' ? 0 : (S[i] - 'a' + 1);
    }
    for (int i = 0; i < m; i++)
        b[m - i - 1] = T[i] == '*' ? 0 : (T[i] - 'a' + 1);

    int N = 1, l = 0;
    while (N <= n + m - 2) {
        N <<= 1;
        l++;
    }
    for (int i = 0; i < N; i++)
        rev[i] = rev[i >> 1] >> 1 | (i & 1) << (l - 1);
    LL aN = pow_mod(N, P - 2, P);
    for (int i = 0; i < n; i++)
        A[i] = a[i] * a[i] * a[i];
    for (int i = n; i < N; i++)
        A[i] = 0;
    for (int i = 0; i < m; i++)
        B[i] = b[i];
    for (int i = m; i < N; i++)
        B[i] = 0;
    NTT(A, N, 1);
    NTT(B, N, 1);
    for (int i = 0; i < N; i++)
        A[i] = A[i] * B[i] % P;
    NTT(A, N, -1);
    for (int i = 0; i < N; i++)
        C[i] = (C[i] + A[i] * aN % P) % P;

    for (int i = 0; i < n; i++)
        A[i] = a[i];
    for (int i = n; i < N; i++)
        A[i] = 0;
    for (int i = 0; i < m; i++)
        B[i] = b[i] * b[i] * b[i];
    for (int i = m; i < N; i++)
        B[i] = 0;
    NTT(A, N, 1);
    NTT(B, N, 1);
    for (int i = 0; i < N; i++)
        A[i] = A[i] * B[i] % P;
    NTT(A, N, -1);
    for (int i = 0; i < N; i++)
        C[i] = (C[i] + A[i] * aN % P) % P;

    for (int i = 0; i < n; i++)
        A[i] = a[i] * a[i];
    for (int i = n; i < N; i++)
        A[i] = 0;
    for (int i = 0; i < m; i++)
        B[i] = b[i] * b[i];
    for (int i = m; i < N; i++)
        B[i] = 0;
    NTT(A, N, 1);
    NTT(B, N, 1);
    for (int i = 0; i < N; i++)
        A[i] = A[i] * B[i] % P;
    NTT(A, N, -1);
    for (int i = 0; i < N; i++)
        C[i] += (P - 2 * A[i] * aN % P) % P;

    for (int i = 0; i < N; i++)
        C[i] %= P;

    vector<int> ans;
    for (int i = 0; i <= n - m; i++)
        if (C[i + m - 1] == 0)
            ans.push_back(i);

    printf("%d\n", ans.size());
    for (int v : ans)
        printf("%d ", v + 1);
    printf("\n");
    return 0;
}