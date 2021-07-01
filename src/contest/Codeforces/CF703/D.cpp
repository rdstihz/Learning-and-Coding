#include <iostream>

using namespace std;

const int maxn = 200000 + 10;

int n, k;
int a[maxn];
int b[maxn];
int s[maxn];

bool check(int x) {
    for (int i = 1; i <= n; i++)
        b[i] = a[i] >= x ? 1 : -1;
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + b[i];
    int minv = 0;
    for (int i = k; i <= n; i++) {
        if (s[i] - minv > 0)
            return true;
        minv = min(minv, s[i + 1 - k]);
    }
    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int L = 1, R = n;
    int M;
    while (L < R) {
        M = (L + R + 1) >> 1;
        if (check(M)) {
            L = M;
        } else {
            R = M - 1;
        }
    }
    cout << L << endl;

    return 0;
}