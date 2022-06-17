/*
    Created by godlei at 2022-06-17 13:39:46
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
const int maxn = 200000 + 100;
vector<int> G[maxn];
int dis[maxn];
int deg[maxn];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int u, v;
    for(int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        G[v].push_back(u);
        deg[u]++;
    }
    
    memset(dis, 0x3f, sizeof(dis));
    dis[n] = 0;

    priority_queue<PII, vector<PII>, greater<PII> > Q;
    Q.push(make_pair(0, n));

    while(Q.size()) {
        PII node = Q.top();
        Q.pop();

        int v = node.second;
        if(node.first != dis[v]) continue;


        for(int u : G[v]) {
            deg[u]--;

            if(dis[v] + 1 + deg[u] < dis[u]) {
                dis[u] = dis[v] + 1 + deg[u];
                Q.push(make_pair(dis[u], u));
            }

        }



    }

    printf("%d\n", dis[1]);

    // for(int i = 1; i <= n; i++) {
    //     printf("%d ", dis[i]);
    // }
    // printf("\n");

    return 0;
}