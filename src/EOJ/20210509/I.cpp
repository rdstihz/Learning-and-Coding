#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n, a, b, c;

LL calc(LL x) {
    LL res = 0;

    res += x * a;

    while (n > x) {
        x <<= 1;
        res += b;
    }
    res += (x - n) * c;
    return res;
}

int main() {

    while (cin >> n >> a >> b >> c) {
        int L = 1, R = n;
        int m1, m2;
        while (R - L > 1) {
            m1 = L + (R - L + 1) / 3;
            m2 = m1 + (R - L + 1) / 3;

            LL a = calc(m1);
            LL b = calc(m2);

            if (a > b) {
                L = a + 1;
            } else {
                R = b - 1;
            }
        }
        LL a = calc(L);
        LL b = calc(R);
        cout << min(a, b) << endl;
    }
    return 0;
}