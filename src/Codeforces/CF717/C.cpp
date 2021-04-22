#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 120;

int a[maxn];
bool f[200000 + 10];

int main() {

    int n;
    cin >> n;

    bool odd = false; //是否有奇数
    int pos = 0;      // 奇数的位置
    int S = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        S += a[i];

        if (a[i] % 2 == 1) {
            odd = true;
            pos = i;
        }
    }

    while (!odd) {
        odd = false;
        pos = 0;
        S = 0;

        for (int i = 1; i <= n; i++) {
            a[i] /= 2;
            S += a[i];

            if (a[i] % 2 == 1) {
                odd = true;
                pos = i;
            }
        }
    }

    if (S % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    f[0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = S; j >= a[i]; j--) {
            f[j] |= f[j - a[i]];
        }
    }

    if (f[S / 2]) {
        cout << 1 << endl;
        cout << pos << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}