#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;

const int maxn = 100000 + 10;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int a[maxn];

int v[maxn * 4], w[maxn * 4];
int fir[maxn], nxt[maxn * 4];
int tot;
void add(int a, int b, int c) {
    tot++;
    v[tot] = b, w[tot] = c;
    nxt[tot] = fir[a];
    fir[a] = tot;
}

int n, m;

LL d[maxn];
bool vis[maxn];
typedef pair<LL, int> PII;
priority_queue<PII, vector<PII>, greater<PII>> Q;
void Dijkstra() {
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    Q.push(make_pair(0, 1));

    while (Q.size()) {
        PII node = Q.top();
        Q.pop();
        int u = node.second;
        if (vis[u]) continue;
        vis[u] = true;

        for (int e = fir[u]; e; e = nxt[e]) {
            int t = v[e];
            for (int ee = fir[t]; ee; ee = nxt[ee]) {
                int val = (w[e] + w[ee]) * (w[e] + w[ee]);
                if (d[v[ee]] > d[u] + val) {
                    d[v[ee]] = d[u] + val;
                    Q.push(make_pair(d[v[ee]], v[ee]));
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int a, b, c;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    Dijkstra();

    for (int i = 1; i <= n; i++){
        if(d[i] == INF) 
            cout << -1 << " ";
        else
            cout << d[i] << " ";
    }
    cout << endl;

    return 0;
}