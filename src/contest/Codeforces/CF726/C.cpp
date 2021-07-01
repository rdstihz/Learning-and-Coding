#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;

int a[maxn];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n);

        int minv = 1e9;
        int pos;
        for (int i = 1; i < n; i++)
            if (a[i + 1] - a[i] < minv) {
                minv = a[i + 1] - a[i];
                pos = i;
            }
        cout << a[pos] << " ";

        for (int i = pos + 2; i <= n; i++)
            cout << a[i] << " ";
        for (int i = 1; i < pos; i++)
            cout << a[i] << " ";

        cout << a[pos + 1];
        cout << endl;
    }

    return 0;
}