#include <iostream>

using namespace std;
typedef long long LL;

const LL P = 9901;

LL p[30], c[30];

LL pow_mod(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % P;
        a = a * a % P;
        b >>= 1;
    }
    return res;
}

int main() {
    LL a, b;
    cin >> a >> b;
    int n = 0;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            p[++n] = i;
            c[n] = 0;
            while (a % i == 0) {
                c[n]++;
                a /= i;
            }
        }
    }
    if (a > 1) {
        p[++n] = a;
        c[n] = 1;
    }

    LL ans = 1;
    for (int i = 1; i <= n; i++) {
        if ((p[i] - 1) % P == 0) {
            ans = (b * c[i] + 1) % P * ans % P;
        } else {
            ans = ans * (pow_mod(p[i], b * c[i] + 1) + P - 1) % P * pow_mod(p[i] - 1, P - 2) % P;
        }
    }
    cout << ans << endl;
    return 0;
}