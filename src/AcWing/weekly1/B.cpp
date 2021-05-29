#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;

typedef long long LL;

LL a[maxn];

LL n, k;

bool check(LL x) {
    LL cnt = 0;

    for(int i = (n + 1)/ 2; i <= n; i++)
        if(a[i] < x) cnt += x - a[i];
    return cnt <= k;
}

int main() {

    
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);
    LL l = a[(n + 1) / 2], r = l + k + 1;
    LL m;

    while (l < r) {
        m = l + r + 1 >> 1;
        if (check(m))
            l = m;
        else
            r = m - 1;
    }

    cout << l << endl;

    return 0;
}