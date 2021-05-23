#include <bits/stdc++.h>

using namespace std;

const int maxn = 50000 + 100;

char s[maxn];
int p[maxn];

int n;

struct Tree {
    inline int lowbit(int x) {
        return x & -x;
    }
    int C[maxn];

    void add(int p) {
        for (; p <= n; p += lowbit(p))
            C[p]++;
    }

    int sum(int p) {
        int res = 0;
        for (; p; p -= lowbit(p))
            res += C[p];
        return res;
    }

} T1, T2;

int val1[maxn], val2[maxn];
vector<int> nums;

int main() {

    scanf("%d", &n);
    scanf("%s", s + 1);

    int m;
    scanf("%d", &m);
    char ch;
    int a, b, c, d;

    long long ans = 0;
    while (m--) {
        getchar();

        //printf("hehe\n");
        scanf("%c%d%d%d%d", &ch, &a, &b, &c, &d);

        for (int i = 1; i <= n; i++)
            p[i] = p[i - 1] + (s[i] == ch);

        // val1[i] = ai - b * p[i] , 离散化
        for (int i = 0; i <= n; i++) {
            val1[i] = a * i - b * p[i];
            nums.push_back(val1[i]);
        }
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for (int i = 0; i <= n; i++)
            val1[i] = lower_bound(nums.begin(), nums.end(), val1[i]) - nums.begin() + 1;
        nums.clear();
        //printf("hehe1\n");

        // val2[i] = ci - d * p[i]
        for (int i = 0; i <= n; i++) {
            val2[i] = c * i - d * p[i];
            nums.push_back(val2[i]);
        }

        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for (int i = 0; i <= n; i++)
            val2[i] = lower_bound(nums.begin(), nums.end(), val2[i]) - nums.begin() + 1;
        nums.clear();
        //printf("hehe2\n");

        // for (int i = 1; i <= n; i++)
        //     printf("%d ", val1[i]);
        // printf("\n");

        // for (int i = 1; i <= n; i++)
        //     printf("%d ", val2[i]);
        // printf("\n");

        memset(T1.C, 0, 4 * maxn);
        memset(T2.C, 0, 4 * maxn);
        T1.add(val1[0]);
        T2.add(val2[0]);
        for (int i = 1; i <= n; i++) {
            int t1 = T1.sum(val1[i]);
            int t2 = T2.sum(val2[i]);
            ans += t2 - t1;
            T1.add(val1[i]);
            T2.add(val2[i]);
        }
        //cout << ans << endl;
    }

    printf("%lld\n", ans);

    return 0;
}