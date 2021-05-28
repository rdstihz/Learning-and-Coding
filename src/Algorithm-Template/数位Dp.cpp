//Acwing 338 计数问题

#include <bits/stdc++.h>

using namespace std;

int f[11][10];
int pwr[11];
void init() {

    pwr[0] = 1;
    for (int i = 1; i <= 9; i++)
        pwr[i] = pwr[i - 1] * 10;

    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            f[i][j] = f[i - 1][j] * 10 + pwr[i - 1];
        }
    }
}

int nums[20], m;

int dp(int n, int t) {
    m = 0;
    while (n) {
        nums[++m] = n % 10;
        n /= 10;
    }

    int res = 0;

    for (int i = 1; i < m; i++)
        res += 9 * f[i - 1][t] + (t != 0) * pwr[i - 1];

    int last = 0; // 前面已有t和个数

    for (int i = m; i >= 1; i--) {
        int x = nums[i];
        if (i == m) { //首位不能填0
            for (int j = 1; j < x; j++)
                res += f[i - 1][t] + (last + (j == t)) * pwr[i - 1];
        } else {
            for (int j = 0; j < x; j++)
                res += f[i - 1][t] + (last + (j == t)) * pwr[i - 1];
        }
        last += x == t;
    }
    res += last;
    return res;
}

int main() {

    init();

    int l, r;
    while (cin >> l >> r, l || r) {
        if (l > r) swap(l, r);
        for (int i = 0; i <= 9; i++)
            cout << dp(r, i) - dp(l - 1, i) << " ";
        cout << endl;
    }

    return 0;
}