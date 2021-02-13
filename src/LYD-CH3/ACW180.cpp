#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 18;

int a[maxn], n, T;

int f() {
    int t = 0;
    for (int i = 1; i < n; i++)
        if (a[i + 1] != a[i] + 1) t++;
    if (!t)
        return 0;
    else
        return (t - 1) / 3 + 1;
}

bool dfs(int d, int maxd) {
    bool flag = true;
    for (int i = 1; i <= n; i++)
        if (a[i] != i)
            flag = false;
    if (flag) return true;
    if (d >= maxd) return false;
    if (d + f() > maxd) return false;
    int bak[maxn];
    memcpy(bak, a, sizeof a);

    for (int l = 1; l < n; l++)
        for (int r = l; r < n; r++) {
            for (int p = r + 1; p <= n; p++) {
                for (int i = 0; r + i < p; i++)
                    a[l + i] = bak[r + 1 + i];
                for (int i = 0; l + i <= r; i++)
                    a[l + p - r + i] = bak[l + i];
                if (dfs(d + 1, maxd)) return true;
                memcpy(a, bak, sizeof a);
            }
        }
    return false;
}

int main() {

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        bool flag = false;
        for (int d = 0; d <= 4; d++) {
            if (dfs(0, d)) {
                cout << d << endl;
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "5 or more" << endl;
    }

    return 0;
}