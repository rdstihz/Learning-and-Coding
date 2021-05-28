#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL P = 1e9 + 7;

LL A, B, C, X;

int m;
int numsa[100], numsb[100], numsc[100];
int numsx[100];

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

void add(LL& a, LL b) {
    a = (a + b) % P;
}

LL g[65][2][2][2][2][2][2];

LL dp(int i, bool a, bool b, bool c, bool d, bool e, bool f) {
    LL& res = g[i][a][b][c][d][e][f];
    if (res > 0) return res;

    if (a && b && c && d && e && f) {
        return res = pow_mod(8, i, P);
    }
    if (i == 0) {
        return res = 1;
    }
    res = 0;
    for (int u = 0; u < 2; u++)
        for (int v = 0; v < 2; v++)
            for (int w = 0; w < 2; w++) {
                if ((!a) && u > numsa[i]) continue;
                if ((!b) && v > numsb[i]) continue;
                if ((!c) && w > numsc[i]) continue;

                if ((!d) && (u ^ v) > numsx[i]) continue;
                if ((!e) && (v ^ w) > numsx[i]) continue;
                if ((!f) && (w ^ u) > numsx[i]) continue;

                add(res, dp(i - 1, a | (u < numsa[i]), b | (v < numsb[i]), c | (w < numsc[i]),
                            d | ((u ^ v) < numsx[i]), e | ((v ^ w) < numsx[i]), f | ((w ^ u) < numsx[i])));
            }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(g, -1, sizeof(g));
        cin >> A >> B >> C >> X;
        m = 0;
        while (A || B || C || X) {
            m++;
            numsa[m] = A & 1;
            numsb[m] = B & 1;
            numsc[m] = C & 1;
            numsx[m] = X & 1;

            A >>= 1;
            B >>= 1;
            C >>= 1;
            X >>= 1;
        }
        cout << dp(m, 0, 0, 0, 0, 0, 0) << endl;
    }

    return 0;
}