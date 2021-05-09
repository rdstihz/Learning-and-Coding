#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;
int a[maxn];

int main() {

    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int cur = 0;
        int k;
        while (m--) {
            cin >> k;
            cur = (cur + k - 1) % n;
        }
    
        for(int i = 0; i < n; i++) 
            cout << a[(i + cur) % n] << " ";
        cout << endl;
    }

    return 0;
}