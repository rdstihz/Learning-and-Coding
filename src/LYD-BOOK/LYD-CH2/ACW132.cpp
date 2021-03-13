#include <bits/stdc++.h>

using namespace std;
const int maxn = 1000 + 10;
map<int, int> G;

int Q[maxn], lQ, rQ;
int q[maxn][maxn], l[maxn], r[maxn];
char op[20];

bool inQ[maxn];

int main() {
    int n;
    int kase = 0;
    while (cin >> n, n) {
        G.clear();
        memset(inQ, 0, sizeof(inQ));
        lQ = rQ = 0;


        printf("Scenario #%d\n", ++kase);

        int m;
        for (int i = 1; i <= n; i++) {
            l[i] = r[i] = 0;
            cin >> m;
            int t;
            for (int j = 1; j <= m; j++) {
                cin >> t;
                G[t] = i;
            }
        }


        int t;
        while (scanf("%s", op), op[0] != 'S') {
            if (op[0] == 'E') {
                scanf("%d", &t);
                int g = G[t];
                q[g][++r[g]] = t;

                if (!inQ[g]) {
                    Q[++rQ] = g;
                    inQ[g] = true;
                }

            } else if (op[0] == 'D') {
                if (lQ == rQ) continue;
                int g = Q[lQ + 1];
                l[g]++;
                printf("%d\n", q[g][l[g]]);
                if (l[g] == r[g]) {
                    inQ[g] = false;
                    lQ++;
                }

            }
        }
        printf("\n");
    }

    return 0;
}