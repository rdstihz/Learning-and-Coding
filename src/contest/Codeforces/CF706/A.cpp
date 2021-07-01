#include <iostream>

using namespace std;

char s[200];

int main() {

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        cin >> (s + 1);

        int i = 1, j = n;
        int cnt = 0;

        
        if (2 * k >= n) {
            cout << "NO" << endl;
            continue;
        }

        bool flag = true;
        for (int i = 0; i < k; i++) {
            if (s[1 + i] != s[n - i]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}