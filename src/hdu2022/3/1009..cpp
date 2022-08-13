#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;

struct Node {
    int l, r, id;

    //按y排序
    bool operator<(const Node& phs) const {
        if(r == phs.r) return l < phs.l;
        return r < phs.r;
    }
    bool operator>(const Node& phs) const {
        return phs<*this;
    }

}a[maxn], b[maxn];

//按l排序
bool cmp(const Node& x, const Node& y) {
    if(x.l == y.l) return x.r < y.r;
    else return x.l < y.l;
}

bool vis[maxn];

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);

    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].l, &a[i].r);
        a[i].id = i;
        b[i] = a[i];
    }

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n, cmp);

    priority_queue<Node, vector<Node>, greater<Node>> Q;

    int ans = 0;
    
    int j = 1;
    for(int i = 1; i <= n; i++) {
        if(vis[a[i].id]) continue;

        ans++;
        vis[a[i].id] = true;

        while(j <= n && b[j].l <= a[i].r) {
            if(vis[b[j].id]) {
                j++;
                continue;
            }
            Q.push(b[j]);
            j++;
        }

        int t = 1;
        while(Q.size() && t < k) {
            Node node = Q.top();
            Q.pop();
            if(vis[node.id]) continue;
            vis[node.id] = true;
            t++;
        }
    }

    printf("%d\n", ans);


    for(int i = 1; i <= n; i++) {
        vis[i] = 0;
    }

}


int main() {
    int T;
    scanf("%d", &T);
    while(T--) 
        solve();
    return 0;
}