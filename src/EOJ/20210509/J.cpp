#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000000 + 100;

int sg[maxn];

bool vis[maxn];

int main() {

    int n = 500;
    sg[0] = 0;

    for (int x = 1; x <= n; x++) {
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= x; i++) {
            for (int k = 0; k <= 3 && i + k - 1 <= x; k++) {
                vis[sg[i - 1] ^ sg[x - (i + k)]] = true;
            }
        }
        sg[x] = 0;
        while(vis[sg[x]])
            sg[x]++;
    }

    for(int i = n + 1; i <= 1000000; i++)
        sg[i] = sg[i - 24];

    
    while(cin >> n) {
        int res = 0;
        int v;

        for(int i = 1; i <= n; i++) {
            cin >> v;
            res ^= sg[v];
        }

        if(res == 0) {
            cout << "lets see who is real evil genius" << endl;
        }else{
            cout << "Emo:?" << endl;
        }
    }

    return 0;
}