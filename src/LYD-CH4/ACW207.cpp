#include <algorithm>
#include <cstdio>

using namespace std;

const double eps = 1e-10;

double a[20][20], b[20][20];

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n + 1; i++)
        for (int j = 1; j <= n; j++)
            scanf("%lf", &b[i][j]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = (b[i + 1][j] - b[i][j]) * 2;
            a[i][n + 1] += b[i + 1][j] * b[i + 1][j] - b[i][j] * b[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {

        for (int j = i; j <= n; j++)
            if (a[j][i] > eps) {
                for (int k = 1; k <= n + 1; k++)
                    swap(a[i][k], a[j][k]);
            }

        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            double t = a[j][i] / a[i][i];
            for (int k = 1; k <= n + 1; k++) {
                a[j][k] -= a[i][k] * t;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%.3lf ", a[i][n + 1] / a[i][i]);
    }

    return 0;
}