#include <cstring>
#include <iostream>

using namespace std;

const int c[] = {0, 3, 4, 5};
const int n = 12;
int a[4];
int ans;
int color[10000][12];

bool equal(int a, int b) {

    //正向
    for (int k = 0; k < n; k++) {
        bool flag = true;
        for (int i = 0; i < n; i++)
            if (color[a][(k + i) % n] != color[b][i]) {
                flag = false;
                break;
            }
        if (flag) return true;
    }

    //反向
    for (int k = 0; k < n; k++) {
        bool flag = true;

        for (int i = 0; i < n; i++) {
            if (color[a][(k + n - i) % n] != color[b][i]) {
                flag = false;
                break;
            }
        }
        if (flag) return true;
    }

    return false;
}

void dfs(int d) {

    if (d == 12) {

        bool vis = false;

        for (int i = 1; i <= ans; i++) {
            if (equal(0, i)) {
                vis = true;
                break;
            }
        }
        if (!vis) {
            ans++;
            for (int i = 0; i < n; i++)
                color[ans][i] = color[0][i];
        }

        return;
    }

    for (int i = 1; i <= 3; i++) {
        if (a[i] < c[i]) {
            a[i]++;
            color[0][d] = i;
            dfs(d + 1);
            a[i]--;
        }
    }
}

int main() {
    ans = 1170;
    //dfs(0);
    cout << ans << endl;
    return 0;
}