#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 505;
char str[maxn][maxn];

int target_x, target_y;

struct State {
    int x1, y1;
    int x2, y2;
    int s; // 0 立 ， 1 躺
    int d; //距离
    
};
State start;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n,m;

inline bool legal(int x,int y) {
    return x>= 0 && x < n && y >= 0 && y < m && str[x][y] != '#';
}


int main() {

    while (scanf("%d%d", &n, &m), n) {
        for (int i = 0; i < n; i++) {
            scanf("%s", str[i]);
        }
        start.s = -1;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (str[i][j] == 'O') { //目标
                    target_x = i;
                    target_y = j;
                } else if (str[i][j] == 'X') { //起点
                    start.s++;
                    if (start.s == 0) {
                        start.x1 = i;
                        start.y1 = j;
                    } else if (start.s == 1) {
                        start.x2 = i;
                        start.y2 = j;
                    }
                }
            }
        start.d = 0;
        queue<State> Q;
        Q.push(start);

        while (Q.size()) {
            State S = Q.front();
            Q.pop();

            if (S.s == 0) {                                 //立
                if (S.x1 == target_x && S.y1 == target_y) { //到达终点
                    printf("%d\n", S.d);
                    break;
                }

                for (int i = 0; i < 4; i++) {
                    int x1 = S.x1 + dx[i];
                    int x2 = x1 + dx[i];
                    int y1 = S.y1 + dy[i];
                    int y2 = y1 + dy[i];

                    if (legal(x1, y1) && legal(x2, y2)) {
                        Q.push(State{x1, y1, x2, y2, 0, S.d + 1});
                    }
                }
            }

            if(S.s == 1) {

                
            }

        }
    }

    return 0;
}