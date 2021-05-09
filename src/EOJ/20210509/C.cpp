#include <bits/stdc++.h>

using namespace std;

// const int maxn = 1010;
// const int maxm = 2000000 + 10;

// int to[maxm], nxt[maxm], tot;
// int fir[maxn];

// inline void add(int a, int b) {
//     tot++;
//     to[tot] = b, nxt[tot] = fir[a], fir[a] = tot;
// }

int n, m;

int main() {

    while (cin >> n >> m) {
        int a, b;
        for (int i = 1; i <= m; i++) {
            cin >> a >> b;
        }

        if(m >= n) {
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }

    }

    return 0;
}