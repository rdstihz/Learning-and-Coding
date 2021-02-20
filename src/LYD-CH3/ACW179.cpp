#include <cstdio>
#include <unordered_map>
#include <cstring>
#include <queue>

using namespace std;

const int N = 9;
const int target_code = 123456780;
const int maxn = 5000000;

int read() {
    char c = getchar();
    while (c != 'x' && (c < '0' || c > '9'))
        c = getchar();
    if (c == 'x')
        return 0;
    else
        return c - '0';
}

int start[N];
int start_code;

int code(int* x) {
    int res = 0;
    for (int i = 0; i < N; i++) {
        res = res * 10 + x[i];
    }
    return res;
}

void decode(int* x, int c) {
    for (int i = N - 1; i >= 0; i--) {
        x[i] = c % 10;
        c /= 10;
    }
}

int tot_id;
unordered_map<int, int> M;
int getId(int x) {
    if (M.count(x))
        return M[x];
    else
        return M[x] = ++tot_id;
}

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const char dir[] = "urdl";

int dist[maxn];
int last[maxn];
int ops[maxn];

bool bfs() {
    queue<int> Q;
    Q.push(start_code);
    int c, t;
    int state[N];

    while (Q.size()) {
        c = Q.front();
        Q.pop();

        if (c == target_code) {
            return true;
        }
        int cid = getId(c);
        decode(state, c);
        int x, y;
        for (int i = 0; i < N; i++)
            if (state[i] == 0) {
                x = i / 3;
                y = i - x * 3;
                break;
            }

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx < 0 || xx > 2 || yy < 0 || yy > 2) continue;
            swap(state[x * 3 + y], state[xx * 3 + yy]);
            t = code(state);
            swap(state[x * 3 + y], state[xx * 3 + yy]);

            if (M.count(t)) continue;
            Q.push(t);
            t = getId(t);
            dist[t] = dist[cid] + 1;
            last[t] = cid;
            ops[t] = dir[i];
        }
    }
    return false;
}
char ans[200];
int main() {

    for (int i = 0; i < N; i++)
        start[i] = read();
    start_code = code(start);
    int start_id = getId(start_code);
    if (bfs()) {
        int target_id = getId(target_code);
        int cur = target_id;
        int t = 0;
        while(cur != start_id) {
            ans[++t] = ops[cur];
            cur = last[cur];
        }
        for(int i = t;i >= 1;i--)
            printf("%c", ans[i]);

    } else {
        printf("unsolvable");
    }

    return 0;
}