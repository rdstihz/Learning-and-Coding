#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL pow_mod(LL a, LL b, LL p) {
    LL res = 1;
    while (b) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res % p;
}

LL bsgs(LL a, LL b, LL p) {
    b %= p;

    unordered_map<LL, LL> hash;
    LL x = 1;
    int t = sqrt(p) + 1;
    for (int j = 0; j < t; j++) {
        hash[b * x % p] = j;
        x = x * a % p;
    }
    hash[b * x % p] = t;
    a = x;
    for (int i = 1; i <= t; i++) {
        if (hash.count(x))
            return i * t - hash[x];
        x = x * a % p;
    }
    return -2;
}

int main() {

    int T;
    cin >> T;

    while (T--) {
        LL p, a, b, X1, t;
        cin >> p >> a >> b >> X1 >> t;

        if (X1 == t) {
            cout << 1 << endl;
            continue;
        }
        if (a < 2 ) {

            if (a == 0) {
                if(X1 == t)
                    cout << 1 << endl;
                else if(b == t)
                    cout << 2 << endl;
                else 
                    cout << -1 <<endl;
            } else if (a == 1) {
                if (b == 0) {
                    cout << (X1 == t ? 1 : -1) << endl;
                } else {
                    LL B = (p + t - X1 + b) % p;
                    LL res =  B * pow_mod(b, p - 2, p) % p;
                    if(res == 0) res += p;
                    cout << res << endl;
                }
            }

            continue;
        }
        if ((X1 * (a - 1) + b) % p == 0) {
            cout << (X1 == t ? 1 : -1) << endl;
            continue;
        }

        LL B = (t * (a - 1) % p + b) % p;
        LL A = (X1 * (a - 1) % p + b) % p;

        cout << bsgs(a, B * pow_mod(A, p - 2, p) % p, p) + 1 << endl;
    }

    return 0;
}