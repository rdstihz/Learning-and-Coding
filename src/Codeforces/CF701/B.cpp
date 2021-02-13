#include <iostream>

using namespace std;

const int maxn = 100000 + 10;

int a[maxn];

int main(){
    int n,q,k;
    cin >> n >> q >> k;
    for(int i = 1; i <= n;i++)
        cin >> a[i];
    
    int l,r;
    while(q--) {
        cin >> l >> r;

        cout << k + 1 + a[r] - a[l] - 2 * (r - l + 1) << endl;

    }

    return 0;
}