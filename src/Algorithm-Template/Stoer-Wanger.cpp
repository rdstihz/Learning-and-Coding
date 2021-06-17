#include <bits/stdc++.h>

using namespace std;

const int maxn = 700;

int G[maxn][maxn];
bool del[maxn], vis[maxn];
int w[maxn];
int n, m;
int cnt;
int s, t;

int work() {
    memset(vis, 0, sizeof(vis));
    memset(w, 0, sizeof(w));
    w[0] = -1;
    for (int k = 1; k <= cnt; k++) {
        int p = 0;
        for (int i = 1; i <= n; i++)
            if (!del[i] && !vis[i] && w[i] > w[p]) p = i;
        vis[p] = true;
        for (int i = 1; i <= n; i++)
            if (!del[i] && !vis[i]) w[i] += G[p][i];
        s = t;
        t = p;
    }
    return w[t];
}

int stoer_wanger() {
    cnt = n;
    int res = 0x3f3f3f3f;
    while (cnt > 1) {
        res = min(res, work());
        del[t] = true;
        cnt--;
        for (int i = 1; i <= n; i++) { // 合并s, t两点并删除t
            G[i][s] += G[i][t];
            G[s][i] += G[t][i];
        }
    }
    return res;
}

int main() {

    scanf("%d%d", &n, &m);

    int a, b, c;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        G[a][b] += c;
        G[b][a] += c;
    }

    printf("%d\n", stoer_wanger());

    return 0;
}