#include <bits/stdc++.h>

using namespace std;
const int P = 998244353;
const int maxn = 5001;
int dp[maxn][maxn];

int fir[maxn], nxt[2 * maxn];
int to[2 * maxn];
int tot;

int n;

void add_edge(int a, int b) {
    tot++;
    to[tot] = b;
    nxt[tot] = fir[a];
    fir[a] = tot;
}

inline void add(int& a, int b) {
    a = (a + b) % P;
}

int mul(int a, int b) {
    int res = 0;
    while (b) {
        if (b & 1)
            add(res, a);
        a = (a + a) % P;
        b >>= 1;
    }
    return res;
}

int pow_mod(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = mul(res, a);
        b >>= 1;
        a = mul(a, a);
    }
    return res;
}

int dfs(int u, int f) {

    int sz = 1;

    dp[u][1] = 1;
    

    for (int e = fir[u]; e; e = nxt[e]) {
        int v = to[e];
        if (v != f) {
            int t = dfs(v, u);
            sz += t;
            for (int j = sz; j >= 2; j--) {
                for (int k = j - t; k < j; k++) {
                    add(dp[u][j], mul(dp[u][k], dp[v][j - k]));
                }
            }
        }
    }

    return sz;
}

int main() {

    while (cin >> n) {
        int v;
        memset(fir, 0, sizeof(fir));
        memset(dp, 0, sizeof(dp));
        tot = 0;
        for (int u = 2; u <= n; u++) {
            cin >> v;
            add_edge(u, v);
            add_edge(v, u);
        }

        dfs(1, -1);

        int a = 0, b = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                //a = (a + j * dp[i][j] % P) % P;
                add(a, mul(j, dp[i][j]));
                //b = (b + dp[i][j]) % P;
                add(b, dp[i][j]);
            }
        }
        cout << a * pow_mod(b, P - 2, P) % P << endl;
    }

    return 0;
}