#include <bits/stdc++.h>


using namespace std;

int main() {
    int T;
    cin >> T;
    for(int kase = 1; kase <= T; kase++) {
        int n, m;
        cin >> n;
        vector<int> s(n + 1);
        for(int i = 1; i <= n; i++)
            cin >> s[i];
        cin >> m;
        vector<int> k(m + 1);
        vector<vector<int> > pos(2501, vector<int>());
        for(int i = 1; i <= m; i++) {
            cin >> k[i];
            pos[k[i]].push_back(i);
        }
        

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e8));
        for(int i = 0; i <= m; i++) {
            dp[0][i] = 0;
            pos[0].push_back(i);
        }
            
        int ans = 1e8;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(j > 1) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    if(k[j - 1] == s[i - 1]) 
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
                if(j < m) {
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                    if(k[j + 1] == s[i - 1]) 
                        dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + 1);
                }
            }

        }
        
        for(int i = 1; i <= m; i++)
            ans = min(ans, dp[n][i]);

        printf("Case #%d: %d\n",kase, ans);
    }
}