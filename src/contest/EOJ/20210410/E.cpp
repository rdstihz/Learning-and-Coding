#include <iostream>

using namespace std;

const int maxn = 100000 + 100;

int fir[maxn], nxt[2 * maxn];
int to[2 * maxn];
int tot;

void add(int u, int v) {
    tot++;
    to[tot] = v;

    nxt[tot] = fir[u];
    fir[u] = tot;
}

int d[maxn];

void dfs(int u, int f) {

    for (int e = fir[u]; e; e = nxt[e]) {
        int v = to[e];
        if (v != f) {
            d[v] = d[u] + 1;
            dfs(v, u);
        }
    }
}

int main() {

    int n;
    cin >> n;
    int u, v;

    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }

    cin >> u >> v;
    dfs(u, 0);
    if (d[v] % 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}