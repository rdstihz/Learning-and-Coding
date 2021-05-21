#include <bits/stdc++.h>

using namespace std;

inline int lowbit(int x) {
    return x & -x;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        int ans = n;

        while (n) {
            int t = lowbit(n);
            n -= t;
            ans = min(ans, n + t - 1);
        }

        cout << ans << endl;
    }

    return 0;
}