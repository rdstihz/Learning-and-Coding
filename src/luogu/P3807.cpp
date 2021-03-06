#include <iostream>

using namespace std;

typedef long long LL;

//快速幂
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

//组合数
LL C(LL n, LL m, LL p) {
    if (n < m) return 0;

    LL a = 1; //分子
    LL b = 1; //分母
    for (LL i = m + 1; i <= n; i++)
        a = a * i % p;
    for (LL i = 1; i <= n - m; i++)
        b = b * i % p;
    return a * pow_mod(b, p - 2, p) % p;
}

LL Lucas(LL n, LL m, LL p) { //用lucs定理计算C(n,m) % p 的值
    if (n - m < p)           // n - m < p 时可直接计算
        return C(n, m, p);
    else // n >= p 递归使用lucas定理
        return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        LL n, m, p;
        cin >> n >> m >> p;
        cout << Lucas(n + m, m, p) << endl;
    }
    return 0;
}