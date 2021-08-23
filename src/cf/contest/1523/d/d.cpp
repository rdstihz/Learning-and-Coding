/*
    Created by rdstihz at 2021-07-22 21:07:57
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 200000 + 100;
int n, m, p;
char str[100];
LL a[maxn];
int dp[1 << 15];
int ones[1 << 15];
int main() {

    for (int i = 0; i < (1 << 15); i++)
        ones[i] = ones[i >> 1] + (i & 1);

    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str);
        for (int j = 0; j < m; j++)
            if (str[j] == '1')
                a[i] |= 1ll << j;
    }
    //for(int i = 1; i <= n; i++)
    //    printf("%d\n", a[i]);

    //随机选取50个人
    int T = 50;

    srand((unsigned int)time(NULL));
    vector<int> ans;
    while (T--) {
        int t = (rand() * rand()) % n + 1;
        vector<int> save;

        for (int i = 0; i < m; i++)
            if (a[t] >> i & 1)
                save.push_back(i);

        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            int cur = 0;

            for (int j = 0; j < save.size(); j++)
                if (a[i] >> save[j] & 1)
                    cur |= 1 << j;
            dp[cur]++;
        }

        for (int i = 0; i < save.size(); i++) {
            for (int S = 0; S < (1 << save.size()); S++) {
                if (!(S >> i & 1))
                    dp[S] += dp[S ^ (1 << i)];
            }
        }

        for (int S = 0; S < (1 << save.size()); S++) {
            if (dp[S] >= (n + 1) / 2) {
                if (ones[S] > ans.size()) {
                    ans.clear();

                    for (int i = 0; i < save.size(); i++)
                        if (S >> i & 1)
                            ans.push_back(save[i]);
                }
            }
        }
    }
    LL res = 0;
    for (int j : ans)
        res |= 1ll << j;

    for (int i = 0; i < m; i++)
        printf("%d", res >> i & 1);
    printf("\n");
    return 0;
}