#include <bits/stdc++.h>

using namespace std;

bool vis[200];
int a[200];

int main() {

    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;
        bool flag = true;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(a[i] < 0) flag = false;
        }

        if(!flag) cout << "No" << endl;
        else {
            cout << "Yes" << endl;
            cout << 101 << endl;
            for(int i = 0; i <= 100; i++)
                cout << i << " ";
            cout << endl;
        }

    }

    return 0;
}