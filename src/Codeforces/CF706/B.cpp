#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 100000 + 100;

int a[maxn];

int main() {

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);

        int mex = 0;
        while (a[mex] == mex)
            mex++;
        int maxv = a[n - 1];

        if (mex < maxv) {
            int t = (mex + maxv + 1) / 2;
            if (*lower_bound(a, a + n, t) == t || k == 0) {
                cout << n << endl;
            } else {
                cout << n + 1 << endl;
            }
        } else {
            cout << n + k << endl;
        }
    }

    return 0;
}