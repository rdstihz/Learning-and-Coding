/*
    Created by rdstihz at 2021-08-29 23:21:24
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000 + 200;
int a[maxn];
int v;

//int val[] = {0, 1, 6, 4, 2, 3, 5, 4};
int get_and(int i, int j) {
    //return val[i] & val[j];
    cout << "and " << i << " " << j << endl;
    cout << flush;
    cin >> v;
    return v;
}
int get_or(int i, int j) {
    //return val[i] | val[j];
    cout << "or " << i << " " << j << endl;
    cout << flush;
    cin >> v;
    return v;
}
int main() {

    int n, k;
    cin >> n >> k;

    for (int i = 2; i <= n; i++) {
        a[i] = get_and(1, i) + get_or(1, i); // a[1] + a[i]
    }
    //a2 + a3;
    int t = get_and(2, 3) + get_or(2, 3);
    //a1
    a[1] = (a[2] + a[3] - t) / 2;
    for (int i = 2; i <= n; i++)
        a[i] -= a[1];
    sort(a + 1, a + 1 + n);
    // for (int i = 1; i <= n; i++)
    //     printf("%d ", a[i]);
    // printf("\n");
    cout << "finish " << a[k] << endl;

    return 0;
}