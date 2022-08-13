#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
const int maxn = 300;
const int INF = 0x3f3f3f3f;
int id[20][20];
int dis[maxn][maxn];
int d[maxn];


struct Wall{
    int x1, y1, x2, y2;
} w[20];

int n, m, k;
int xs, ys, xt, yt;

int wr[20][20];
int wc[20][20];

bool vis[20][20];

void dfs(int x, int y) {
    vis[x][y] = 1;

    //上
    if(x < n - 1 && !wr[x + 1][y] && !vis[x + 1][y]) 
        dfs(x + 1, y); 
    //下
    if(x > 0 && !wr[x][y] && !vis[x - 1][y]) 
        dfs(x - 1, y); 
    //左
    if(y > 0 && !wc[x][y] && !vis[x][y - 1])
        dfs(x, y - 1);
    //右
    if(y < m - 1 && !wc[x][y + 1] && !vis[x][y + 1])
        dfs(x, y + 1);
} 

bool check() {
    memset(vis, 0, sizeof(vis));
    dfs(xs, ys);
    return vis[xt][yt];
}


void solve() {
    scanf("%d%d%d", &n, &m, &k);
    scanf("%d%d%d%d", &xs, &ys, &xt, &yt);

    for(int i = 0; i < k; i++) {
        scanf("%d%d%d%d", &w[i].x1, &w[i].y1, &w[i].x2, &w[i].y2);
    }

    int ans = 20;
    //枚举删掉的墙
    for(int s = 0; s < (1 << k); s++) {
        int ones = 0;
        for(int i = 0; i < k; i++) {
            if(s >> i & 1) ones++;
        }
        if(ones >= ans) continue;
        memset(wr, 0, sizeof(wr));
        memset(wc, 0, sizeof(wc));
        
        for(int i = 0; i < k; i++) {
            if(s >> i & 1) continue;
            int x1 = w[i].x1, y1 = w[i].y1, x2 = w[i].x2, y2 = w[i].y2;

            if(x1 == x2) { //横
                if(y1 > y2) swap(y1, y2);
                for(int j = y1; j < y2; j++) 
                    wr[x1][j] = 1;
            }
            if(y1 == y2) { //竖
                if(x1 > x2) swap(x1, x2);
                for(int j = x1; j < x2; j++)
                    wc[j][y1] = 1;
            }

        }
        if(check()) ans = ones;
    }

    printf("%d\n", ans);
}



int main() {
    int T;
    scanf("%d", &T);
    while(T--)
        solve();
}