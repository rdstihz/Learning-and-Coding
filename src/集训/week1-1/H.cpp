#include <iostream>

using namespace std;

const int maxn = 10000 + 100;
int a[maxn], b[maxn];
long long f[maxn];

int main() {
    int m, n;
    cin >> m >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            for (int t = 1; t * a[i] <= j; t++) {
                f[j] = max(f[j], f[j - t * a[i]] + t * b[i]);
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}
