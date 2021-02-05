#include <iostream>
#include <algorithm>

using namespace std;

const int N = 9;

int ones[1 << N], map[1 << N];
char str[100];

int row[N], col[N], cell[3][3];

inline int lowbit(int x) {
    return x & (-x);
}

void init() {
    for (int i = 0; i < N; i++)
        col[i] = row[i] = (1 << N) - 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cell[i][j] = (1 << N) - 1;
}

int get(int x, int y) {
    return row[x] & col[y] & cell[x / 3][y / 3];
}

bool dfs(int cnt) {
    if (!cnt) return true;

    //1.找到选择最少的格子
    int minv = 10;
    int x, y;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (str[i * 9 + j] == '.') {
                if (ones[get(i, j)] < minv) {
                    minv = ones[get(i, j)];
                    x = i, y = j;
                }
            }
    for (int i = get(x, y); i; i -= lowbit(i)) {
        int t = map[lowbit(i)];

        str[x * 9 + y] = t + '1';
        row[x] ^= 1 << t;
        col[y] ^= 1 << t;
        cell[x / 3][y / 3] ^= 1 << t;

        if (dfs(cnt - 1)) return true;

        str[x * 9 + y] = '.';
        row[x] ^= 1 << t;
        col[y] ^= 1 << t;
        cell[x / 3][y / 3] ^= 1 << t;
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

    while (cin >> str, str[0] != 'e') {

        init();
        int cnt = 0;
        for (int i = 0, k = 0; i < N; i++) {
            for (int j = 0; j < N; j++, k++) {
                if (str[k] != '.') {
                    int t = str[k] - '1';
                    row[i] ^= 1 << t;
                    col[j] ^= 1 << t;
                    cell[i / 3][j / 3] ^= 1 << t;

                } else
                    cnt++;
            }
        }

        dfs(cnt);

        cout << str << endl;
    }

    return 0;
}
