#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    string s;
    while (T--) {
        int n;
        cin >> n;
        cin >> s;

        int val = 0;
        bool ok = true;

        for (auto it = s.begin(); it != s.end(); it++) {
            if (*it == 'T') {
                val++;
            } else {
                val--;
            }

            if (val < 0) {
                ok = false;
                break;
            }
        }

        if (val != n / 3) {
            ok = false;
        }

        val = 0;

        for (auto it = s.rbegin(); it != s.rend(); it++) {
            if (*it == 'T') {
                val++;
            } else {
                val--;
            }

            if (val < 0) {
                ok = false;
                break;
            }
        }

        if (val != n / 3) {
            ok = false;
        }

        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}