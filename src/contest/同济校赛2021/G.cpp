#include <bits/stdc++.h>

using namespace std;

const int maxn = 510;
const int maxm = 10000 + 100;
const int INF = 0x3f3f3f3f;

int from[maxm], to[maxm], cap[maxm], len[maxm];
int fir[maxn], nxt[maxm], tot;

void add(int a, int b, int c, int l) {
    tot++;
    from[tot] = a, to[tot] = b, cap[tot] = c, len[tot] = l;
    nxt[tot] = fir[a], fir[a] = tot;

    tot++;
    from[tot] = b, to[tot] = a, cap[tot] = 0, len[tot] = -l;
    nxt[tot] = fir[b], fir[b] = tot;
}
int n, m, s, t;

long long maxflow, cost;

int d[maxn], pre[maxn];
bool inq[maxn];
bool spfa() {
    memset(d, 0x3f, sizeof(d));
    memset(inq, 0, sizeof(inq));

    d[s] = 0;
    queue<int> Q;
    Q.push(s);
    inq[s] = true;

    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        inq[u] = false;

        for (int e = fir[u]; e; e = nxt[e])
            if (cap[e]) {
                int v = to[e];
                if (d[v] > d[u] + len[e]) {
                    d[v] = d[u] + len[e];
                    pre[v] = e;

                    if (!inq[v]) {
                        Q.push(v);
                        inq[v] = false;
                    }
                }
            }
    }
    return d[t] < INF;
}

void mcmf() {
    maxflow = cost = 0;
    while (spfa()) {
        int f = INF;
        for (int u = t; u != s; u = from[pre[u]])
            f = min(f, cap[pre[u]]);

        maxflow += f;
        cost += (long long)f * d[t];
        for (int u = t; u != s; u = from[pre[u]]) {
            cap[pre[u]] -= f;
            cap[pre[u] ^ 1] += f;
        }
    }
}

int cnt[maxn];

int main() {

    int T;
    scanf("%d", &T);

    while (T--) {

        memset(fir, 0, sizeof(fir));
        tot = 1;

        scanf("%d%d", &n, &m);

        int S = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", cnt + i);
            S += cnt[i];
        }

        int a, b, c;
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, INF, c);
            add(b, a, INF, c);
        }

        //S 不能整除 n
        if (S % n) {
            printf("-1\n");
            continue;
        }

        int avg = S / n;
        s = n + 1, t = n + 2;
        int totflow = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > avg) {
                totflow += cnt[i] - avg;
                add(s, i, cnt[i] - avg, 0);
            } else if (cnt[i] < avg) {
                add(i, t, avg - cnt[i], 0);
            }
        }

        mcmf();
        if (maxflow != totflow) {
            printf("-1\n");
            continue;
        }

        printf("%lld\n", cost);
    }

    return 0;
}