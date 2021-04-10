#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

bool check(LL x, LL n, LL m) {

    if (x == 1)
        return false;
    if (x == 2)
        return n == m;

    int k = n / m;
    int t = k * x;

    n %= t;
    m %= x;

    if (m == 0 && n == 0) return true;
    if (m > 2) return true;
    if (m == 1)
        return n < x;
}

int main() {

    int T;
    cin >> T;
    while (T--) {
        LL n, m;
        cin >> n >> m;
        LL L = 0, R = n / m + 1;
        LL M;
        while (L < R) {
            M = L + R >> 1;
            if (check(M, n, m)) {
                R = M;
            } else {
                L = M + 1;
            }
        }
        cout << L << endl;
    }

    return 0;
}