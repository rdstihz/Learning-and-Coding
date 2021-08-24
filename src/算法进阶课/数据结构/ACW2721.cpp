#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
const int INF = 0x3f3f3f3f;
int a[maxn];
int val[maxn], lc[maxn], rc[maxn], dis[maxn];
int cost[maxn][maxn];
int f[maxn][13];

struct Segment{
    int root;
    int tot_size, tot_sum;
    int tree_size, tree_sum;
    
    int get_cost() {
        int mid = val[root];
        return mid * tree_size - tree_sum + tot_sum - tree_sum - mid * (tot_size - tree_size);
    }
    
    void operator+=(const Segment& phs) {
        tot_size += phs.tot_size;
        tot_sum += phs.tot_sum;
        tree_size += phs.tree_size;
        tree_sum += phs.tree_sum;
    }
}st[maxn];
int n, k;

int merge(int x,int y) {
    if(!x || !y) return x | y;
    if(val[x] < val[y]) swap(x, y);
    rc[x] = merge(rc[x], y);
    if(dis[lc[x]] < dis[rc[x]]) swap(lc[x], rc[x]);
    dis[x] = dis[rc[x]] + 1;
    return x;
}

void get_cost(int u) {
    int res = 0, top = 0;
    for(int i = u; i <= n; i++) {
        Segment cur = Segment({i, 1, val[i], 1, val[i]});
        lc[i] = rc[i] = 0, dis[i] = 1;
        while(top && val[st[top].root] > val[cur.root]) {
            res -= st[top].get_cost();
            cur.root = merge(cur.root, st[top].root);
            bool is_pop = (cur.tot_size % 2) && (st[top].tot_size % 2);
            cur += st[top];
            if(is_pop) {
                cur.tree_size--;
                cur.tree_sum -= val[cur.root];
                cur.root = merge(lc[cur.root], rc[cur.root]);
            }
            top--;
        }
        res += cur.get_cost();
        cost[u][i] = min(cost[u][i], res);
        st[++top] = cur;
    }
    
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    
    //get cost
    memset(cost, 0x3f, sizeof(cost));
    for(int i = 1; i <= n; i++)
        val[i] = a[i] - i;
    for(int i = 1; i <= n; i++)
        get_cost(i);
    
    for(int i = 1; i <= n; i++)
        val[i] = -a[i] - i;
    for(int i = 1; i <= n; i++)
        get_cost(i);
    // for(int i = 1; i <= n; i++)
    //     printf("%d ", cost[1][i]);
    // printf("\n");
    
    
    //Dp
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k; j++) 
            for(int t = 1; t <= i; t++)
                f[i][j] = min(f[i][j], f[i - t][j - 1] + cost[i - t + 1][i]);
    //printf("%d %d\n", n, k);
    printf("%d\n", f[n][k]);
    return 0;
}