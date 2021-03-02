#include <iostream>

using namespace std;

const int maxn = 100000 + 10;

int a[maxn];
int c[2 * maxn];
int gt[maxn], lt[maxn];

int main() {
    int n, b;
    cin >> n >> b;
    int pos;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < b)
            a[i] = -1;
        else if (a[i] > b) {
            a[i] = 1;
        } else {
            a[i] = 0;
            pos = i;
        }
    }
    int s = 0;
    for (int i = pos; i >= 1; i--) {
        s += a[i];
        c[s + n]++;
    }
    s = 0;
    int ans = 0;
    for (int i = pos; i <= n; i++) {
        s += a[i];
        ans += c[n - s];
    }
    cout << ans << endl;
    return 0;
}