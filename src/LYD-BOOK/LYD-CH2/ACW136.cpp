#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 10;

int a[maxn], q[maxn], pos[maxn];

int nxt[maxn], pre[maxn];

int v[maxn], p[maxn];
int n;

bool cmp(int x, int y) {
    return a[x] < a[y];
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        q[i] = i;
    }

    sort(q + 1, q + 1 + n, cmp);

    for (int i = 1; i <= n; i++) {
        pos[q[i]] = i;
        nxt[i] = i + 1;
        pre[i] = i - 1;
    }
    nxt[n] = 0;



    for (int u = n; u >= 2; u--) {
        int i = pos[u];
        int l = pre[i];
        int r = nxt[i];

        if ( l == 0 || r != 0 &&  a[q[r]] - a[q[i]] < a[q[i]] - a[q[l]] ) {
            v[u] = a[q[r]] - a[q[i]];
            p[u] = q[r];
        } else {
            v[u] = a[q[i]] - a[q[l]];
            p[u] = q[l];
        }

        if(l) nxt[l] = r;
        if(r) pre[r] = l;

    }
    for(int i = 2; i <= n; i++) {
        cout << v[i] << " " << p[i] << endl;
    }
    return 0;
}