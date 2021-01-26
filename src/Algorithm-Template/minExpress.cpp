#include <bits/stdc++.h>

using namespace std;

const int maxn = 600000 + 100;

int a[maxn];
int n;

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }


    int i = 1;
    int j = 2;
    int k;
    while (i <= n && j <= n) {
        for (k = 0; k < n && a[i + k] == a[j + k]; k++);
        if (k == n) break;

        if (a[i + k] < a[j + k]) {
            j = j + k + 1;
            if (i == j) j++;
        } else {
            i = i + k + 1;
            if (i == j) i++;
        }


    }

    int t = min(i,j);

    for(int k = 0; k < n; k++) {
        printf("%d ",a[t + k]);
    }
    printf("\n");

    return 0;
}