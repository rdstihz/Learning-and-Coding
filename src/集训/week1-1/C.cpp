#include <iostream>

using namespace std;

const int maxn = 200000 + 100;

int a[maxn];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = -2147483648;
    int s = 0;
    for (int i = 1; i <= n; i++) {
        if (s < 0)
            s = 0;
        s += a[i];
        ans = max(ans, s);
    }
    cout << ans << endl;

    return 0;
}