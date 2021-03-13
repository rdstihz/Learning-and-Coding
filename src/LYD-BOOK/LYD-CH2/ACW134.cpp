//
// Created by rdstihz on 2020/12/20.
//
#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;

int a[maxn], q[maxn];
int n;
bool cmp(int x,int y) {
    if(a[x] == a[y]) return x < y;
    return a[x] < a[y];
}

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        q[i] = i;
    }

    sort(q + 1, q + 1 + n, cmp);

    int ans = 0;
    int p = 1; // 0 down , 1 up
    int last = n + 1;
    for(int i = 1;i <=n ;i ++) {
        int l = q[i];
        while(a[q[i+1]] == a[q[i]] && i <= n) i++;
        int r = q[i];

        if(p == 0) {
            if(r < last) {
                last = l;
            }
            else{
                p = 1;
                last = r;
            }
        }
        else if( p == 1) {
            if(l > last) {
                last = r;
            }
            else {
                ans++;
                p = 0;
                last = l;
            }
        }

    }

    cout << ans << endl;

    return 0;
}