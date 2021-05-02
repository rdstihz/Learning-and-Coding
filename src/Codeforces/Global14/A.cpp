#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 100 + 10;

int a[maxn];

int main() {

    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        int S = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            S += a[i];
        }

        if (S == x) {
            cout << "NO" << endl;
            continue;
        } else if (S < x) {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << endl;
            continue;
        }

        sort(a + 1, a + 1 + n);

        int cur = 0;
        for (int i = 1; i <= n; i++) {
            cur += a[i];
            if (cur == x) {
                swap(a[i], a[i + 1]);
                break;
            }
        }
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
    }

    return 0;
}