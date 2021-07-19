#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
const int maxn = 5000 + 10;

vector<PII> v;      //后手胜的状态
bool a[maxn][maxn]; //标记后手胜

bool del[maxn];

vector<int> dis[maxn];

void init() {
    a[0][0] = 1;
    v.push_back(make_pair(0, 0));

    int n = 5000;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            dis[j].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {

        memset(del, 0, sizeof(del));

        for (auto p : v) {
            int t = i - p.first;
            //t的倍数
            for (int j = p.second; j <= n; j += t)
                del[j] = true;
            //t 的约数
            for (int d : dis[t]) {
                if (d + p.second > n) break;
                del[d + p.second] = true;
            }
        }

        int j = 1;
        while (del[j])
            j++;
        if (j <= n) {
            a[i][j] = 1;
            v.push_back(make_pair(i, j));
        }
    }
}

int main() {
    init();

    // for (int i = 0; i < 10; i++)
    //     printf("%d %d\n", v[i].first, v[i].second);

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        if (a[n][m])
            puts("Bob");
        else
            puts("Alice");
    }

    return 0;
}