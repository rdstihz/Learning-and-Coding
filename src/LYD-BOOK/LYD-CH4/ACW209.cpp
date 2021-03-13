#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 510;
const double eps = 1e-6;

long double a[maxn][maxn];
int c[maxn];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        cin >> c[i];

    int cnt = 0;
    int val = 0;

    for (int i = 1; i <= m; i++) {

        bool find = false;
        int pos = 0, pri = 1 << 30;
        for (int j = cnt + 1; j <= n; j++)
            if (fabs(a[j][i]) > eps && c[j] < pri) {
                pos = j;
                pri = c[j];
                find = true;
            }

        if (find) {
            cnt++;
            val += pri;
        } else {
            continue;
        }

        for (int k = 1; k <= m; k++)
            swap(a[cnt][k], a[pos][k]);
        swap(c[cnt], c[pos]);

        for (int j = 1; j <= n; j++) {
            if (cnt == j) continue;
            double t = a[j][i] / a[cnt][i];
            for (int k = 1; k <= m; k++)
                a[j][k] -= a[cnt][k] * t;
        }
    }

    cout << cnt << " " << val << endl;

    return 0;
}