#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;

int to[maxn], fir[maxn], nxt[maxn], tot;

void add(int a, int b) {
    tot++;
    to[tot] = b, nxt[tot] = fir[a], fir[a] = tot;
    tot++;
    to[tot] = a, nxt[tot] = fir[b], fir[b] = tot;
}

int sg(int u, int f) {
    int res = 0;

    for (int e = fir[u]; e; e = nxt[e]) {
        if (to[e] != f)
            res ^= sg(to[e], u);
    }
    return res + 1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        tot = 0;
        memset(fir, 0, sizeof(fir));

        int n;
        cin >> n;
        int a, b;
        for (int i = 1; i < n; i++) {
            cin >> a >> b;
            add(a, b);
        }

        int res = 0;

        for (int e = fir[1]; e; e = nxt[e]) {
            res ^= sg(to[e], 1);
        }
        if (res == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}