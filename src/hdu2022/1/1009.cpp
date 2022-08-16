#include <bits/stdc++.h>


using namespace std;

const int maxn = 500000 + 100;
const double eps = 1e-2;
struct Point{
    double x, y;
}a[maxn];

int n;
int cmp(double a, double b) {
    if(fabs(a - b) < eps) return 0;
    else if(a > b) return 1;
    else return -1;
}

bool check(Point u) {
    for(int i = 1; i <= n; i++) {
        Point v = a[i];
        if(cmp(u.x, v.x) && cmp(u.y, v.y) && cmp(u.x + u.y, v.x + v.y) && cmp(u.x - u.y, v.x - v.y))
            return false;
    }
    return true;
}

void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lf%lf", &a[i].x, &a[i].y);
    }


    Point u = a[1];
    Point v;
    bool flag = false;
    for(int i = 2; i <= n; i++) {
        if(cmp(u.x, a[i].x) && cmp(u.y, a[i].y) && cmp(u.x + u.y, a[i].x + a[i].y) && cmp(u.x-u.y, a[i].x-a[i].y)) {
            v = a[i];
            flag = true;
            break;
        }
    }

    if(!flag) {
        puts("YES");
        return;
    }

    if(check(Point({v.x, u.y}))) {
        puts("YES");
        return;
    }
    if(check(Point({v.x, u.y+(v.x-u.x)}))) {
        puts("YES");
        return;
    }
    if(check(Point({v.x, u.y-(v.x-u.x)}))) {
        puts("YES");
        return;
    }
    if(check(Point({u.x, v.y}))) {
        puts("YES");
        return;
    }
    if(check(Point({u.x+(v.y-u.y), v.y}))) {
        puts("YES");
        return;
    }
    if(check(Point({u.x-(v.y-u.y), v.y}))) {
        puts("YES");
        return;
    }
    if(check(Point({u.x, v.y+(v.x-u.x)}))) {
        puts("YES");
        return;
    }
    if(check(Point({u.x, v.y-(v.x-u.x)}))) {
        puts("YES");
        return;
    }
    if(check(Point({v.x+(v.y-u.y), u.y}))) {
        puts("YES");
        return;
    }
    if(check(Point({v.x-(v.y-u.y), u.y}))) {
        puts("YES");
        return;
    }
    if(check(Point({(u.x + u.y + v.x - v.y) / 2, (u.x + u.y - v.x + v.y) / 2}))) {
        puts("YES");
        return;
    }
    if(check(Point({(v.x + v.y + u.x - u.y) / 2, (v.x + v.y - u.x + u.y) / 2}))) {
        puts("YES");
        return;
    }
    puts("NO");

}


int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}