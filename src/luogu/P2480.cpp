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

const LL P = 999911659;

//a[1] - a[4]为 999911658的四个质因数。
LL a[] = {0, 2, 3, 4679, 35617};
LL b[5];
int main() {
    LL n, q;
    cin >> n >> q;

    if (q % P == 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i <= 4; i++) {
        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                b[i] = (b[i] + Lucas(n, d, a[i])) % a[i];
                if (d * d != n) {
                    b[i] = (b[i] + Lucas(n, n / d, a[i])) % a[i];
                }
            }
        }
    }
    //用中国剩余定理求解同余方程组
    LL x = 0;
    for (int i = 1; i <= 4; i++) {
        LL M = (P - 1) / a[i];
        x = (x + (b[i] * M % (P - 1)) * pow_mod(M, a[i] - 2, a[i])) % (P - 1);
    }
    cout << pow_mod(q, x, P) << endl;

    return 0;
}