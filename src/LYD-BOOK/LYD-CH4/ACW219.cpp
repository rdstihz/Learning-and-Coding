#include <bits/stdc++.h>

using namespace std;

const int maxn = 210;

int sg[maxn][maxn];

bool vis[maxn * maxn];

int main() {

    sg[2][2] = sg[2][3] = sg[3][2] = 0;

    for (int i = 2; i <= 200; i++) {
        for (int j = 2; j <= 200; j++) {

            memset(vis, 0, sizeof(vis));

            for (int t = 2; t <= i - t; t++) {
                vis[sg[t][j] ^ sg[i - t][j]] = true;
            }
            for (int t = 2; t <= j - t; t++) {
                vis[sg[i][t] ^ sg[i][j - t]] = true;
            }

            sg[i][j] = 0;
            while (vis[sg[i][j]])
            {
                sg[i][j]++;
            }
            
        }
    }
    int n,m;
    while (cin >> n >> m)
    {
        if(sg[n][m] == 0) {
            cout << "LOSE" << endl;
        }else{
            cout << "WIN" << endl;
        }
    }
    

    return 0;
}