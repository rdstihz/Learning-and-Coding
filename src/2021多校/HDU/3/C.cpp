#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL P = 998244353;
const LL g = 3;
const int maxn = 1000000 + 100;

char S[200000 + 10], T[200000 + 10];
LL A[maxn], B[maxn], C[maxn];

int val[maxn], cnt[maxn];
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

void NTT(LL* A, int N, int type) {
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

    int TT;
    scanf("%d", &TT);
    while (TT--) {
        int n, m;
        scanf("%d%d", &n, &m);
        scanf("%s%s", S, T);

        int N = 1, l = 0;
        while (N <= n + m) {
            N <<= 1;
            l++;
        }
        for (int i = 0; i < N; i++)
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << (l - 1);

        for (int i = 0; i <= n - m; i++)
            val[i] = 0;
        for (int i = 0; i <= m; i++)
            cnt[i] = 0;

        for (char ch = '0'; ch <= '9'; ch++) {
            for (int i = 0; i < n; i++)
                A[i] = S[i] == ch || S[i] == '*';
            for (int i = n; i < N; i++)
                A[i] = 0;

            for (int i = 0; i < m; i++)
                C[i] = T[i] == ch;
            for (int i = m; i < N; i++)
                C[i] = 0;

            for (int i = 1; i <= m; i++)
                B[i] = C[m - i];
            for (int i = m + 1; i < N; i++)
                B[i] = 0;
            B[0] = 0;

            NTT(A, N, 1);
            NTT(B, N, 1);

            for (int i = 0; i < N; i++)
                A[i] = A[i] * B[i] % P;

            NTT(A, N, -1);

            LL aN = pow_mod(N, P - 2, P);
            for (int i = 0; i < N; i++)
                A[i] = A[i] * aN % P;
            
            // for (int i = 0; i <= n - m; i++)
            //     printf("%d ", A[i + m]);
            // printf("\n");

            for (int i = 0; i <= n - m; i++)
                val[i] += A[i + m];
        }

        int xing = 0;
        for (int i = 0; i < m; i++)
            if (T[i] == '*') xing++;

        for (int i = 0; i <= n - m; i++)
            cnt[xing + val[i]]++;

        int ans = 0;
        for (int i = 0; i <= m; i++) {
            ans += cnt[m - i];
            printf("%d\n", ans);
        }
    }

    return 0;
}