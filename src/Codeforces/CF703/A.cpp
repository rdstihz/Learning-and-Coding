#include <iostream>

using namespace std;

const int maxn = 110;

long long h[maxn];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> h[i];

        h[0] = -1;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (h[i] < h[i - 1] + 1) {
                flag = false;
                break;
            }
            long long  t = h[i] - (h[i - 1] + 1);
            h[i] -= t;
            h[i + 1] += t;
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}