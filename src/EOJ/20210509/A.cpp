#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL m, k;

LL calc(LL x) {

    if (x <= m)
        return x * (1 + x) / 2;
    else {
        x -= m;
        return (2 * m - 1 - x) * x / 2 + m * (m + 1) / 2;
    }
}

int main() {

    while (cin >> m >> k) {

        int s = 0;

        long long t = m * (m + 1) / 2;

        LL L = 1, R = 2 * m - 1;
        int M;
        while (L < R) {
            M = L + R >> 1;
            if (calc(M) >= k) {
                R = M;
            } else {
                L = M + 1;
            }
        }

        cout << L + 1 << endl;
    }

    return 0;
}