#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 1000000 + 100;

int val[maxn];
int color[maxn];

int g[maxn][2];
LL f[maxn][2];

int main() {

    int T;
    cin >> T;
    while (T--) {
        int n, m, idx;
        cin >> n >> m;
        idx = 0;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                idx++;
                cin >> val[idx];
            }

        idx = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                idx++;
                cin >> color[idx];
            }

        idx = 0;
        for(int i = 1; i <= n; i++) {
            g[i][0] = g[i][1] = -1;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                idx++;
                g[i][color[idx]] = max(g[i][color[idx]], val[idx]);
            }

        if (n == 1) {
            cout << max(g[1][0], g[1][1]) << endl;
            continue;
        }

        //第一个珠子选红色
        f[1][0] = -1;
        f[1][1] = g[1][1];

        for (int i = 2; i <= n; i++) {
            f[i][0] = -1;
            f[i][1] = -1;
            if (g[i][0] != -1) { //选蓝色
                if (f[i - 1][0] != -1) f[i][0] = max(f[i][0], f[i - 1][0] + g[i][0]);
                if (f[i - 1][1] != -1) f[i][0] = max(f[i][0], f[i - 1][1] + g[i][0]);
            }

            if (g[i][1] != -1) { // 选红色
                if (f[i - 1][0] != -1) f[i][1] = f[i - 1][0] + g[i][1];
            }
        }

        LL ans = f[n][0];

        //第一个珠子选蓝色
        f[1][0] = g[1][0];
        f[1][1] = -1;

        for (int i = 2; i <= n; i++) {
            f[i][0] = -1;
            f[i][1] = -1;
            if (g[i][0] != -1) { //选蓝色
                if (f[i - 1][0] != -1) f[i][0] = max(f[i][0], f[i - 1][0] + g[i][0]);
                if (f[i - 1][1] != -1) f[i][0] = max(f[i][0], f[i - 1][1] + g[i][0]);
            }

            if (g[i][1] != -1) { // 选红色
                if (f[i - 1][0] != -1) f[i][1] = f[i - 1][0] + g[i][1];
            }
        }


        ans = max(ans, max(f[n][0], f[n][1]));

        cout << ans << endl;
    }

    return 0;
}