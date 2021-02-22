#include <bits/stdc++.h>

using namespace std;

int p[10];
bool vis[10];

void dfs(int d) {

    if (d == 8) {
        int x = p[0] * 1000 + p[1] * 100 + p[2] * 10 + p[3];                //祥瑞生辉
        int y = p[4] * 1000 + p[5] * 100 + p[6] * 10 + p[1];                //三羊献瑞
        int z = p[4] * 10000 + p[5] * 1000 + p[2] * 100 + p[1] * 10 + p[7]; //三羊生瑞气
        if (y >= 1000)
            if (x + y == z)
                cout << y << endl;

        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (!vis[i]) {
            vis[i] = true;
            p[d] = i;
            dfs(d + 1);
            vis[i] = false;
        }
    }
}

int main() {

    dfs(0);
    return 0;
}