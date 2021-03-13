#include <iostream>
#include <stack>

using namespace std;

const int maxn = 1010;

char M[maxn][maxn];
int a[maxn][maxn];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> M[i][j];
        }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (M[i][j] == 'R')
                a[i][j] = 0;
            else
                a[i][j] = a[i - 1][j] + 1;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        stack<pair<int, int>> S;
        for (int j = 1; j <= m + 1; j++) {
            int w = 0;
            while (!S.empty() && S.top().first > a[i][j]) {
                w += S.top().second;
                ans = max(ans, w * S.top().first);
                S.pop();
            }

            w++;
            S.push(make_pair(a[i][j], w));
        }
    }
    cout << ans * 3 << endl;
    return 0;
}