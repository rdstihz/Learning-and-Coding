#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 100000 + 100;

LL a[maxn], b[maxn];

int q[maxn];

bool cmp(int x, int y) {
    return a[x] + b[x] > a[y] + b[y];
}

int main() {
    int n;
    while (cin >> n) {

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            q[i] = i;
        }

        sort(q + 1, q + 1 + n, cmp);
        LL A = 0, B = 0;
        for(int e = 1; e <= n; e++) {
            int i = q[e];
            if(e % 2)
                A += a[i];
            else
                B += b[i];
        }

        if(A > B) {
            cout << "Alice" << endl;
        }else if(A == B){
            cout << "AEMSHANA" << endl;
        }else{
            cout << "Bob" << endl;
        }
    }
}