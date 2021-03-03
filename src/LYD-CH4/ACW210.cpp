#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 10000 + 100;
typedef unsigned long long LL;
LL a[maxn];

int main() {
    int T;
    cin >> T;

    for (int kase = 1; kase <= T; kase++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int cnt = 0;
        bool zero = false;
        vector<LL> e;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++)
                if (a[j] > a[i])
                    swap(a[i], a[j]);
            if (a[i] == 0) {
                zero = true;
                break;
            }
            cnt++;
            int tmp;
            for (int k = 63; k >= 0; k--)
                if (a[i] >> k & 1) {
                    tmp = k;
                    break;
                }

            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (a[j] >> tmp & 1)
                    a[j] ^= a[i];
            }
        }

        for (int i = cnt; i >= 1; i--) {
            e.push_back(a[i]);
        }

        // for (int x : e) {
        //     cout << x << " ";
        // }
        // cout << endl;

        cout << "Case #" << kase << ":" << endl;
        int q;
        cin >> q;
        while (q--) {
            LL x, ans = 0;
            cin >> x;

            if (zero) x--;
            if (x >= 1ll << cnt) {
                cout << -1 << endl;
                continue;
            }
            for (int i = 0; i < cnt; i++)
                if (x >> i & 1)
                    ans ^= e[i];
            cout << ans << endl;
        }
    }

    return 0;
}