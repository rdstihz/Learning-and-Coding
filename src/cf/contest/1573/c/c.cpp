/*
    Created by rdstihz at 2021-11-05 14:50:37
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;

vector<int> G[maxn];
int deg[maxn];
int q[maxn], s[maxn];
int dp[maxn];

void solve() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        G[i].clear();
        deg[i] = 0;
    }

    int k, x;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &x);
            G[i].push_back(x);
            deg[x]++;
        }
    }
    int l = 0, r = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!deg[i])
            q[++r] = i;
    }
    while (l < r) {
        int u = q[++l];
        s[++cnt] = u;
        for (int v : G[u]) {
            deg[v]--;
            if (!deg[v]) {
                q[++r] = v;
            }
        }
    }

    if (cnt < n) {
        printf("-1\n");
        return;
    }
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        dp[s[i]] = 1;
        for (int v : G[s[i]]) {
            dp[s[i]] = max(dp[s[i]], dp[v] + (v > s[i]));
        }
        ans = max(ans, dp[s[i]]);
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}