#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;

int a[maxn];

int main() {

    int T;

    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++)
            cin >> a[i];

        bool flag = true;

        for(int i = 1;i <= n; i++)  {
            int t = sqrt(a[i]);
            if(t * t != a[i]) {
                flag = false;
                break;
            }
        }

        if(flag) {
            cout  << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }

    }
    

    return 0;
}