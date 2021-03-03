#include <iostream>

using namespace std;

const int maxn = 10000 + 100;
int a[maxn], b[maxn];
long long f[10000000 + 10];

int main() {
    int m, n;
    cin >> m >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(j >= a[i]) f[j] = max(f[j], f[j - a[i]] + b[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}
