#include <bits/stdc++.h>

using namespace std;

int f[11][11];

void init() {
    for (int i = 0; i <= 9; i++)
        if (i != 4) f[1][i] = 1;

    for (int i = 2; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 4) continue;

            for (int k = 0; k <= 9; k++) {
                if (j == 6 && k == 2) continue;
                f[i][j] += f[i - 1][k];
            }
        }
    }
}

int nums[20], m;

int dp(int n) {

    m = 0;
    while (n) {
        nums[++m] = n % 10;
        n /= 10;
    }
    int res = 0;
    for (int i = 1; i < m; i++) {
        for (int j = 1; j <= 9; j++)
            res += f[i][j];
    }

    int last = -1;

    for (int i = m; i >= 1; i--) {
        int x = nums[i];
        for (int j = i == m ? 1 : 0; j < x; j++) {
            if (last == 6 && j == 2) continue;
            if (j == 4) continue;
            res += f[i][j];
        }

        if (last == 6 && x == 2) break;
        if (x == 4) break;

        last = x;
        if (i == 1) res++;
    }
    return res;
}

int main() {

    int l, r;
    init();
    while(cin >> l >> r, l || r) {
        cout << dp(r) - dp(l - 1) << endl;
    }


    return 0;
}