#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 16;

int G[N][N];
int row[N], col[N], cell[4][4];
char str[20][20];

int ones[1 << N], map[1 << N];

inline int lowbit(int x) {
    return x & (-x);
}

void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            G[i][j] = (1 << N) - 1;
    for (int i = 0; i < N; i++)
        row[i] = col[i] = (1 << N) - 1;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cell[i][j] = (1 << N) - 1;
}

bool dfs(int cnt) {
    if (!cnt)
        return true;

    //可行性剪枝
    //遍历每一格
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (G[i][j] == 0)
                return false;
    //每一行
    for (int i = 0; i < N; i++) {
        int s = 0;
        for (int j = 0; j < N; j++) {
            s |= G[i][j];
        }
        if (s != (1 << N) - 1) return false;
    }

    //每一列
    for (int j = 0; j < N; j++) {
        int s = 0;
        for (int i = 0; i < N; i++) {
            s |= G[i][j];
        }
        if (s != (1 << N) - 1) return false;
    }

    for(int i = 0; i < 4;i++)
        for(int j = 0;j < 4;j++) {
            int s = 0;
            
            for(int x = 4 * i; x < 4*(i + 1);x++)
                for(int y = 4 * j; y < 4 * (j + 1); y++)
                    s |= G[x][y];
            if(s != (1 << N) - 1) return false;
        }


    //找到选择最少的空格
    int minv = 20;
    int x, y;

    for(int i = 0; i < N;i++)
        for(int j = 0; j < N;j++) 
            if(str[i][j] == '-' && ones[G[i][j]] < minv) {
                minv = ones[G[i][j]];
                x = i;
                y = j;
            }

    int bak[N][N];
    memcpy(bak, G, sizeof(G));
    for (int i = G[x][y]; i; i -= lowbit(i)) {
        int t = map[lowbit(i)];
        for (int k = 0; k < N; k++) {
            G[x][k] &= ~(1 << t);
            G[k][y] &= ~(1 << t);
        }
        int xx0 = x / 4 * 4;
        int yy0 = y / 4 * 4;
        for (int xx = xx0; xx < xx0 + 4; xx++)
            for (int yy = yy0; yy < yy0 + 4; yy++)
                G[xx][yy] &= ~(1 << t);
        str[x][y] = 'A' + t;
        G[x][y] = 1 << t;
        if (dfs(cnt - 1)) return true;
        str[x][y] = '-';
        memcpy(G, bak, sizeof(bak));
    }
    return false;
}

int main() {

    for (int i = 0; i < N; i++)
        map[1 << i] = i;
    for (int i = 0; i < 1 << N; i++) {
        int s = 0;
        for (int j = i; j; j -= lowbit(j))
            s++;
        ones[i] = s;
    }

    while (scanf("%s", str[0]) != EOF) {
        for (int i = 1; i < N; i++)
            scanf("%s", str[i]);
        init();
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (str[i][j] != '-') {
                    int t = str[i][j] - 'A';
                    row[i] ^= 1 << t;
                    col[j] ^= 1 << t;
                    cell[i / 4][j / 4] ^= 1 << t;
                } else
                    cnt++;
            }
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (str[i][j] == '-') {
                    G[i][j] = row[i] & col[j] & cell[i / 4][j / 4];
                } else {
                    G[i][j] = 1 << (str[i][j] - 'A');
                }
            }
        dfs(cnt);

        for (int i = 0; i < N; i++)
            printf("%s\n", str[i]);
    }

    return 0;
}