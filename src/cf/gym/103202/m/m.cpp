/*
    Created by rdstihz at 2021-10-08 19:24:15
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = (1 << 20) + 100;
char str[maxn];

LL f[maxn];

void fwt(LL* a, int N, int type) {
    for (int o = 2, k = 1; o <= N && k <= N; o <<= 1, k <<= 1) {
        for (int i = 0; i < N; i += o)
            for (int j = 0; j < k; j++) {
                LL x = a[i + j], y = a[i + j + k];
                a[i + j] = (x + y) / type;
                a[i + j + k] = (x - y) / type;
            }
    }
}

int main() {
    LL n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%s", str);
        int state = 0;
        for (int j = 0; j < m; j++)
            if (str[j] == 'B')
                state |= 1 << j;

        f[state]++;
    }
    fwt(f, 1 << m, 1);
    for (int i = 0; i < (1 << m); i++)
        f[i] *= f[i];
    fwt(f, 1 << m, 2);
    for (int i = 0; i < (1 << m); i++)
        f[i] /= 2;

    for (int i = 0; i < m; i++)
        for (int s = 0; s < (1 << m); s++)
            if (s & (1 << i))
                f[s] += f[s ^ (1 << i)];

    LL ans = 0;
    for (int s = 0; s < (1 << m); s++)
        if (n * n - 2 * f[s] >= 2 * k)
            ans++;
    printf("%lld\n", ans);
    return 0;
}