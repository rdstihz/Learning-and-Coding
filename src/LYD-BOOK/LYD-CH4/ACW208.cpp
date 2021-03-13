#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int a[50];

int main() {
    int T;
    cin >> T;
    while (T--) {
        
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1, j; i <= n; i++) {
            cin >> j;
            a[i] ^= j;
            a[i] |= 1 << i; //a[i][i] = 1;
        }

        int x, y;
        while (scanf("%d%d", &x, &y), x && y) {
            a[y] |= 1 << x; // a[y][x] = 1
        }
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (a[j] > a[i])
                    swap(a[i], a[j]);
            }
            if (a[i] == 0) {
                ans = 1 << (n - i + 1);
                break;
            }
            if (a[i] == 1) {
                ans = 0;
                break;
            }

            for (int k = n; k >= 1; k--) {
                if (a[i] >> k & 1) {
                    for (int j = 1; j <= n; j++) {
                        if (i == j) continue;
                        if (a[j] >> k & 1)
                            a[j] ^= a[i];
                    }

                    break;
                }
            }
        }
        if (ans == 0) {
            cout << "Oh,it's impossible~!!" << endl;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}