#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef long long LL;

const int maxn = 50;
LL w, g[maxn];
int n;
int weigs[(1 << 24) + 3];
int tot;

int mid;
LL ans;

void dfs1(int d, LL sum) {
    if (d > mid) {
        weigs[++tot] = sum;
        return;
    }

    if (sum + g[d] <= w) dfs1(d + 1, sum + g[d]);
    dfs1(d + 1, sum);
}

void dfs2(int d, LL sum) {
    if (d > n) {
        int x = upper_bound(weigs + 1, weigs + 1 + tot, w - sum) - weigs - 1;
        if (x) {
            ans = max(ans, sum + weigs[x]);
        }
        return;
    }
    if (sum + g[d] <= w)
        dfs2(d + 1, sum + g[d]);
    dfs2(d + 1, sum);
}

int main() {

    cin >> w >> n;
    for (int i = 1; i <= n; i++) {
        cin >> g[i];
    }
    mid = (n + 1) / 2;
    sort(g + 1, g + 1 + n, greater<LL>());

    dfs1(1, 0);
    sort(weigs + 1, weigs + 1 + tot);
    
    dfs2(mid + 1, 0);

    cout << ans << endl;

    return 0;
}
