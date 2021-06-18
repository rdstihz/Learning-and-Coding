#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        int S = 0, v;
        for (int i = 1; i <= n; i++) {
            cin >> v;
            S += v;
        }

        if (S == n)
            cout << 0 << endl;
        else if (S < n)
            cout << 1 << endl;
        else
            cout << S - n << endl;
    }

    return 0;
}