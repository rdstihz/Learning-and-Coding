#include <cstdio>

int f[11][11];

void init() {

    for (int i = 0; i <= 9; i++)
        f[1][i] = 1;
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if (j - k <= -2 || j - k >= 2)
                    f[i][j] += f[i - 1][k];
            }
        }
    }
}

int nums[20], m;

int dp(int n) {
    //if (!n) return 1;

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
    int last = -3;
    for (int i = m; i >= 1; i--) {
        int x = nums[i];

        for (int j = i == m ? 1 : 0; j < x; j++)
            if (j - last <= -2 || j - last >= 2)
                res += f[i][j];

        if (x - last > -2 && x - last < 2) break;
        last = x;
        if (i == 1) res++;
    }
    return res;
}

int main() {

    init();
    int l, r;
    while (~scanf("%d%d", &l, &r)) {
        printf("%d\n", dp(r) - dp(l - 1));
    }

    return 0;
}