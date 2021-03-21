#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000000 + 100;
bool flag[maxn];
int main() {
    unsigned l, r;
    cin >> l >> r;

    unsigned t = sqrt(r);

    for (unsigned i = 2; i <= t; i++) {
        unsigned start = max(2u, (l - 1) / i + 1) * i;
        for (unsigned j = start; j <= r; j += i)
            flag[j - l] = true;
    }

    int ans = 0;
    for(int i = l; i <= r; i++)
        if(!flag[i - l])
            ans++;
    cout << ans << endl;

    return 0;
}