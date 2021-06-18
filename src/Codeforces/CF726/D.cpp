#include <bits/stdc++.h>

using namespace std;

int sg[1000];
bool vis[1000];
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        if (n % 2)
            cout << "Bob" << endl;
        else {
            int l = 0;
            while (n && (n % 2) == 0) {
                l++;
                n >>= 1;
            }

            //cout << l << " " << n << endl;
            if (n != 1 || (l % 2 == 0))
                cout << "Alice" << endl;
            else
                cout << "Bob" << endl;
        }
    }
    return 0;
}