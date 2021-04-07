#include <iostream>
#include <vector>

using namespace std;

const int maxn = 100000 + 100;

vector<int> G[maxn];

char s[maxn];

int n, m;

int st[maxn][17];
int dep[maxn];
int cntG[maxn], cntH[maxn];

void dfs(int u, int f) {

    for (int v : G[u])
        if (v != f) {
            dep[v] = dep[u] + 1;
            st[v][0] = u;

            cntG[v] = cntG[u];
            cntH[v] = cntH[u];

            if (s[v] == 'G')
                cntG[v]++;
            else
                cntH[v]++;

            dfs(v, u);
        }
}

int LCA(int a, int b) {

    if (dep[a] < dep[b])
        swap(a, b);

    int dd = dep[a] - dep[b];

    for (int i = 0; i <= 16; i++)
        if ((dd >> i) & 1)
            a = st[a][i];
    if (a == b) return a;
    for (int i = 16; i >= 0; i--) {
        if (st[a][i] != st[b][i]) {
            a = st[a][i];
            b = st[b][i];
        }
    }
    return st[a][0];
}

int main() {

    cin >> n >> m;
    cin >> (s + 1);

    int a, b;
    char c;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dep[1] = 0;
    if (s[1] == 'G') {
        cntG[1] = 1;
    } else {
        cntH[1] = 1;
    }
    dfs(1, 0);

    for (int k = 1; k <= 16; k++) {
        for (int i = 1; i <= n; i++) {
            st[i][k] = st[st[i][k - 1]][k - 1];
        }
    }

    while (m--) {
        cin >> a >> b >> c;

        int lca = LCA(a, b);

        if (c == 'G') {
            int t = cntG[a] + cntG[b] - 2 * cntG[lca];
            if (s[lca] == 'G') t++;
            if(t > 0)
                cout << 1;
            else
                cout << 0;
        }else if (c == 'H') {
            int t = cntH[a] + cntH[b] - 2 * cntH[lca];
            if (s[lca] == 'H') t++;
            if(t > 0)
                cout << 1;
            else
                cout << 0;
        }
    }

    return 0;
}