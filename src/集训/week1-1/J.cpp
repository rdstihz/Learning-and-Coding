#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1000000 + 100;

vector<int> G[maxn];
vector<int> ans;
int n;

int dfs(int u, int f) {
    int cnt = 1;
    int cur = 0;
    bool flag = true;
    for (int v : G[u])
        if (v != f) {
            int t = dfs(v, u);
            cnt += t;

            if (cur == 0 || cur == t) {
                cur = t;
            } else {
                flag = false;
            }
        }
    if(flag && (cur == 0 || n - cnt == 0 || cur == n - cnt)) {
        ans.push_back(u);
    }

    return cnt;
}

int main() {

    cin >> n;
    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1, 0);
    sort(ans.begin(), ans.end());

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}