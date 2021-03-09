#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 10000 + 10;
const int INF = 0x3f3f3f3f;

int x[maxn], y[maxn];
int l[maxn], h[maxn];

int f[maxn][1010];
bool pipe[maxn];

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i <= n; i++) {
        l[i] = 1;
        h[i] = m;
    }
    int p, a, b;
    for (int i = 1; i <= k; i++) {
        cin >> p >> a >> b;
        l[p] = a + 1;
        h[p] = b - 1;
        pipe[p] = true;
    }

    memset(f, 0x3f, sizeof(f));

    for (int i = 1; i <= m; i++)
        f[0][i] = 0;

    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int j = l[i]; j <= h[i]; j++) {
            if (f[i][j] != INF) {
                ok = true;

                //下落
                if (j - y[i] >= l[i + 1] && j - y[i] <= h[i + 1]) {
                    f[i + 1][j - y[i]] = min(f[i + 1][j - y[i]], f[i][j]);
                }

                //上
                for (int k = 1;; k++) {
                    int t = j + x[i] * k;
                    if (h[i + 1] == m && t > m) {
                        t = m;
                        f[i + 1][t] = min(f[i + 1][t], f[i][j] + k);
                        break;
                    }

                    if (t < l[i + 1]) continue;
                    if (t > h[i + 1]) break;

                    f[i + 1][t] = min(f[i + 1][t], f[i][j] + k);
                }
            }
        }

        if (!ok) {
            cout << 0 << endl;
            int cnt = 0;
            for(int j = 0; j < i; j++)
                cnt += pipe[j];
            cout << cnt << endl;
            return 0;
        }
    }

    int ans = INF;
    for (int j = 1; j <= m; j++)
        ans = min(ans, f[n][j]);

    if (ans == INF) {
        cout << 0 << endl
             << k - 1 << endl;
    } else {
        cout << 1 << endl
             << ans << endl;
    }

    return 0;
}