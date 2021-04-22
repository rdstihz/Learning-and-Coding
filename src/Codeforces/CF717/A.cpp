#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;

int a[maxn];

int main() {

    int n, k;
    int T;
    cin >> T;

    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int pos = 1;

        while (pos < n && k) {
            int t = min(a[pos], k);
            a[pos] -= t;
            k -= t;
            a[n] += t;

            pos++;
        }

        for(int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}