#include <iostream>

using namespace std;

typedef long long LL;

int n;
LL k;

void dfs(int d, LL k) {
    if (d > n)
        return;

    if (n - d >= 63) {
        cout << d << " ";
        dfs(d + 1, k);
        return;
    }

    int r = d;

    while (r < n && 1ll << (n - r - 1) <= k) {
        k -= 1ll << (n - r - 1);
        r++;
    }

    for (int i = r; i >= d; i--)
        cout << i << " ";
    dfs(r + 1, k);
}

int main() {

    cout << (1ll << (-1)) <<endl;

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;

        if (n < 63 && 1ll << (n - 1) < k) {
            cout << -1 << endl;
            continue;
        }

        dfs(1, k - 1);
        cout << endl;
    }

    return 0;
}