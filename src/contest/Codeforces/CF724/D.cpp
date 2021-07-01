#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;

int a[maxn];

int main() {

    int T;

    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int v;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        set<int> S;
        S.insert(a[1]);

        bool ok = true;
        for (int i = 2; i <= n; i++) {
            if (a[i] == a[i - 1]) continue;
            if (a[i] > a[i - 1]) {
                auto it = S.upper_bound(a[i - 1]);
                if (it != S.end() && *it < a[i]) {
                    ok = false;
                    break;
                }
            }
            if (a[i] < a[i - 1]) {
                auto it = S.lower_bound(a[i - 1]);
                if (it != S.begin()) {
                    it--;
                    if (*it > a[i]) {
                        ok = false;
                        break;
                    }
                }
            }

            S.insert(a[i]);
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}