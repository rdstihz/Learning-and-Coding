#include <bits/stdc++.h>

using namespace std;
const double eps = 0.05;

int a, b;

double f(double x) {
    if (b + x < 1 + eps) return 1e9;
    return x + 1 + log(a) / log(b + x);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b;

        double l = 0, r = a + 1;
        double m1, m2;

        while (r - l > eps) {
            m1 = l + (r - l) / 3;
            m2 = m1 + (r - l) / 3;
            if (f(m1) < f(m2))
                r = m2;
            else
                l = m1;
        }

        cout << min(floor(f(floor(l))), floor(f(ceil(l)))) << endl;
    }
}