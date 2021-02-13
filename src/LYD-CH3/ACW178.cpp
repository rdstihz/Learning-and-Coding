#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, pair<int, int>> PIII;

const int maxn = 1010;
const int maxm = 100000 + 10;
const int INF = 0x3f3f3f3f;

vector<PII> G[maxn], aG[maxn];
int n, m;
int s, t, k;

int d[maxn];
void Dijkstra() {
    memset(d, 0x3f, sizeof d);
    d[t] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> Q;
    Q.push(make_pair(d[t], t));

    while (Q.size()) {
        PII node = Q.top();
        Q.pop();

        if (d[node.second] != node.first) continue;

        int u = node.second;
        for (PII e : aG[u]) {
            int v = e.second;
            if (d[v] > d[u] + e.first) {
                d[v] = d[u] + e.first;
                Q.push(make_pair(d[v], v));
            }
        }
    }
}

int cnt[maxn];
int f[maxn];

int Astar() {
    priority_queue<PIII,vector<PIII>,greater<PIII> > Q;
    Q.push({d[s], {0, s}});

    while (Q.size()) {
        PIII node = Q.top();
        Q.pop();

        int u = node.second.second;
        if (cnt[u] >= k) continue;
        cnt[u]++;
        if (u == t && cnt[u] == k) {
            return node.second.first;
        }

        for (PII e : G[u]) {
            int v = e.second;
            Q.push({node.second.first + e.first + d[v], {node.second.first + e.first, v}});
        }
    }
    return -1;
}

int main() {

    cin >> n >> m;
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        G[u].push_back(make_pair(w, v));
        aG[v].push_back(make_pair(w, u));
    }
    cin >> s >> t >> k;
    Dijkstra();
    if (s == t) k++;
    cout << Astar() << endl;
    return 0;
}