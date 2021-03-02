#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> edge;

const int maxn = 1000000 + 100;
vector<edge> G[maxn];
long long ans;
int n;

int dfs(int u, int f, int l) {
    int cnt = 1;

    for (edge e : G[u]) if(e.first != f){
        cnt += dfs(e.first, u, e.second);
    }

    int t = n - cnt;

    if (t) {
        long long x = abs(t - cnt);
        ans += x * l;
    }

    return cnt;
}

int main() {

    cin >> n;
    int a, b, c;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }

    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}
