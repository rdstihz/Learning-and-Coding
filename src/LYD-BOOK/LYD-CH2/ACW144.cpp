#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 10;
typedef pair<int, int> Edge;

int d[maxn];
vector<Edge> G[maxn];
int n;

void dfs(int u, int f) {

    for (auto e : G[u]) {
        if (e.first == f) continue;
        d[e.first] = d[u] ^ e.second;
        dfs(e.first, u);
    }

}

int ch[maxn * 31][2], tot;

void insert(int v) {
    int u = 1;
    for (int i = 30; i >= 0; i--) {
        int t = (v >> i) & 1;
        if (!ch[u][t]) ch[u][t] = ++tot;
        u = ch[u][t];
    }
}

int solve(int v) {
    int u = 1;
    int res = 0;
    for (int i = 30; i >= 0; i--) {
        int t = (v >> i) & 1;
        if (ch[u][!t]) {
            u = ch[u][!t];
            res |= (1 << i);
        } else {
            u = ch[u][t];
        }

    }
    return res;
}


int main() {
    cin >> n;
    int u, v, w;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    d[0] = 0;
    dfs(0, -1);



    tot = 1;
    insert(d[0]);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans = max(ans, solve(d[i]));
        insert(d[i]);
    }
    cout << ans << endl;

    return 0;
}

//10
//4 1 2
//4 8 6
//1 0 6
//1 3 5
//8 6 9
//8 9 9
//3 2 3
//6 5 10
//6 7 6