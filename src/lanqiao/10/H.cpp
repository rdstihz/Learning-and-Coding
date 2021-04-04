#include <iostream>

using namespace std;

const int maxn = 100000 + 100;



bool vis[15 * maxn];

int main() {

    int n,v;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> v;
        while(vis[v])
            v++;
        vis[v] = true;
        cout << v << " ";
    }
    cout << endl;


    return 0;
}