/*
    Created by rdstihz at 2022-08-20 23:05:06
*/

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
const int maxn = 200000 + 10;

int u[maxn], v[maxn], w[maxn];
int color[maxn];
int a[maxn];

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%d", u + i, v + i, w + i);
    }

    for(int k = 0; k <= 29; k++) {
        memset(color, -1, sizeof(color));
        //自环
        for(int i = 1; i <= m; i++) {
            int a = u[i], b = v[i], c = w[i];
            if(a == b) {
                color[a] = color[b] = (c >> k & 1);
            }
        }
        // i | j = 0
        for(int i = 1; i <= m; i++) {
            int a = u[i], b = v[i], c = w[i];
            if((c >> k & 1) == 0) {
                color[a] = color[b] = 0;
            }
        }

        // i | j = 1 , i,j中有一个0
        for(int i = 1; i <= m; i++) {
            int a = u[i], b = v[i], c = w[i];
            if((c >> k & 1) == 1) {
                if(color[a] == 0) color[b] = 1;
                if(color[b] == 0) color[a] = 1;
            }
        }

        //i | j = 1, 未确定的边
        vector<PII> e;
        for(int i = 1; i <= m; i++) {
            int a = u[i], b = v[i], c = w[i];
            if((c >> k & 1) == 1) {
                if(color[a] == -1 && color[b] == -1) {
                    if(a > b) swap(a, b);
                    e.push_back(make_pair(a, -b));
                }
            }
        }
        sort(e.begin(), e.end());
        for(auto &item : e) {
            int a = item.first, b = -item.second;
            if(color[a] == 1 || color[b] == 1) continue;
            color[a] = 0;
            color[b] = 1;
        }

        for(int i = 1; i <= n; i++) {
            if(color[i] == -1) color[i] = 0;

            a[i] |= color[i] << k;
        }
    }
    for(int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int T;
    T = 1;
    while (T--)
        solve();
    return 0;
}