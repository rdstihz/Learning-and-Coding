#include <bits/stdc++.h>

using namespace std;
const double INF = 1e12;
double dp[15][15][15][15][5][5];
bool vis[15][15][15][15][5][5];

int A, B, C, D;

double dfs(int a, int b, int c, int d, int x, int y) {
    if (vis[a][b][c][d][x][y])
        return dp[a][b][c][d][x][y];

    double& res = dp[a][b][c][d][x][y];

    if (a + (x == 0) + (y == 0) >= A && b + (x == 1) + (y == 1) >= B &&
        c + (x == 2) + (y == 2) >= C && d + (x == 3) + (y == 3) >= D)
        return res = 0;
    int sum = a + b + c + d + (x != 4) + (y != 4);
    if (sum >= 54) {
        return INF;
    }
    vis[a][b][c][d][x][y] = true;

    res = 0;

    if (a < 13)
        res += (dfs(a + 1, b, c, d, x, y) + 1) * (13 - a) / (54 - sum);
    if (b < 13)
        res += (dfs(a, b + 1, c, d, x, y) + 1) * (13 - b) / (54 - sum);
    if (c < 13)
        res += (dfs(a, b, c + 1, d, x, y) + 1) * (13 - c) / (54 - sum);
    if (d < 13)
        res += (dfs(a, b, c, d + 1, x, y) + 1) * (13 - d) / (54 - sum);

    if (x == 4) {
        double t = 1e12;
        for (int i = 0; i < 4; i++)
            t = min(t, dfs(a, b, c, d, i, y));
        res += (t + 1) / (54 - sum);
    }
    if (y == 4) {
        double t = 1e12;
        for (int i = 0; i < 4; i++)
            t = min(t, dfs(a, b, c, d, x, i));
        res += (t + 1) / (54 - sum);
    }
    return res;
}

int main() {

    cin >> A >> B >> C >> D;

    int ghost = 0;

    cout << fixed;
    cout << setprecision(3);

    double ans = dfs(0, 0, 0, 0, 4, 4);

    if (ans > 55)
        cout << "-1.000" << endl;
    else
        cout << ans << endl;

    return 0;
}