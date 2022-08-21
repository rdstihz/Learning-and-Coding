#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL INF = 1e18;
int n, p, m;

const int dx[] = {-1, 0, 0, 1, 0};
const int dy[] = {0, 1, -1, 0, 0};
struct Op {
    char op[2];
    int v;
} op[5];

int a[11][11];

LL ans;

bool legal(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

LL proc(LL cur, int k) {
    if(*op[k].op == '+') {
        return cur + op[k].v;
    }else if(*op[k].op == '-') {
        return cur - op[k].v;
    }else if(*op[k].op == '*') {
        return cur * op[k].v;
    }else if(*op[k].op == '/') {
        int r = cur % op[k].v;
        if(r < 0) r += op[k].v;
        cur -= r;
        cur /= op[k].v;
        return cur;
    }
}

int h(int x,int y) { //估价函数
    int res = 0;
    int mnx = x, mny = y;
    int mxx = x, mxy = y;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(a[i][j] != 0) {
                mnx = min(mnx, i);
                mny = min(mny, j);
                mxx = max(mxx, i);
                mxy = max(mxy, j);
            }
    
    res += (mxx - mnx) + min(x - mnx, mxx - x);
    res += (mxy - mny) + min(y - mny, mxy - y);

    return res;
}

LL hh(LL cur, int rp,int rm) {
    cur += 4;
    rp--;
    for(int i = 1; i <= rp; i++) {
        cur *= 4;
        cur += 4;
    }
    for(int i = rp + 1; i <= rm; i++) {
        cur *= 4;
    }
    return abs(cur);
}

void dfs(int x, int y, int rp, int rm, LL cur) {
    if (rp == 0 && rm == 0) {
        ans = max(ans, cur);
        return;
    } else if(rm == 0 && rp == 1 && a[x][y] != 0) {
        ans = max(ans, cur + a[x][y]);
        return;
    } 
    else if (rm == 0) {
        return;
    }

    if(rp && h(x, y) > rm) return;
    if(rp > rm + 1) return;
    if(hh(cur, rp, rm) <= ans) return;

    for (int k = 0; k < 5; k++) {
        int xx = x + dx[k], yy = y + dy[k];
        if (!legal(xx, yy)) continue;

        dfs(xx, yy, rp, rm - 1, proc(cur, k));
        if(a[xx][yy] != 0) {
            int t = a[xx][yy];
            a[xx][yy] = 0;
            dfs(xx, yy, rp - 1, rm - 1, proc(cur + a[xx][yy], k));
            a[xx][yy] = t;
        }
    }
}

void solve() {
    cin >> n >> p >> m;
    int x0, y0;
    cin >> x0 >> y0;

    for (int i = 0; i < 4; i++)
        cin >> op[i].op >> op[i].v;
    op[4].op[0] = '+';
    op[4].v = 0;

    memset(a, 0, sizeof(a));
    int x, y, c;
    for (int i = 1; i <= p; i++) {
        cin >> x >> y >> c;
        a[x][y] = c;
    }
    ans = -INF;
    dfs(x0, y0, p, m, 0);
    if (ans == -INF) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {

    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cout << "Case #" << kase << ": ";
        solve();
    }

    return 0;
}