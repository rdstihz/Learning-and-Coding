#include <bits/stdc++.h>

using namespace std;

const int maxn = 82;

int f[11][83][83][83];
int pwr[11][83];

int mod(int a, int b) {
    return (a % b + b) % b;
}

void init() {
    for (int k = 1; k <= 82; k++) {
        pwr[0][k] = 1 % k;
        for (int i = 1; i <= 10; i++)
            pwr[i][k] = 10 * pwr[i - 1][k] % k;

        f[0][0][k][0] = 1;

        for (int i = 1; i <= 10; i++)
            for (int j = 0; j <= 82; j++)
                for (int l = 0; l < k; l++) {

                    for (int p = 0; p <= 9 && p <= j; p++) {
                        f[i][j][k][l] += f[i - 1][j - p][k][mod(l - p * pwr[i - 1][k], k)];
                    }
                }
    }
}

int num[12];

int calc(int x) {

    //分解x
    int n = 0;
    while (x) {
        num[++n] = x % 10;
        x /= 10;
    }
    int ans = 0;
    for (int k = 1; k <= 82; k++) {
        int t = 0;
        int sum = 0;
        for (int i = n; i >= 1; i--) {
            for (int p = 0; p < num[i] && sum + p <= k; p++)
                ans += f[i - 1][k - sum - p][k][mod(-t - p * pwr[i - 1][k], k)];
            sum += num[i];
            t = (t + num[i] * pwr[i - 1][k] % k) % k;
        }
        if (t == 0 && sum == k) ans++;
    }

    return ans;
}

int main() {

    init();
    int L, R;
    while (cin >> L >> R) {
        cout << calc(R) - calc(L - 1) << endl;
    }
    return 0;
}