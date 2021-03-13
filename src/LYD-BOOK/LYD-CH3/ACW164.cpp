#include <cstdio>
#include <bitset>
#include <queue>

const int maxn = 30000 + 10;

using namespace std;

bitset<maxn> S[maxn];

int tot;
int to[maxn];
int fir[maxn], nxt[maxn];
int ind[maxn];

void add(int u, int v) {
    tot++;
    to[tot] = v;
    nxt[tot] = fir[u];
    fir[u] = tot;
    ind[v]++;
}

int top[maxn];

int main() {

    int n, m;
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    //拓扑排序
    int k = 0;
    queue<int> Q;
    for (int i = 1; i <= n; i++)
        if (!ind[i])
            Q.push(i);

    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        top[++k] = u;

        for (int e = fir[u]; e; e = nxt[e]) {
            int v = to[e];
            ind[v]--;
            if (!ind[v]) {
                Q.push(v);
            }
        }
    }

    for(int i = n;i >= 1;i--) {
        int u = top[i];
        S[u][u] = 1;
        for(int e = fir[u]; e; e = nxt[e]) {
            int v = to[e];
            S[u] |= S[v];
        }
    }

    for(int i = 1;i <= n; i++) {
        printf("%d\n",S[i].count());
    }

    return 0;
}