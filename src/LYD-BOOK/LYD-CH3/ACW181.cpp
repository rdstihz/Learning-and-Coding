#include <iostream>
#include <algorithm>

using namespace std;

const int N = 8;

int a[N][N];

int x[] = {3, 3, 3, 4, 4, 5, 5, 5};
int y[] = {3, 4, 5, 3, 5, 3, 4, 5};

bool check() {
    for (int i = 1; i < 8; i++)
        if (a[x[i]][y[i]] != a[x[i - 1]][y[i - 1]])
            return false;
    return true;
}

void roll(int i, int d, int q) {

    if (d == 0) {
        //纵向
        if (q == 1) {
            int t = a[1][i];
            for (int j = 1; j < 7; j++)
                a[j][i] = a[j + 1][i];
            a[7][i] = t;
        } else {
            int t = a[7][i];
            for (int j = 7; j > 1; j--)
                a[j][i] = a[j - 1][i];
            a[1][i] = t;
        }
    } else {
        //横向
        if (q == 1) {
            int t = a[i][1];
            for (int j = 1; j < 7; j++)
                a[i][j] = a[i][j + 1];
            a[i][7] = t;
        } else {
            int t = a[i][7];
            for (int j = 7; j > 1; j--)
                a[i][j] = a[i][j - 1];
            a[i][1] = t;
        }
    }
}
string ans;
int cnt[4];
int f() {
    cnt[1] = cnt[2] = cnt[3] = 0;
    for (int i = 0; i < 8; i++)
        cnt[a[x[i]][y[i]]]++;
    int res = 8;
    for (int i = 1; i <= 3; i++) {
        res = min(res, 8 - cnt[i]);
    }
    return res;
}

bool dfs(int d, int maxd) {
    if (check()) return true;
    if (d + f() > maxd) return false;

    //A:
    roll(3, 0, 1);
    if (dfs(d + 1, maxd)) {
        ans += 'A';
        return true;
    }
    roll(3, 0, -1);

    //B:
    roll(5, 0, 1);
    if (dfs(d + 1, maxd)) {
        ans += 'B';
        return true;
    }
    roll(5, 0, -1);

    //C:
    roll(3, 1, -1);
    if (dfs(d + 1, maxd)) {
        ans += 'C';
        return true;
    }
    roll(3, 1, 1);

    //D:
    roll(5, 1, -1);
    if (dfs(d + 1, maxd)) {
        ans += 'D';
        return true;
    }
    roll(5, 1, 1);

    //E:
    roll(5, 0, -1);
    if (dfs(d + 1, maxd)) {
        ans += 'E';
        return true;
    }
    roll(5, 0, 1);

    //F:
    roll(3, 0, -1);
    if (dfs(d + 1, maxd)) {
        ans += 'F';
        return true;
    }
    roll(3, 0, 1);

    //G:
    roll(5, 1, 1);
    if (dfs(d + 1, maxd)) {
        ans += 'G';
        return true;
    }
    roll(5, 1, -1);

    //H:
    roll(3, 1, 1);
    if (dfs(d + 1, maxd)) {
        ans += 'H';
        return true;
    }
    roll(3, 1, -1);
    return false;
}

int main() {

    while (cin >> a[1][3] && a[1][3]) {
        cin >> a[1][5];
        cin >> a[2][3] >> a[2][5];
        for (int i = 1; i <= 7; i++)
            cin >> a[3][i];
        cin >> a[4][3] >> a[4][5];
        for (int i = 1; i <= 7; i++)
            cin >> a[5][i];
        cin >> a[6][3] >> a[6][5];
        cin >> a[7][3] >> a[7][5];

        if (check()) {
            cout << "No moves needed" << endl;
            cout << a[3][3] << endl;
            continue;
        }

        for (int d = 1;; d++) {
            ans = "";
            if (dfs(0, d)) {
                reverse(ans.begin(), ans.end());
                cout << ans << endl;
                cout << a[3][3] << endl;
                break;
            }
        }
    }

    return 0;
}