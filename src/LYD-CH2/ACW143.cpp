#include <cstdio>
#include <algorithm>


using namespace std;
const int maxn = 1000000 + 10;

int ch[2 * maxn][2];
int tot;
int n;
int root;


void insert(int v) {
    int u = root;

    for (int i = 30; i >= 0; i--) {
        int t = (v >> i) & 1;
        if (!ch[u][t]) ch[u][t] = ++tot;
        u = ch[u][t];
    }

}

int solve(int v) {
    int res = 0;
    int u = root;

    for (int i = 30; i >= 0; i--) {
        int t = (v >> i) & 1;

        if (ch[u][!t]) {
            u = ch[u][!t];
            res |= (1 << i);
        } else {
            u = ch[u][t];
        }

    }
    return res;
}

int main() {

    scanf("%d", &n);
    tot = 0;
    root = ++tot;

    int v;
    scanf("%d", &v);
    insert(v);
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &v);
        ans = max(ans, solve(v));
        insert(v);
    }
    printf("%d\n", ans);
    return 0;
}