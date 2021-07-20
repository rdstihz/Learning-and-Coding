#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
const int M = 1e6 + 10;
int n, m, k;
struct edge {
    int u, v, w;
    edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        w = _w;
    }
    bool operator<(const edge& u) const {
        return w < u.w;
    }
};
vector<edge> e;
int s[N];

int find_set(int x) {
    if (x != s[x]) return s[x] = find_set(s[x]);
    return s[x];
}
int readIn() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
int main() {
    int T;
    T = readIn();
    while (T--) {
        n = readIn();
        m = readIn();
        k = readIn();
        e.clear();
        for (int i = 1; i <= m; i++) {
            int u, v, x;
            u = readIn();
            v = readIn();
            x = readIn();
            e.push_back(edge(u, v, x));
        }
        sort(e.begin(), e.end());
        int cnt = n;
        for (int i = 1; i <= n; i++) {
            s[i] = i;
        }
        for (int i = 0; i < m; i++) {
            int u = e[i].u, v = e[i].v;
            int x = find_set(u), y = find_set(v);
            if (x != y) {
                s[x] = y;
                --cnt;
            }
            int l = i + 1;
            while (l < m && e[l].w == e[l - 1].w) {
                u = e[l].u, v = e[l].v;
                x = find_set(u), y = find_set(v);
                if (x != y) {
                    s[x] = y;
                    --cnt;
                }
                l++;
            }
            if (cnt == k) {
                printf("%d\n", e[i].w);
                goto g1;
            } else if (cnt < k) {
                printf("%d\n", -1);
                goto g1;
            }
            i = l - 1;
        }
        printf("-1\n");
    g1:;
    }
    return 0;
}