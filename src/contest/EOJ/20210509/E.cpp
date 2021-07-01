#include <bits/stdc++.h>

using namespace std;

const int maxn = (1 << 17) + 100;

int a[maxn], b[maxn];
long long  cnt[20];
long long f[20];

void mergesort(int l, int r, int d) {
    if (d == 0) return;

    int m = l + r >> 1;
    mergesort(l, m, d - 1);
    mergesort(m + 1, r, d - 1);

    int i = l, j = m + 1;
    int k = l;

    while (i <= m && j <= r) {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else {
            cnt[d] += m - i + 1;
            b[k++] = a[j++];
        }
    }

    while (i <= m)
        b[k++] = a[i++];
    while (j <= r)
        b[k++] = a[j++];

    for (int i = l; i <= r; i++)
        a[i] = b[i];
}

int main() {

    int n, m;
    while (cin >> n >> m) {
        for (int i = 1; i <= (1 << n); i++)
            cin >> a[i];
        memset(cnt, 0, sizeof(cnt));
        mergesort(1, 1 << n, n);

        
        
        
        
        for (int d = 1; d <= n; d++) {
            long long len = 1 << d - 1;
            f[d] = len * len  * (1 << n - d);
        }

        // ----
        // for(int i  = 0; i <= n; i++)
        //     cout << f[i] << " ";
        // cout << endl;
        // for(int i = 0; i <= n; i++)
        //     cout << cnt[i] << " ";
        // cout << endl;
        //----

        long long S = 0;
        for(int i = 0; i <= n; i++)
            S += cnt[i];
        int t;
        for( int i = 1; i <= m; i++) {
            cin >> t;
            for(int d =0; d <= t; d++) {
                S -= cnt[d];
                cnt[d] = f[d] - cnt[d];
                S += cnt[d];
            }

            cout << S << endl;
        }
    }

    return 0;
}

/*
2 3
4 3 2 1
1 1 0
2 3
1 4 2 3
0 1 2

*/