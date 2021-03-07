#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 70;
int v[maxn], p[maxn], q[maxn];

int app[maxn][2], cnt[maxn];

int f[maxn][32000 + 100];

int main() {
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> p[i] >> q[i];
        if (q[i]) {
            app[q[i]][cnt[q[i]]++] = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (q[i]) {
            memcpy(f[i], f[i - 1], sizeof(f[i]));
            continue;
        }

        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];

            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + v[i] * p[i]);

            int a = app[i][0], b = app[i][1];
            if (a && j >= v[i] + v[a])
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] - v[a]] + v[i] * p[i] + v[a] * p[a]);
            if (b && j >= v[i] + v[b])
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] - v[b]] + v[i] * p[i] + v[b] * p[b]);
            if (a && b && j >= v[i] + v[a] + v[b]) {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] - v[a] - v[b]] + v[i] * p[i] + v[a] * p[a] + v[b] * p[b]);
            }
        }
    }

    cout << f[n][m] << endl;

    return 0;
}