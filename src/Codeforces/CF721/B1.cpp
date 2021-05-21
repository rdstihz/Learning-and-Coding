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

        int m = 0;

        for (int i = 1; i <= n; i++)
            m += s[i] == '0';

        if (m == 1 || m % 2 == 0)
            cout << "BOB" << endl;
        else
            cout << "ALICE" << endl;
    }

    return 0;
}