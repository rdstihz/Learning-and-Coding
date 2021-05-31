#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
char s[maxn], ss[maxn];

int main() {
    int T;
    cin >> T;

    while (T--) {

        int n, m;
        cin >> n >> m;

        cin >> (s + 1);
        s[0] = '0';
        s[n + 1] = '0';
        bool changed = false;

        for (int k = 1; k <= m; k++) {
            changed = false;

            for (int i = 1; i <= n; i++) {
                ss[i] = s[i];
                if (s[i] == '0')
                    if (s[i - 1] == '0' && s[i + 1] == '1' || s[i - 1] == '1' && s[i + 1] == '0') {
                        ss[i] = '1';
                        changed = true;
                    }
            }

            if (!changed) break;
            for (int i = 1; i <= n; i++)
                s[i] = ss[i];
        }

        s[n + 1] = 0;
        cout << (s + 1) << endl;
    }

    return 0;
}