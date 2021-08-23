/*
    Created by rdstihz at 2021-07-17 23:18:06
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;
int a[maxn], b[maxn];
int match[maxn];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", a + i);

        for(int i = 1; i <= n; i++) {
            b[i] = match[i] = 0;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!match[a[i]]) {
                match[a[i]] = i;
                b[i] = a[i];
                cnt++;
            }
        }
        vector<int> nums;
        for (int i = 1; i <= n; i++)
            if (!match[i])
                nums.push_back(i);
        int cur = 0;
        for (int i = 1; i <= n; i++) 
            if (!b[i]) {
                if (i != nums[cur]) {
                    b[i] = nums[cur];
                    cur++;
                } else {
                    b[match[a[i]]] = nums[cur];
                    cur++;
                    b[i] = a[i];
                    match[a[i]] = i;
                }
            }

        printf("%d\n", cnt);
        for (int i = 1; i <= n; i++)
            printf("%d ", b[i]);
        printf("\n");
    }

    return 0;
}