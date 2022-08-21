/*
    Created by rdstihz at 2022-08-21 15:22:10
*/

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII; 
typedef long long LL;
typedef pair<LL, int> PLI;
const int maxn = 100000 + 10;
const LL INF = 1e16;
vector<PII> G[maxn];
int n, m, k;
void Dijkstra(vector<LL> &d) {
    priority_queue<PLI, vector<PLI>, greater<PLI>> Q;
    for(int i = 1; i <= n; i++)
        Q.push(make_pair(d[i], i));

    while(Q.size()) {
        auto item = Q.top();
        Q.pop();

        if(item.first != d[item.second]) continue;

        int u = item.second;
        for(auto& e : G[u]) {
            int v = e.first;
            int w = e.second;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push(make_pair(d[v], v));
            }
        }
    }

}

int q[maxn], l, r;
LL y[maxn];

double getk(int i,int j) {
    return 1.0 * (y[i] - y[j]) / (i - j);
}

void solve() {
    scanf("%d%d%d", &n, &m, &k);

    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    vector<LL> d(n + 1, INF);
    d[1] = 0;
    Dijkstra(d);

    
    for(int ep = 1; ep <= k; ep++) {
        for(int i = 1; i <= n; i++) {
            y[i] = d[i] + 1ll * i * i;
        }
        y[0] = INF;
        l = r = 0;
        q[++r] = 1;
        for(int i = 2; i <= n; i++) {
            while(l < r && getk(q[r - 1], q[r]) >= getk(q[r], i)) r--;
            q[++r] = i;
        }
        
        for(int i = 1; i <= n; i++) {
            while(r - l > 1 && getk(q[l + 1], q[l + 2]) <= 2 * i) l++;
            int j = q[l + 1];
            d[i] = y[j] - 2ll * i * j + 1ll * i * i;
        }

        Dijkstra(d);
    }

    for(int i = 1; i <= n; i++) {
        printf("%lld ", d[i]);
    }
    printf("\n");
}

int main() {
    int T;
    T = 1;
    while (T--)
        solve();
    return 0;
}