#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 4000 + 100;
const int maxm = 2 * maxn;
const LL P = 998244353;

LL f[maxn][maxn][2], g[maxn];
LL h[maxn][maxn];


int to[maxm], nxt[maxm], fir[maxn], tot;
void add_edge(int a,int b) {
    tot++;
    to[tot] = b, nxt[tot] =fir[a], fir[a] = tot;
}

int readIn() {
    int x = 0;
    char c = getchar();
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int dfs(int u,int fa) {
    f[u][0][0] = 1;
    f[u][1][1] = 1;
    h[u][0] = 1;
    int sz = 1;
    for(int e = fir[u]; e; e = nxt[e]) {
        int v = to[e];
        if(v == fa) continue;
        int t = dfs(v, u);
        sz += t;

        for(int j = (sz + 1) / 2; j >= 1; j--)
            for(int k = max(1, j - (sz - t + 1) / 2 ); k <= min((t + 1) / 2, j); k++) {
                f[u][j][1] = (f[u][j][1] + f[u][j - k][1] * h[v][k] % P) % P;
                h[u][j] = (h[u][j] + h[u][j - k] * h[v][k] % P) % P;
                h[u][j] = (h[u][j] + f[u][j - k][0] * (f[v][k][1]) % P) % P;
                f[u][j][0] = (f[u][j][0] + f[u][j - k][0] * h[v][k] % P) % P;       
            }
    }
    return sz;
}


int main() {
    int n;
    n = readIn();
    int a, b;
    for(int i = 1; i < 2 * n; i++) {
        a = readIn();
        b = readIn();
        add_edge(a, b);
        add_edge(b, a);
    }

    g[0] = 1;
    for(int i = 1; i <= n; i++)
        g[i] = (2 * i - 1) * g[i - 1] % P;
    
    dfs(1, 0);

    int p = 1;
    LL ans = 0;
    for(int i = 0; i <= n; i++) {
        ans = (ans + h[1][i] * g[n - i] % P * p % P ) % P;
        p = P - p;
    }
    printf("%lld\n", ans);
    return 0;
}