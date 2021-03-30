#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

const int maxn = 1010;

typedef pair<int, int> PII;
typedef pair<PII, PII> PIII;

vector<PII> G[maxn];

int f[maxn];

void Dijkstra(int S) {

    memset(f, 0x3f, sizeof(f));

    f[S] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> Q;
    Q.push(make_pair(0, S));
    while (Q.size()) {
        PII node = Q.top();
        Q.pop();
        int u = node.second;
        if (node.first > f[u]) continue;

        for (auto e : G[u]) {
            int v = e.first;
            int w = e.second;

            if (f[v] > f[u] + w) {
                f[v] = f[u] + w;
                Q.push(make_pair(f[v], v));
            }
        }
    }
}

int A_star(int S, int E, int n) {

    priority_queue<PIII, vector<PIII>, greater<PIII>> Q;
    set<PII> Vis;
    Q.push({{f[S], 0}, {S, 0}});

    while (Q.size()) {
        PIII node = Q.top();
        Q.pop();
        if (Vis.count(node.second)) continue;
        Vis.insert(node.second);
        if (node.second == make_pair(E, n))
            return node.first.second;

        if (node.second.second >= n) continue;
        int u = node.second.first;

        for (auto e : G[u]) {
            int v = e.first;
            int w = e.second;

            Q.push({{node.first.second + w + max(f[v], n - node.second.second - 1), node.first.second + w}, {v, node.second.second + 1}});
        }
    }
    return -1;
}

int main() {
    int N, T, S, E;
    cin >> N >> T >> S >> E;
    int u, v, w;
    for (int i = 1; i <= T; i++) {
        cin >> w >> u >> v;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    //从E开始跑一遍最短路，作为估价函数
    Dijkstra(E);

    
    //A*
    int ans = A_star(S, E, N);

    cout << ans << endl;

    return 0;
}