#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 105;

int f[103][103][210];

int a[120], b[120];
int w[120];

int q[120];

bool cmp(int x, int y) {
    return a[x] < a[y];
}

int main() {
    int n, k;
    cin >> n >> k;

    int temp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        q[i] = i;
    }
    sort(q + 1, q + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        w[i] = b[q[i]];
    }
    // for(int i = 1; i <= n; i++)
    //     cout << w[i] << " ";
    // cout << endl;
    memset(f, 0x3f, sizeof(f));

    for (int i = 0; i <= 200; i++)
        f[0][0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {

            for (int t = 0; t <= 200; t++) {
                f[i][j][w[i]] = min(f[i - 1][j][t] + abs(w[i] - t), f[i][j][w[i]]);
                if (j >= 1)
                    f[i][j][t] = min(f[i][j][t], f[i - 1][j - 1][t]);
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= 200; i++)
        ans = min(ans, f[n][k][i]);
    cout << ans << endl;
    return 0;
}