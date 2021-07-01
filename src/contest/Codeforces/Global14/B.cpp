#include <bits/stdc++.h>

using namespace std;

int main() {

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        bool ok = false;
        if (n % 2 == 0) {
            int t = sqrt(n / 2);
            if (t * t == n / 2)
                ok = true;
        }

        if (n % 4 == 0) {
            int t = sqrt(n / 4);
            if (t * t == n / 4)
                ok = true;
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}