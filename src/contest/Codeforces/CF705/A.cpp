#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1000 + 10;

bool vis[maxn];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> ans;

        for (int i = k + 1; i <= n; i++)
            ans.push_back(i);

        memset(vis, 0, sizeof(vis));
        vis[k] = 1;
        for (int i = k - 1; i >= 1; i--) {
            if (!vis[i])
                ans.push_back(i);

            for (int t = i + 1; t <= k; t++)
                if (vis[t])
                    vis[t - i] = 1;
        }
        cout << ans.size() << endl;
        for(int x: ans)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}