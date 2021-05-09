#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;
const int maxn = 5001;
int dp[2][maxn][maxn];

long long g[maxn];

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

void dfs(int u, int f) {
    int v;
    for (int e = fir[u]; e; e = nxt[e]) {
        v = to[e];
        if (v != f) {
            dfs(v, u);
        }
    }

    dp[0][u][0] = 1;
    dp[1][u][1] = 1;

    for (int e = fir[u]; e; e = nxt[e]) {
        v = to[e];
        if (v != f) {

            for (int s = 0; s <= n; s++)
                add(dp[0][u][s], dp[0][v][s]);
            
            for(int s = 2; s <= n; s++) {
                g[s] = 
            }
        
        }
    }
}

int main() {

    cin >> n;

    int v;
    for (int u = 2; u <= n; u++) {
        cin >> u;
        add_edge(u, v);
        add_edge(v, u);
    }

    dfs(1, -1);

    return 0;
}