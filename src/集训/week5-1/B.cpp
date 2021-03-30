#include <iostream>

using namespace std;

const int maxn = 100000 + 100;

int a[maxn];

int main() {

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] > a[i - 1])
            ans += a[i] - a[i - 1];
    }
    cout << ans << endl;
    return 0;
}