#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 200000 + 10;

int w[maxn], v[maxn];
int l[maxn], r[maxn];
int n, m;
LL s;

int cnt[maxn];
LL sum[maxn];

LL calc(int x) {
    for (int i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1] + (w[i] >= x);
        sum[i] = sum[i - 1] + (w[i] >= x) * v[i];
    }
    LL res = 0;

    for (int i = 1; i <= m; i++)
        res += (sum[r[i]] - sum[l[i] - 1]) * (cnt[r[i]] - cnt[l[i] - 1]);

    return res;
}

int main() {

    cin >> n >> m >> s;

    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    for (int i = 1; i <= m; i++)
        cin >> l[i] >> r[i];

    int L = 0, R = 1000000;
    int M;

    while (L < R) {
        M = (L + R + 1) >> 1;
        if (calc(M) < s)
            R = M - 1;
        else
            L = M;
    }
    LL t = calc(L);
    if (t < s)
        cout << s - t << endl;
    else {
        LL ans = min(t - s, s - calc(L + 1));
        cout << ans << endl;
    }

    return 0;
}