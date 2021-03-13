#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 505;
const int INF = 0x3f3f3f3f;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const char dir[] = "urdl";

int n, m;
char str[maxn][maxn];

struct State {
    int x, y;
    int d;
} start, target;

inline bool legal(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && (str[x][y] == '.' || str[x][y] == 'E');
}
inline bool legal2(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && str[x][y] == '.';
}

int dist[maxn][maxn][5];

bool solve() {
    memset(dist, 0x3f, sizeof(dist));
    dist[start.x][start.y][start.d] = 0;

    queue<State> Q;
    Q.push(start);

    while (Q.size()) {
        State node = Q.front();
        Q.pop();

        if (node.d == 4) {
            //立着的
            for (int i = 0; i < 4; i++) {
                int xx = node.x + dx[i];
                int yy = node.y + dy[i];

                if (legal(xx, yy) && legal(xx + dx[i], yy + dy[i])) {
                    if (dist[xx][yy][i] == INF) {
                        dist[xx][yy][i] = dist[node.x][node.y][node.d] + 1;
                        Q.push({xx, yy, i});
                    }
                }
            }
        } else {
            int xx, yy;
            for (int i = 0; i < 4; i++) {
                if (i == node.d) {
                    xx = node.x + 2 * dx[i];
                    yy = node.y + 2 * dy[i];
                    if (legal2(xx, yy) && dist[xx][yy][4] == INF) {
                        dist[xx][yy][4] = dist[node.x][node.y][node.d] + 1;
                        Q.push({xx, yy, 4});
                    }
                } else if (i - node.d == 2 || node.d - i == 2) {
                    xx = node.x + dx[i];
                    yy = node.y + dy[i];
                    if (legal2(xx, yy) && dist[xx][yy][4] == INF) {
                        dist[xx][yy][4] = dist[node.x][node.y][node.d] + 1;
                        Q.push({xx, yy, 4});
                    }
                } else {
                    xx = node.x + dx[i];
                    yy = node.y + dy[i];

                    if (legal(xx, yy) && legal(xx + dx[node.d], yy + dy[node.d])) {
                        if (dist[xx][yy][node.d] == INF) {
                            dist[xx][yy][node.d] = dist[node.x][node.y][node.d] + 1;
                            Q.push({xx, yy, node.d});
                        }
                    }
                }
            }
        }

        if (dist[target.x][target.y][target.d] != INF) return true;
    }

    return false;
}

int main() {

    while (scanf("%d%d", &n, &m), n) {
        
        
        
        for (int i = 1; i <= n; i++)
            scanf("%s", str[i] + 1);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (str[i][j] == 'O') {
                    target.x = i;
                    target.y = j;
                    target.d = 4;
                    str[i][j] = '.';
                } else if (str[i][j] == 'X') {
                    start.x = i;
                    start.y = j;
                    start.d = 4;

                    for (int k = 0; k < 4; k++) {
                        if (str[i + dx[k]][j + dy[k]] == 'X') {
                            start.d = k;
                            str[i + dx[k]][j + dy[k]] = '.';
                        }
                    }
                    str[i][j] = '.';
                }
            }

        if (solve()) {
            printf("%d\n", dist[target.x][target.y][target.d]);
        } else {
            printf("Impossible\n");
        }
    }

    return 0;
}
