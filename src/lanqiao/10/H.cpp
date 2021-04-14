#include <iostream>

using namespace std;

const int maxn = 100000 + 100;

bool vis[15 * maxn];

int main() {

    int n, v;
    cin >> n;
    int last = 1;
    for (int i = 1; i <= n; i++) {
        cin >> v;

        v = max(v, last);

        while (vis[v])
            v++;
        vis[v] = true;

        while (vis[last])
            last++;
        cout << v << " ";
    }
    cout << endl;

    return 0;
}