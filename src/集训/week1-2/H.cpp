#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 105;
int a[maxn];
bool vis[25000 + 10];
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);

        memset(vis, 0, sizeof(vis));
        vis[0] = true;
        int ans = n;
        for (int i = 1; i <= n; i++) {
            if (vis[a[i]]) {
                ans--;
                continue;
            }
            for (int j = 0; j + a[i] <= 25000; j++)
                vis[j + a[i]] |= vis[j];
        }
        cout << ans << endl;
    }
}