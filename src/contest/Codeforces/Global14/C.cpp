#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;

int h[maxn];
int H[maxn];

int belong[maxn];
int q[maxn];
int q2[maxn];

bool cmp(int x, int y) {
    return H[x] < H[y];
}

bool cmp2(int x, int y) {
    return h[x] > h[y];
}

int main() {

    int T;
    cin >> T;
    while (T--) {
        int n, m, x;
        cin >> n >> m >> x;

        int S = 0;
        for (int i = 1; i <= n; i++) {
            cin >> h[i];
            S += h[i];
        }

        int avg = S / m;

        int cur = 1;

        for (int i = 1; i <= m; i++) {
            H[i] = 0;
            while (H[i] + h[cur] <= avg && cur <= n) {
                H[i] += h[cur];
                belong[cur] = i;
                cur++;
            }
        }

        for (int i = 1; i <= m; i++)
            q[i] = i;
        sort(q + 1, q + 1 + m, cmp);

        for (int i = cur; i <= n; i++)
            q2[i] = i;
        sort(q2 + cur, q2 + n + 1, cmp2);

        for (int i = 1; i <= m && cur <= n; i++, cur++) {
            int id = q[i];
            int bl = q2[cur];

            belong[bl] = id;
        }

        cout << "YES" << endl;

        for (int i = 1; i <= n; i++)
            cout << belong[i] << " ";
        cout << endl;
    }

    return 0;
}