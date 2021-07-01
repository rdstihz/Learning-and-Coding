#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

map<LL, LL> M;

int main() {
    int n;
    int T;
    cin >> T;

    while (T--) {
        cin >> n;
        M.clear();
        LL v;
        LL ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> v;
            if (M.count(v)) {
                ans += (LL)(n - i + 1) * M[v];
                M[v] += i;
            } else {
                M[v] = i;
            }
        }
        cout << ans << endl;
    }

    return 0;
}