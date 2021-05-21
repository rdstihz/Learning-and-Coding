#include <bits/stdc++.h>

using namespace std;

char s[10000];
int f[10000];

int main() {

    int T;
    int n;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        cin >> (s + 1);

        int t = 0;

        for (int i = 1; i <= n / 2; i++) {
            if (s[i] != s[n + 1 - i]) {
                t++;
                s[i] = s[n + 1 - i] = '1';
            }
        }

        int m = 0;

        for (int i = 1; i <= n; i++)
            m += s[i] == '0';

        if (m == 0) {
            cout << "ALICE" << endl;
        } else if (m == 1) {
            if (t == 1)
                cout << "DRAW" << endl;
            else if (t < 1)
                cout << "BOB" << endl;
            else
                cout << "ALICE" << endl;
        } else if (m % 2 == 0) {
            if (t == 2)
                cout << "DRAW" << endl;
            else if (t < 2)
                cout << "BOB" << endl;
            else
                cout << "ALICE" << endl;
        } else if (m % 2 == 1) {
            cout << "ALICE" << endl;
        }
    }

    return 0;
}