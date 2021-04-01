#include <bits/stdc++.h>

using namespace std;

const int maxn = 50000 + 10;

typedef pair<int, int> Edge;

vector<Edge> G[maxn];

int n, m;

int cnt;

int dfs(int u, int f, int dist, int x) {

    vector<int> s;

    for (Edge e : G[u])
        if (e.first != f) {
            s.push_back(dfs(e.first, u, e.second, x));
        }

    sort(s.begin(), s.end());
    while (s.size() && s.back() >= x) {
        cnt++;
        s.pop_back();
    }
    vector<bool> vis(s.size(), false);

    for (auto i = s.begin(); i != s.end(); i++)
        if (!vis[i - s.begin()]) {
            auto it = lower_bound(i + 1, s.end(), x - *i);
            while (it != s.end() && vis[it - s.begin()] )
                it++;
            if (it != s.end()) {
                cnt++;
                vis[i - s.begin()] = true;
                vis[it - s.begin()] = true;
            }
        }
    int rest = 0;
    for (int i = s.size() - 1; i >= 0; i--)
        if (!vis[i]) {
            rest = s[i];
            break;
        }
    return rest + dist;
}

bool check(int x) {
    cnt = 0;

    dfs(1, 0, 0, x);

    return cnt >= m;
}

int main() {
    cin >> n >> m;

    int u, v, l;

    for (int i = 1; i < n; i++) {
        cin >> u >> v >> l;
        G[u].push_back(make_pair(v, l));
        G[v].push_back(make_pair(u, l));
    }

    int L = 0, R = 500000000 + 100;
    int M;
    while (L < R) {
        M = L + R >> 1;
        if (!check(M)) {
            R = M;
        } else {
            L = M + 1;
        }
    }

    cout << L - 1 << endl;

    return 0;
}