#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

const int maxn = 120;
const double eps = 1e-10;
double a[maxn][maxn];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n + 1; j++) {
            cin >> a[i][j];
        }

    for (int i = 1; i <= n; i++) {
        //找到a[j][i] != 0的一项
        bool find = false;
        for (int j = i; j <= n; j++)
            if (fabs(a[j][i]) > eps) {
                for (int k = 1; k <= n + 1; k++)
                    swap(a[i][k], a[j][k]);
                find = true;
                break;
            }

        if (!find) {
            cout << "No Solution" << endl;
            return 0;
        }

        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            double t = a[j][i] / a[i][i];
            for (int k = 1; k <= n + 1; k++)
                a[j][k] -= a[i][k] * t;
        }
    }
    cout << fixed << setprecision(2);
    for (int i = 1; i <= n; i++) {
        cout << a[i][n + 1] / a[i][i] << endl;
    }
    return 0;
}