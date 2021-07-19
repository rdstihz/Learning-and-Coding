#include <bits/stdc++.h>

using namespace std;
const int maxn = 1000 + 10;
int a[maxn][maxn];
int n, m;

struct Node {
    int x, y, d;
    Node() {
        x = y = d = 0;
    }
    Node(int x, int y, int d) : x(x), y(y), d(d) {}
    bool operator==(const Node& phs) const {
        return x == phs.x && y == phs.y && d == phs.d;
    }
};

Node pre[maxn][maxn][12];
bool vis[maxn][maxn][12];
int dist[maxn][maxn][12];
Node start, target;

inline bool legal(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

queue<Node> Q;

bool bfs() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int d = 0; d < 12; d++)
                vis[i][j][d] = dist[i][j][d] = 0;
    while (Q.size())
        Q.pop();

    if (a[1][1] == 4 || a[1][1] == 5) {
        start = Node(1, 1, 5);
        Q.push(Node(1, 1, 5));
        vis[1][1][5] = true;
        dist[1][1][5] = 1;
    } else {
        start = Node(1, 1, 7);
        Q.push(Node(1, 1, 7));
        vis[1][1][7] = true;
        dist[1][1][7] = 1;
    }

    while (Q.size()) {
        Node u = Q.front();
        Q.pop();

        if (u == Node(n, m, 3) || u == Node(n, m, 5)) {
            target = u;
            return true;
        }

        if (u.d == 0 || u.d == 9 || u.d == 10) { //向左
            int xx = u.x, yy = u.y - 1;
            if (!legal(xx, yy)) continue;
            if (a[xx][yy] == 4 || a[xx][yy] == 5) {
                if (!vis[xx][yy][10]) {
                    pre[xx][yy][10] = u;
                    Q.push(Node(xx, yy, 10));
                    vis[xx][yy][10] = true;
                    dist[xx][yy][10] = dist[u.x][u.y][u.d] + 1;
                }
            } else {
                if (!vis[xx][yy][1]) {
                    pre[xx][yy][1] = u;
                    Q.push(Node(xx, yy, 1));
                    vis[xx][yy][1] = true;
                    dist[xx][yy][1] = dist[u.x][u.y][u.d] + 1;
                }
                if (!vis[xx][yy][8]) {
                    pre[xx][yy][8] = u;
                    Q.push(Node(xx, yy, 8));
                    vis[xx][yy][8] = true;
                    dist[xx][yy][8] = dist[u.x][u.y][u.d] + 1;
                }
            }
        } else if (u.d == 1 || u.d == 6 || u.d == 11) { // 向上
            int xx = u.x - 1, yy = u.y;
            if (!legal(xx, yy)) continue;
            if (a[xx][yy] == 4 || a[xx][yy] == 5) {
                if (!vis[xx][yy][11]) {
                    pre[xx][yy][11] = u;
                    Q.push(Node(xx, yy, 11));
                    vis[xx][yy][11] = true;
                    dist[xx][yy][11] = dist[u.x][u.y][u.d] + 1;
                }
            } else {
                if (!vis[xx][yy][2]) {
                    pre[xx][yy][2] = u;
                    Q.push(Node(xx, yy, 2));
                    vis[xx][yy][2] = true;
                    dist[xx][yy][2] = dist[u.x][u.y][u.d] + 1;
                }
                if (!vis[xx][yy][9]) {
                    pre[xx][yy][9] = u;
                    Q.push(Node(xx, yy, 9));
                    vis[xx][yy][9] = true;
                    dist[xx][yy][9] = dist[u.x][u.y][u.d] + 1;
                }
            }
        } else if (u.d == 2 || u.d == 4 || u.d == 7) { //向右
            int xx = u.x, yy = u.y + 1;
            if (!legal(xx, yy)) continue;
            if (a[xx][yy] == 4 || a[xx][yy] == 5) {
                if (!vis[xx][yy][4]) {
                    pre[xx][yy][4] = u;
                    Q.push(Node(xx, yy, 4));
                    vis[xx][yy][4] = true;
                    dist[xx][yy][4] = dist[u.x][u.y][u.d] + 1;
                }
            } else {
                if (!vis[xx][yy][3]) {
                    pre[xx][yy][3] = u;
                    Q.push(Node(xx, yy, 3));
                    vis[xx][yy][3] = true;
                    dist[xx][yy][3] = dist[u.x][u.y][u.d] + 1;
                }
                if (!vis[xx][yy][6]) {
                    pre[xx][yy][6] = u;
                    Q.push(Node(xx, yy, 6));
                    vis[xx][yy][6] = true;
                    dist[xx][yy][6] = dist[u.x][u.y][u.d] + 1;
                }
            }
        } else if (u.d == 3 || u.d == 5 || u.d == 8) { //向下
            int xx = u.x + 1, yy = u.y;
            if (!legal(xx, yy)) continue;
            if (a[xx][yy] == 4 || a[xx][yy] == 5) {
                if (!vis[xx][yy][5]) {
                    pre[xx][yy][5] = u;
                    Q.push(Node(xx, yy, 5));
                    vis[xx][yy][5] = true;
                    dist[xx][yy][5] = dist[u.x][u.y][u.d] + 1;
                }

            } else {
                if (!vis[xx][yy][0]) {
                    pre[xx][yy][0] = u;
                    Q.push(Node(xx, yy, 0));
                    vis[xx][yy][0] = true;
                    dist[xx][yy][0] = dist[u.x][u.y][u.d] + 1;
                }
                if (!vis[xx][yy][7]) {
                    pre[xx][yy][7] = u;
                    Q.push(Node(xx, yy, 7));
                    vis[xx][yy][7] = true;
                    dist[xx][yy][7] = dist[u.x][u.y][u.d] + 1;
                }
            }
        }
    }
    return false;
}

void print(const Node& cur) {
    if (cur == start) {
        int t1 = a[cur.x][cur.y] % 6;
        int t2 = cur.d % 6;
        int deg;
        if (t1 < 4)
            deg = ((t2 - t1 + 4) % 4) * 90;
        else
            deg = t1 == t2 ? 0 : 90;
        a[cur.x][cur.y] = t2;
        printf("1 %d %d %d\n", deg, cur.x, cur.y);
        printf("0 %d %d\n", cur.x, cur.y);
    } else {
        print(pre[cur.x][cur.y][cur.d]);
        int t1 = a[cur.x][cur.y] % 6;
        int t2 = cur.d % 6;
        int deg;
        if (t1 < 4)
            deg = ((t2 - t1 + 4) % 4) * 90;
        else
            deg = t1 == t2 ? 0 : 90;
        a[cur.x][cur.y] = t2;
        printf("1 %d %d %d\n", deg, cur.x, cur.y);
        printf("0 %d %d\n", cur.x, cur.y);
    }
}
int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &a[i][j]);
        if (bfs()) {
            printf("YES\n");
            printf("%d\n", dist[target.x][target.y][target.d] * 2);
            print(target);
        } else {
            printf("NO\n");
        }
    }

    return 0;
}