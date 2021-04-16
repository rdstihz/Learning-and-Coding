#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000 + 100;

int a[maxn];

int main() {

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for(int i = 1;i <= n; i++) {
            cin >> a[i];
        }

        for(int i = 1;i <= n; i++)
            if(a[i] % 2)
                cout << a[i] << " ";
        
        for(int i = 1;i <= n; i++)
            if(a[i] % 2 == 0)
                cout << a[i] << " ";
        
        cout << endl;

    }
    


    return 0;
}