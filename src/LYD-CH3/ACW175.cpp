#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>

using namespace std;
typedef pair<int, int> PII;

const int maxn = 510;
const int INF = 0x3f3f3f3f;

char g[maxn][maxn];
int n, m;
int d[maxn][maxn];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> g[i];

        memset(d, 0x3f, sizeof(d));
        deque<PII> Q;
        Q.push_back(make_pair(0, 0));
        d[0][0] = 0;
        while (Q.size()) {
            int x = Q.front().first, y = Q.front().second;
            Q.pop_front();
            int xx, yy;
            if (x < n && y < m) {
                xx = x + 1, yy = y + 1;

                if (g[x][y] == '\\' && d[xx][yy] > d[x][y]) {
                    d[xx][yy] = d[x][y];
                    Q.push_front(make_pair(xx, yy));
                } else if (g[x][y] == '/' && d[xx][yy] > d[x][y] + 1) {
                    d[xx][yy] = d[x][y] + 1;
                    Q.push_back(make_pair(xx, yy));
                }
            }

            if (x < n && y > 0) {
                xx = x + 1, yy = y - 1;

                if (g[x][y - 1] == '/' && d[xx][yy] > d[x][y]) {
                    d[xx][yy] = d[x][y];
                    Q.push_front(make_pair(xx, yy));
                } else if (g[x][y - 1] == '\\' && d[xx][yy] > d[x][y] + 1) {
                    d[xx][yy] = d[x][y] + 1;
                    Q.push_back(make_pair(xx, yy));
                }
            }
            if (x > 0 && y < m) {
                xx = x - 1, yy = y + 1;
                if (g[x - 1][y] == '/' && d[xx][yy] > d[x][y]) {
                    d[xx][yy] = d[x][y];
                    Q.push_front(make_pair(xx, yy));
                } else if (g[x - 1][y] == '\\' && d[xx][yy] > d[x][y] + 1) {
                    d[xx][yy] = d[x][y] + 1;
                    Q.push_back(make_pair(xx, yy));
                }
            }
            if (x > 0 && y > 0) {
                xx = x - 1, yy = y - 1;
                if (g[x - 1][y - 1] == '\\' && d[xx][yy] > d[x][y]) {
                    d[xx][yy] = d[x][y];
                    Q.push_front(make_pair(xx, yy));
                } else if (g[x - 1][y - 1] == '/' && d[xx][yy] > d[x][y] + 1) {
                    d[xx][yy] = d[x][y] + 1;
                    Q.push_back(make_pair(xx, yy));
                }
            }
        }
        if(d[n][m] == INF) {
            cout << "NO SOLUTION" << endl;
        }else{
            cout << d[n][m] << endl;
        }
    }

    return 0;
}