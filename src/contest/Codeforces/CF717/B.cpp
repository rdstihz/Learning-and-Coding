#include <iostream>

using namespace std;

const int maxn = 2000 + 100;

int a[maxn];

int main() {

    int T;
    cin >> T;
    while (T--) {
        int n;
        int v = 0;
        int t;

        cin >> n;

        int sor = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sor ^= a[i];
        }

        if (sor == 0) {
            cout << "YES" << endl;
            continue;
        }

        
        int cur = 0;
        int cnt = 0;

        for (int i = 1; i <= n; i++) {
            cur ^= a[i];

            if(cur == sor) {
                cnt++;
                cur = 0;
            }

        }
        

        if (cur == 0 && cnt > 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}