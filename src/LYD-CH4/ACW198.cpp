#include <iostream>
using namespace std;

const int p[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
typedef long long LL;
int c[13];
int n;

LL pow_mod(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

LL maxg, ans;

void dfs(int d, LL v, int rest, int g) {
    if (v > n) return;

    if (d == 11) {
        if (g > maxg || g == maxg && v < ans) {
            ans = v;
            maxg = g;
        }
        return;
    }

    for (int i = min(c[d - 1], rest); i >= 0; i--) {
        c[d] = i;
        dfs(d + 1, v * pow_mod(p[d], i), rest - i, g * (i + 1));
    }
}

int main() {

    cin >> n;
    c[0] = 30;

    dfs(1, 1, 30, 1);

    cout << ans << endl;

    return 0;
}