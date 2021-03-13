#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 300000 + 100;

LL a[maxn];

int q[maxn], l, r;
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    l = r = 0;
    q[++r] = 0;
    LL ans = -1e18;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, a[i] - a[q[l + 1]]);

        while (r > l && a[q[r]] > a[i]) r--;
        q[++r] = i;

        if (q[l + 1] <= i - m) l++;

    }
    cout << ans << endl;
    return 0;
}