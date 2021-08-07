#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000 + 100;
const int maxm = 2000000 + 100;

int to[maxm], nxt[maxm], fir[maxn], tot;

void add_edge(int a, int b) {
    tot++;
    to[tot] = b, nxt[tot] = fir[a], fir[a] = tot;
    tot++;
    to[tot] = a, nxt[tot] = fir[b], fir[b] = tot;
}

int b[maxn];
bool g[maxn][maxn];
int seq[1000 * 1000 + 100], cnt;

int n, m;
void dfs(int u) {
    for (int e = fir[u]; e; e = nxt[e]) {
        fir[u] = e;
        int v = to[e];
        if (!g[u][v]) continue;
        g[u][v] = g[v][u] = 0;
        dfs(to[e]);
        seq[cnt++] = u; //seq.push_back(u);
    }
}




int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {

        scanf("%d%d", &n, &m);

        tot = 0;
        for (int i = 1; i <= n; i++)
            fir[i] = 0;

        for (int i = 1; i <= m; i++)
            scanf("%d", b + i);

        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++) {
                add_edge(i, j);
                g[i][j] = g[j][i] = 1;
            }

        //seq.clear();
        //seq.push_back(1);
        cnt = 0;
        seq[cnt++] = 1;
        dfs(1);

        printf("Case #%d:\n", kase);
        int pos = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= b[i]; j++) {
                printf("%d ", seq[pos++]);
            }
            printf("%d\n", seq[pos]);
        }
    }
    return 0;
}

/*

4
5 6
2 1 1 2 2 2
5 6
2 1 1 2 2 2
7 8
1 1 4 3 4 1 3 4
5 10
1 1 1 1 1 1 1 1 1 1

*/