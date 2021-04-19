#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int a[100000 + 100];

int main() {

    int n;
    cin >> n;

    long long t = 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (gcd(n, i) == 1) {
            cnt++;
            a[cnt] = i;
            t = t * i % n;
        }
    }

    if (t != 1)
        cnt--;

    cout << cnt << endl;
    for (int i = 1; i <= cnt; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}