#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000 + 10;
double f[maxn], m[maxn];
int g[maxn];
int main() {

    int T;
    cin >> T;
    while (T--) {
        int n, p = 0, q = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> g[i];
        }
        for (int i = 1; i <= n; i++) {
            if (g[i] == 0)
                cin >> f[++p];
            else
                cin >> m[++q];
        }

        sort(f + 1, f + 1 + p);
        sort(m + 1, m + 1 + q);
        for (int i = 1; i <= p; i++)
            cout << f[i] << " ";
        cout << endl;
        for (int i = 1; i <= q; i++)
            cout << m[i] << " ";
        cout << endl;
    }

    return 0;
}