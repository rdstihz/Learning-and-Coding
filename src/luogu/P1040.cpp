#include <iostream>

using namespace std;

const int maxn = 100;

unsigned a[maxn];
unsigned f[maxn][maxn];
int g[maxn][maxn];

void dfs(int l, int r) {
    if (l > r) return;

    cout << g[l][r] << " ";
    dfs(l, g[l][r] - 1);
    dfs(g[l][r] + 1, r);
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int l = n; l >= 1; l--) {
        for (int r = l; r <= n; r++) {

            if (l == r){
                f[l][r] = a[l];
                g[l][r] = l;
            }
                
            else {
                unsigned t1 = a[l] + f[l + 1][r];
                unsigned t2 = a[r] + f[l][r - 1];

                if (t1 >= t1) {
                    f[l][r] = t1;
                    g[l][r] = l;
                } else {
                    f[l][r] = t2;
                    g[l][r] = r;
                }

                for (int k = l + 1; k < r; k++) {
                    unsigned t = f[l][k - 1] * f[k + 1][r] + a[k];
                    if (t > f[l][r]) {
                        f[l][r] = t;
                        g[l][r] = k;
                    }
                }
            }
        }
    }

    cout << f[1][n] << endl;

    dfs(1, n);

    return 0;
}