/*
    Created by rdstihz at 2021-07-23 18:05:54
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 5010;
const LL P = 998244353;

LL f[maxn][maxn];
LL prod[maxn];
int cnt[maxn];
int s[maxn];
int main() {

    int n;
    scanf("%d", &n);
    prod[0] = 1;
    for (int i = 1; i <= n; i++)
        prod[i] = prod[i - 1] * i % P;
    int v;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v);
        cnt[v]++;
    }

    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + cnt[i];

    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        if (!cnt[i]) continue;
        for (int j = 0; j <= s[i] && j <= n / 2 && s[i] - j >= j; j++) {
            for (int k = 0; k <= cnt[i] && k <= j; k++) {
                f[s[i]][j] = (f[s[i]][j] + f[s[i - 1]][j - k]) % P;
            }
        }
    }
    LL ans = f[n][n / 2];
    for (int i = 1; i <= n; i++)
        ans = ans * prod[cnt[i]] % P;
    printf("%lld\n", ans);
    return 0;
}