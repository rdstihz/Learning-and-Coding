#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 25;

int n, m;

int ans;
bool flag;
void dfs(int d, int rest, int sum, int hm, int rm) {

    if (!d) {
        if (!rest) ans = min(ans, sum);
        return;
    }
    if(rest <= 0) return;
    if(d * rm * rm * hm < rest) return;
    if(sum > ans) return;

    int rmax = min(rm, (int)sqrt(rest));
    int rmin = max((int)sqrt(rest / d / hm), 1);

    for (int r = rmax; r >= rmin; r--) {
        int hmax = min(hm, rest / r / r);
        int hmin = max(rest / r / r / d, 1);
        for (int h = hmax; h >= hmin; h--) {
            if (d == m)
                dfs(d - 1, rest - r * r * h, r * r + 2 * r * h, h - 1, r - 1);
            else
                dfs(d - 1, rest - r * r * h, sum + 2 * r * h, h - 1, r - 1);
        }
    }
}

int main() {
    cin >> n >> m;
    ans = 1e9;

    dfs(m, n, 0, n, sqrt(n));

    if (ans == 1e9)
        cout << 0 << endl;
    else
        cout << ans << endl;

    return 0;
}