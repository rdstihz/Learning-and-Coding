#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = (1 << 18) + 20;
const LL P = 998244353;
int a[maxn], b[maxn];
int maxa[maxn], mina[maxn], maxb[maxn], minb[maxn];
LL c[maxn];

int readInt() {

    int x = 0;
    int flag = 1;
    char c = getchar();
    while (c != '-' && (c < '0' || c > '9'))
        c = getchar();
    if (c == '-') flag = -1, c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * flag;
}

int main() {
    //freopen("1.in", "r", stdin);
    int T;
    T = readInt();
    while (T--) {
        int n;
        n = readInt();
        for (int i = 0; i < n; i++)
            a[i] = readInt();
        for (int i = 0; i < n; i++)
            b[i] = readInt();

        for (int i = 0; i < n; i++) {
            maxa[i] = mina[i] = a[i];
            maxb[i] = minb[i] = b[i];
        }
        for (int i = 0; (1 << i) <= n; i++) {
            for (int S = 0; S < n; S++) {
                if ((!(S >> i & 1)) && (S ^ (1 << i)) < n) {
                    maxa[S] = max(maxa[S], maxa[S ^ (1 << i)]);
                    mina[S] = min(mina[S], mina[S ^ (1 << i)]);
                    maxb[S] = max(maxb[S], maxb[S ^ (1 << i)]);
                    minb[S] = min(minb[S], minb[S ^ (1 << i)]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            c[i] = max(max((LL)maxa[i] * maxb[i], (LL)mina[i] * minb[i]), max((LL)maxa[i] * minb[i], (LL)mina[i] * maxb[i]));
        }
        for (int i = n - 2; i >= 0; i--)
            c[i] = max(c[i], c[i + 1]);
        LL ans = 0;
        for (int i = 0; i < n; i++)
            ans = ((ans + c[i]) % P + P) % P;
        printf("%lld\n", ans);
    }

    return 0;
}