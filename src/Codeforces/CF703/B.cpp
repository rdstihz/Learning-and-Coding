#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1010;

int x[maxn], y[maxn];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i];
        }

        sort(x + 1, x + 1 + n);
        sort(y + 1, y + 1 + n);

        long long ans = 1;

        if (n % 2 == 0) {
            int t = n / 2;
            ans = (long long)(x[t + 1] - x[t] + 1) * (y[t + 1] - y[t] + 1);
        }
        cout << ans << endl;
    }

    return 0;
}