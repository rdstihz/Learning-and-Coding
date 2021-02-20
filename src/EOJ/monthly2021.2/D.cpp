#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 50000 + 100;
int color[maxn];
int h[maxn];
bool vis[maxn];

int main(){
    int r,c,q;
    int t;
    cin >> r >> c >> q;
    for(int i = 1;i <= c;i++) {
        cin >> h[i];
    }
    for(int i = 1;i <= c; i++) {
        cin >> color[i];
    }

    int op,x,y,l;
    while(q--) {
        cin >> op >> x >> y >> l;
        if(op == 1) {
            color[x] = l;
        } else if(op == 2) {
            if(h[x] > l) {
                cout << 0 << endl;
                continue;
            }

            int ans = 0;
            memset(vis,0,sizeof(vis));
            for(int i = 1; i <= c; i++) {
                if( h[i] <= l && !vis[color[i]]) {
                    ans++;
                    vis[color[i]] = true;
                }
            }
            cout << ans << endl;
        }

    }

    return 0;
}