#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        cout << 1ll * (n - m) * 500000004 % P << endl;
    }
    return 0;
}