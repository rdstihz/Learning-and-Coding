/*
    Created by rdstihz at 2022-08-21 00:24:13
*/

#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-10;

void print(double x, double y) {
    printf("%.15lf %.15lf\n", x, y);
}

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    double x, y;
    if (m == 1) {
        y = 0;
    } else {
        printf("? %d\n", 2 * n + 1);
        print(0, 0);
        for (int i = 1; i <= n; i++) {
            print(i, m);
            print(i, eps);
        }
        fflush(stdout);

        double s;
        scanf("%lf", &s);

        double A = (2 - 1.0 / m) / 2.0;
        double B = (1.0 / m) / 2.0;
        double k = (B - A) / (m - 1);
        y = (s - A) / k;
    }

    if (n == 1) {
        x = 0;
    } else {
        printf("? %d\n", 2 * m + 1);
        print(0, 0);
        for (int i = 1; i <= m; i++) {
            print(n, i);
            print(eps, i);
        }
        fflush(stdout);

        double s;
        scanf("%lf", &s);

        double A = (2 - 1.0 / n) / 2.0;
        double B = (1.0 / n) / 2.0;
        double k = (B - A) / (n - 1);
        x = (s - A) / k;
    }
    printf("! ");
    print(x, y);
}

int main() {
    int T;
    T = 1;
    while (T--)
        solve();
    return 0;
}