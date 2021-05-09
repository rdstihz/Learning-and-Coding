#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000000 + 100;

int sg[maxn];

bool vis[maxn];

int main() {

    int n = 1000;
    sg[0] = 0;

    for (int x = 1; x <= n; x++) {
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= x; i++) {
            for (int k = 1; k <= 3 && i + k - 1 <= x; k++) {
                vis[sg[i - 1] ^ sg[x - i - k + 1]] = true;
            }
        }
        sg[x] = 0;
        while(vis[sg[x]])
            sg[x]++;
    }

    for(int i = 1; i <= 1000; i++) {
        if(sg[i] == 88)
            cout << i << endl;
    }
    
    // while(cin >> n) {
    //     int res = 0;
    //     int v;

    //     for(int i = 1; i <= n; i++) {
    //         cin >> v;
    //         res ^= sg[v];
    //     }

    //     if(res == 0) {
    //         cout << "lets see who is real evil genius" << endl;
    //     }else{
    //         cout << "Emo:?" << endl;
    //     }
    // }

    return 0;
}

/*
2
1 1
1
4
1
5
1
9
3
15 16 17
3
1000000 1 2

*/