#include <iostream>
using namespace std;

/*
2 19
28 2
*/

typedef long long LL;

const LL P = 1000000000 + 7;

LL k, K;
LL T;

const int maxn = 100;
LL p[maxn], q[maxn];

inline void divide(LL x, LL* p) {
    p[0] = 0;

    while (x) {
        p[++p[0]] = x % k;
        x /= k;
    }
}

LL pow_mod(LL a, LL b, LL p) {
    LL res = 1;

    while (b) {
        if (b & 1)
            res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }

    return res % p;
}

inline LL getnums(LL n, LL m) {

    if (m == 0) {
        return 1;
    } else if (m < 0) {
        return 0;
    }

    n++;
    if (n <= m) { // 1 + 2 + 3 + ... + n
        return (n * (n + 1) / 2) % P;
    } else {
        LL res = (m * (m + 1) / 2) % P; // 1 + 2 + 3 + ... + m

        n -= m;
        res = (res + n * (m + 1) % P) % P;
        return res;
    }
}

inline void add(LL& a, LL b) {
    a = (a + b) % P;
}

LL dfs(int pos, bool a, bool b, bool c) {

    if (pos == 0)
        return 1;

    LL res = 0;

    if (a && b && c) {
        res = pow_mod(K, pos, P);
    }

    else if (a && !b) {
        LL t1 = getnums(k - 1, q[pos] - 1);
        LL t2 = k - q[pos];

        if (c) {
            add(res, t1 * dfs(pos - 1, true, true, true) % P);
            add(res, t2 * dfs(pos - 1, true, false, true) % P);
        } else {
            add(res, q[pos] * dfs(pos - 1, true, true, false) % P);
            add(res, (t1 - q[pos]) * dfs(pos - 1, true, true, true));

            add(res, dfs(pos - 1, true, false, false) % P);
            add(res, (t2 - 1) * dfs(pos - 1, true, false, true) % P);
        }
    } else if (b && !a) {
        LL t1 = getnums(p[pos] - 1, k - 1);
        LL t2 = p[pos] + 1;

        if (c) {
            add(res, t1 * dfs(pos - 1, true, true, true) % P);
            add(res, t2 * dfs(pos - 1, false, true, true) % P);
        } else {
            add(res, p[pos] * dfs(pos - 1, true, true, false) % P);
            add(res, (t1 - p[pos]) * dfs(pos - 1, true, true, true) % P);

            add(res, dfs(pos - 1, false, true, false) % P);
            add(res, (t2 - 1) * dfs(pos - 1, false, true, true) % P);
        }
    } else if (!(a || b)) {
        LL t1 = getnums(p[pos] - 1, q[pos] - 1); // a -> true ,  b -> true;

        LL t2 = getnums(p[pos] - 1, q[pos]) - t1; // a -> true, b = false

        LL t3 = getnums(p[pos], q[pos] - 1) - t1; // a = false, b -> true;

        LL t4 = getnums(p[pos], q[pos]) - t1 - t2 - t3; // a = false, b = false;

        if (c) {
            add(res, t1 * dfs(pos - 1, true, true, true) % P);
            add(res, t2 * dfs(pos - 1, true, false, true) % P);
            add(res, t3 * dfs(pos - 1, false, true, true) % P);
            add(res, t4 * dfs(pos - 1, false, false, true) % P);
        } else {
            LL tt1 = min(p[pos], q[pos]);
            LL tt2 = p[pos] > q[pos] ? 1 : 0;
            LL tt3 = q[pos] > p[pos] ? 1 : 0;
            LL tt4 = p[pos] == q[pos] ? 1 : 0;

            add(res, tt1 * dfs(pos - 1, true, true, false) % P);
            add(res, (t1 - tt1) * dfs(pos - 1, true, true, true) % P);

            add(res, tt2 * dfs(pos - 1, true, false, false) % P);
            add(res, (t2 - tt2) * dfs(pos - 1, true, false, false) % P);

            add(res, tt3 * dfs(pos - 1, false, true, false) % P);
            add(res, (t3 - tt3) * dfs(pos - 1, false, true, true) % P);

            add(res, tt4 * dfs(pos - 1, false, false, false) % P);
            add(res, (t4 - tt4) * dfs(pos - 1, false, false, true) % P);
        }
    }

    return res;
}

int main() {

    int T;
    cin >> T >> k;
    K = (k * (k + 1) / 2) % P;

    while (T--) {
        LL n, m;
        cin >> n >> m;
        if (m > n) {
            m = n;
        }
        divide(n, p);
        divide(m, q);

        LL res = dfs(p[0], false, false, false);

        LL total = getnums(n, m);

        LL ans = (total + P - res) % P;
        cout << ans << endl;
    }


    return 0;
}