#include <bits/stdc++.h>


using namespace std;


int main() {
    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;
        int a;
        
        for(int i = 1; i <= n; i++) {
            cin >> a;
        }
        cout << 3 * n << endl;
        n /= 2;
        for(int i = 1; i <= n; i++) {

            for(int k = 1; k <= 3; k++) {
                cout << 1 << " " << 2 * i - 1 << " " << 2 * i << endl;
                cout << 2 << " " << 2 * i - 1 << " " << 2 * i << endl;
            }

        }
    }
    return 0;
}