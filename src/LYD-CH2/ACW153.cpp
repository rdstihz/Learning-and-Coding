#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;

int n;
int a[maxn];
int f[maxn];
bool G[maxn][maxn];
int color[maxn];

bool dfs(int u, int c) {
    color[u] = c;
    for (int i = 1; i <= n; i++)
        if (G[u][i]) {
            if (color[i] == color[u]) return false;
            if (color[i] == -1 && !dfs(i, !c)) return false;
        }
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    f[n + 1] = n + 1;
    for (int i = n; i >= 1; i--)
        f[i] = min(a[i], f[i + 1]);

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] < a[j] && f[j + 1] < a[i]) {
                G[i][j] = G[j][i] = true;
            }
        }
    }

    memset(color, -1, sizeof(color));
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1 && !dfs(i, 0)) {
            flag = false;
            break;
        }
    }
    if (!flag) {
        cout << 0 << endl;
        return 0;
    }
  //  for(int i = 1; i <= n;i ++) cout << color[i] << " ";
  //  cout << endl;
    stack<int> st1, st2;
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            st1.push(a[i]);
            cout << "a ";
        }

        else {
            st2.push(a[i]);
            cout << "c ";
        }

        while (true) {
            if (st1.size() && st1.top() == cur) {
                cout << "b ";
                cur++;
                st1.pop();
            } else if (st2.size() && st2.top() == cur) {
                cout << "d ";
                cur++;
                st2.pop();
            } else
                break;
        }
    }
    cout << endl;
    return 0;
}
