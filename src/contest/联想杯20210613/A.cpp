#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;

map<int, int> f;
int a[maxn];

int main() {

    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(f.count(a[i] - k)) {
            f[a[i]] = f[a[i] - k] + 1;
        }else{
            f[a[i]] = 1;
        }
        ans = max(ans, f[a[i]]);
    }

    cout << ans << endl;

    return 0;
}