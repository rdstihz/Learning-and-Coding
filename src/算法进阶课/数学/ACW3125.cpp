#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL INF = 0x3f3f3f3f3f3f3f3f;

LL exgcd(LL a, LL b, LL& x, LL& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    } else {
        LL d = exgcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
}

LL bsgs(LL a, LL b, LL p) {
    b %= p;

    unordered_map<LL, LL> hash;
    LL x = 1;
    LL t = sqrt(p) + 1;

    for (int j = 0; j < t; j++) {
        hash[x * b % p] = j;
        x = x * a % p;
    }
    hash[x * b % p] = t;

    a = x;
    for (int i = 1; i <= t; i++) {
        if (hash.count(x)) return i * t - hash[x];
        x = x * a % p;
    }
    return -INF;
}

LL exbsgs(LL a, LL b, LL p) {
    if (1 % p == b % p) return 0;

    LL x, y, d;
    d = exgcd(a, p, x, y);
    if (d == 1) {
        return bsgs(a, b, p);
    } else {
        if (b % d) return -INF;
        p /= d;
        //a / d 模 p的逆元
        exgcd(a / d, p, x, y);
        x = (x % p + p) % p;
        return 1 + exbsgs(a, b / d * x % p, p);
    }
}

int main() {
    LL a, p, b;
    while (cin >> a >> p >> b, a || p || b) {
        LL res = exbsgs(a, b, p);
        if (res < 0)
            cout << "No Solution" << endl;
        else
            cout << res << endl;
    }

    return 0;
}