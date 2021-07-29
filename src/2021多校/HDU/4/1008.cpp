#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 100;

struct Node {
    int i, l, r, id;
};

vector<int> mines[maxn];
vector<Node> ins[maxn];
bool vis[3 * maxn];
int cur[maxn];
int idx;

bool isoverlap(int a, int b, int c, int d) {
    return !(b < c || d < a);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);

        //初始化
        idx = 0;
        for (int i = 1; i <= n; i++) {
            mines[i].clear();
            ins[i].clear();
            cur[i] = 0;
        }

        int a, b;
        while (k--) {
            scanf("%d%d", &a, &b);
            mines[a].push_back(b);
        }

        for (int i = 1; i <= n; i++) {
            sort(mines[i].begin(), mines[i].end());
        }

        for (int i = 1; i <= n; i++) {
            int last = 1;
            for (int v : mines[i]) {
                if (last < v) {
                    idx++;
                    ins[i].push_back({i, last, v - 1, idx});
                }
                last = v + 1;
            }
            if (last <= m) {
                idx++;
                ins[i].push_back({i, last, m, idx});
            }
        }

        for (int i = 1; i <= idx + 10; i++) {
            vis[i] = false;
        }

        long long ans = 0;
        queue<Node> Q;
        Q.push(ins[1].front());
        vis[1] = true;

        while (Q.size()) {
            Node node = Q.front();
            Q.pop();
            ans += node.r - node.l + 1;
            //printf("%d %d %d\n", node.i, node.l, node.r);
            if (node.i == n) continue;
            for (int i = cur[node.i + 1]; i < ins[node.i + 1].size(); i++) {
                cur[node.i + 1] = i;
                Node v = ins[node.i + 1][i];
                if (vis[v.id]) continue;
                if (isoverlap(node.l, node.r, v.l, v.r)) {
                    vis[v.id] = true;
                    v.l = max(v.l, node.l);
                    Q.push(v);
                } else if (v.l > node.r)
                    break;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}

/*
30
23 23 6
15 17
11 1
11 22
3 15
19 1
16 18
21 21 9
7 13
10 15
21 4
21 18
13 16
14 11
15 12
16 20
10 8
26 26 4
18 8
16 8
26 4
2 26
22 22 10
14 11
2 3
3 17
8 20
21 16
18 10
13 9
21 1
4 22
6 9
25 25 15
22 12
25 5
14 7
1 11
8 20
22 18
1 8
4 21
15 5
8 1
21 17
10 13
21 9
9 16
18 14
22 22 14
10 11
9 5
1 16
1 17
6 5
21 12
16 1
13 20
12 4
18 9
6 10
8 6
10 14
6 17
25 25 4
1 21
18 8
20 14
17 23
29 29 5
13 12
22 15
27 15
3 9
10 23
20 20 10
3 19
4 4
1 10
8 9
8 4
14 4
6 7
14 12
12 12
12 7
27 27 7
8 19
4 3
18 26
6 15
5 5
20 12
4 7
26 26 9
13 26
13 3
21 5
16 18
19 15
19 8
5 26
19 2
9 17
23 23 15
6 9
15 14
6 15
4 6
14 20
12 12
15 3
8 19
1 15
9 6
20 3
12 8
21 7
21 1
4 13
29 29 10
17 22
9 14
5 10
9 24
12 16
5 15
7 15
22 13
22 27
4 22
23 23 3
2 8
20 12
6 1
29 29 8
10 3
16 11
28 13
22 3
29 1
27 15
28 24
5 19
24 24 15
24 2
4 23
4 12
9 20
1 13
24 12
6 15
24 3
22 9
5 17
21 24
16 8
6 9
19 2
5 21
25 25 7
25 8
11 6
5 1
5 24
1 20
13 8
8 15
21 21 15
6 11
18 15
5 14
16 9
4 11
16 18
1 3
10 17
2 6
8 1
11 4
10 7
21 4
6 15
14 19
28 28 11
1 16
13 6
4 26
11 9
3 5
3 2
17 12
17 9
14 3
17 14
15 9
29 29 12
28 19
4 22
3 11
13 1
8 14
5 9
12 27
10 21
15 3
25 26
18 10
6 6
21 21 2
7 15
6 8
28 28 3
21 16
20 26
14 19
27 27 3
7 11
22 23
13 21
22 22 5
17 8
18 13
17 19
15 14
2 9
29 29 5
5 13
29 1
18 17
5 29
8 13
20 20 2
3 11
3 12
28 28 5
1 18
20 20
12 12
5 18
20 28
21 21 16
15 11
7 10
9 21
17 7
7 4
19 12
8 7
18 9
13 7
5 17
2 9
8 4
1 21
12 18
9 15
8 14
22 22 6
16 8
7 19
14 8
6 1
15 7
6 15
26 26 10
3 7
25 9
2 18
18 6
24 2
6 1
5 5
7 17
11 4
11 15
*/