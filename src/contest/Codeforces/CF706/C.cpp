#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

const int maxn = 100000 + 10;
const double eps = 1e-10;

long long X[maxn], Y[maxn];

int main() {

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int i = 0, j = 0;
        long long x, y;
        for (int k = 0; k < 2 * n; k++) {

            cin >> x >> y;
            x = abs(x), y = abs(y);

            if (x == 0) {
                Y[j++] = y;
            } else {
                X[i++] = x;
            }
        }

        sort(X, X + n);
        sort(Y, Y + n);
        double ans = 0;
        for (int i = 0; i < n; i++) {
            ans += sqrt(X[i] * X[i] + Y[i] * Y[i]);
        }
        cout << setprecision(10);
        cout << ans << endl;
    }

    return 0;
}