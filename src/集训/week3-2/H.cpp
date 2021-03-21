#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;

int a[maxn],b[maxn];
long long ans;


void sort(int l, int r) {
    if (l == r)
        return;
    int m = l + r >> 1;
    sort(l, m);
    sort(m + 1, r);
    int i = l, j = m + 1;
    int k = l;
    while (i <= m && j <= r) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else {
            b[k++] = a[j++];
            ans += m - i + 1;
        }
    }
    while (i <= m)
        b[k++] = a[i++];
    while (j <= r)
        b[k++] = a[j++];
    for(int i = l; i <= r; i++)
        a[i] = b[i];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= m;
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++)
        a[i] = -a[i];
    ans = 0;
    sort(0, n);
    cout << ans % 92084931 << endl;
    return 0;
}