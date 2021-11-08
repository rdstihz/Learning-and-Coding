/*
    Created by rdstihz at 2021-11-04 21:01:12
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 5010;
const int INF = 0x3f3f3f3f;
const double eps = 1e-13;
int dis[maxn][maxn];
int a[maxn]; // a[i]表示公共部分长度为i时，最短的个人路径长度
vector<int> G[maxn];

int n, m, k;
int s1, t1, s2, t2;
int q[maxn];
void bfs(int s) {
    int l = 0, r = 0;
    dis[s][s] = 0;
    q[++r] = s;
    while (l < r) {
        int u = q[++l];
        for (int v : G[u]) {
            if (dis[s][v] == INF) {
                dis[s][v] = dis[s][u] + 1;
                q[++r] = v;
            }
        }
    }
}

int getTimes(double x) {
    int l = 0, r = 2e9;
    int m;
    while (l < r) {
        m = l + r + 1 >> 1;
        if (1ll * m * (m + 1) <= x)
            l = m;
        else
            r = m - 1;
    }
    return l;
}

double get(int a, int p, int b, int q) {
    double res = 0;
    if (a) res += 2.0 / (p / a + 1) * (a - p % a);
    if (a) res += 2.0 / (p / a + 2) * (p % a);
    if (b) res += 1.0 / (q / b + 1) * (b - q % b);
    if (b) res += 1.0 / (q / b + 2) * (q % b);
    return res;
}

double calc(int a, int b) {
    //三分用在公共部分的钱数
    int l = 0, r = k;
    int m1, m2;
    while (l < r) {
        m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (get(a, m1, b, k - m1) > get(a, m2, b, k - m2))
            l = m1 + 1;
        else
            r = m2 - 1;
    }
    return get(a, l, b, k - l);
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    int u, v;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    scanf("%d%d%d%d", &s1, &t1, &s2, &t2);
    memset(dis, 0x3f, sizeof(dis));

    for (int i = 1; i <= n; i++)
        bfs(i);

    memset(a, 0x3f, sizeof(a));
    a[0] = dis[s1][t1] + dis[s2][t2];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            assert(dis[i][j] <= INF);

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (dis[i][j] < INF && dis[s1][i] < INF && dis[s2][i] < INF) {
                int t = min(dis[s1][i] + dis[j][t1], dis[s1][j] + dis[i][t1]) + min(dis[s2][i] + dis[j][t2], dis[s2][j] + dis[i][t2]);
                a[dis[i][j]] = min(a[dis[i][j]], t);
            }
        }
    }
    double ans = 1e8;
    for (int i = 0; i <= n; i++) {
        if (a[i] == INF) continue;
        ans = min(ans, calc(i, a[i]));
    }
    printf("%.12f\n", ans);
    return 0;
}