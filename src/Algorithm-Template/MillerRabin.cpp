// LOJ 143

#include <iostream>

using namespace std;
typedef unsigned long long LL;

LL pow_mod(LL a, LL b, LL p) {
    LL res = 1;
    while (b) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

const int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

bool isprime(LL n) {
    if (n == 1) return false;
    for (int i = 0; i < 12; i++) {
        if (a[i] >= n) break;
        LL x = n - 1;
        if (pow_mod(a[i], x, n) != 1)
            return false; // 费马小定理
        while (x % 2 == 0) {
            x = x / 2;
            LL t = pow_mod(a[i], x, n);
            if (t != 1 && t != n - 1)
                return false;
            if (t == n - 1)
                break;
        }
    }
    return true;
}

int main() {
    LL n;
    while (cin >> n) {
        if (isprime(n))
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }

    return 0;
}