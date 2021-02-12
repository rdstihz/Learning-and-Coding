#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int maxn = 25;

struct Node {
    int x, y;
    int dir;
};

char str[maxn][maxn];
int n, m;

inline bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && str[x][y] != '#';
}

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
const char dir[] = {'n', 's', 'w', 'e'};

bool vis[maxn][maxn][4]; //
PII dist[maxn][maxn][4];
string path[maxn][maxn][4];
Node pre[maxn][maxn][4];

PII last[maxn][maxn];
int len[maxn][maxn];
bool vis_man[maxn][maxn];
char op[maxn][maxn];

int bfs_man(PII st, PII ed, PII box, string& seq) {

    memset(len, 0x3f, sizeof len);
    len[st.first][st.second] = 0;
    queue<PII> Q;
    Q.push(st);

    while (Q.size()) {
        PII u = Q.front();
        Q.pop();

        if (u == ed) {
            seq = "";
            while (u != st) {
                seq += op[u.first][u.second];
                u = last[u.first][u.second];
            }
            return len[ed.first][ed.second];
        }

        for (int i = 0; i < 4; i++) {
            int a = u.first - dx[i], b = u.second - dy[i];
            if (check(a, b) && !(a == box.first && b == box.second)) {
                if (len[a][b] > len[u.first][u.second] + 1) {
                    len[a][b] = len[u.first][u.second] + 1;
                    last[a][b] = u;
                    op[a][b] = dir[i];
                    Q.push(make_pair(a, b));
                }
            }
        }
    }
    return -1;
}

bool bfs_box(PII man, PII box, Node& end) {
    memset(vis, 0, sizeof(vis)); // 标记节点是否进过队列，防止重复入队
    queue<Node> Q;

    //将初始状态入队
    string seq;
    for (int i = 0; i < 4; i++) {
        //人的位置
        int a = box.first + dx[i], b = box.second + dy[i];
        //箱子推去的位置
        int j = box.first - dx[i], k = box.second - dy[i];

        if (check(a, b) && check(j, k)) {
            int t = bfs_man(man, {a, b}, box, seq);
            if (t != -1) {
                dist[j][k][i] = make_pair(1, t + 1);
                pre[j][k][i] = {box.first, box.second, -1};
                path[j][k][i] = seq;

                vis[j][k][i] = true;
                Q.push({j, k, i});
            }
        }
    }

    bool succeed = false;
    PII man_d = {1e9, 1e9};

    while (Q.size()) {
        Node t = Q.front();
        Q.pop();
        if (str[t.x][t.y] == 'T') {
            if (man_d > dist[t.x][t.y][t.dir]) {
                succeed = true;
                man_d = dist[t.x][t.y][t.dir];
                end = t;
            }
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int a = t.x + dx[i], b = t.y + dy[i];
            int j = t.x - dx[i], k = t.y - dy[i];

            if (check(a, b) && check(j, k)) {
                int distance = bfs_man({t.x + dx[t.dir], t.y + dy[t.dir]}, {a, b}, {t.x, t.y}, seq);
                if (distance != -1) {
                    PII d = make_pair(dist[t.x][t.y][t.dir].first + 1,
                                      dist[t.x][t.y][t.dir].second + distance + 1);

                    if (!vis[j][k][i]) {
                        vis[j][k][i] = true;

                        dist[j][k][i] = d;
                        path[j][k][i] = seq;
                        pre[j][k][i] = t;

                        Q.push({j, k, i});

                    } else if (dist[j][k][i] > d) {
                        dist[j][k][i] = d;
                        pre[j][k][i] = t;
                        path[j][k][i] = seq;
                    }
                }
            }
        }
    }

    return succeed;
}

int main() {
    int T = 0;
    while (cin >> n >> m, n || m) {
        for (int i = 1; i <= n; i++)
            cin >> (str[i] + 1);

        //找到人和箱子的初始位置
        PII man, box;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (str[i][j] == 'S') {
                    man = make_pair(i, j);
                } else if (str[i][j] == 'B') {
                    box = make_pair(i, j);
                }
            }

        Node end;
        printf("Maze #%d\n", ++T);
        if (!bfs_box(man, box, end)) {
            puts("Impossible.");
        } else {
            string ans = "";
            Node u = end;
            Node v = pre[u.x][u.y][u.dir];

            while (true) {
                if (u.x == v.x - 1) {
                    ans += 'N';
                } else if (u.x == v.x + 1) {
                    ans += 'S';
                } else if (u.y == v.y - 1) {
                    ans += 'W';
                } else {
                    ans += 'E';
                }
                ans += path[u.x][u.y][u.dir];
                if(v.dir == -1) break;
                u = v;
                v = pre[u.x][u.y][u.dir];
                
            }
            reverse(ans.begin(), ans.end());
            cout << ans << endl;
        }
        cout << endl;
    }

    return 0;
}
