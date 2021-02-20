#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 1000 + 100;
int n, q;
int l[maxn], r[maxn];
int minv[maxn];

vector<int> G[maxn];

int match[maxn];
bool vis[maxn];
bool dfs(int x) {

    for (int y : G[x]) {
        if (!vis[y]) {
            vis[y] = true;
            if (!match[y] || dfs(match[y])) {
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> q;

    int a, b, c;

    for (int i = 1; i <= n; i++) {
        l[i] = 1;
        r[i] = n;
    }

    for (int i = 1; i <= q; i++) {
        cin >> a >> b >> c;
        a++, b++, c++;

        for (int j = a; j <= b; j++) {
            minv[j] = max(minv[j], c);
        }

        l[c] = max(l[c], a);
        r[c] = min(r[c], b);
    }

    bool flag = true;

    for (int i = 1; i <= n; i++) {
        if (l[i] > r[i]) {
            flag = false;
        }

        for (int j = l[i]; j <= r[i]; j++) {
            if (minv[j] <= i) {
                G[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if (!dfs(i)) {
            flag = false;
            break;
        }
    }
    if (!flag) {
        for (int i = 1; i <= n; i++)
            cout << -1 << " ";
        cout << endl;
    } else {
        for (int i = 1; i <= n; i++)
            cout << match[i] - 1 << " ";
        cout << endl;
    }

    return 0;
}