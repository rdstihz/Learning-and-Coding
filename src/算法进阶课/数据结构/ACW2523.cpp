#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 100000 + 100;

int color[maxn];
vector<int> temp;

int cnt[maxn];
LL ans[maxn];

int len;

inline int get(int x) {
    return x / len;
}

struct Query {
    int id, l, r;

    bool operator<(const Query& phs) {
        int la = get(l);
        int lb = get(phs.l);
        if (la != lb) return la < lb;
        return r < phs.r;
    }
} query[maxn];

void add(int x, LL& res) {
    cnt[x]++;
    if ((LL)temp[x] * cnt[x] > res)
        res = (LL)temp[x] * cnt[x];
}

int readIn() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();

    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int main() {

    int n, m;
    n = readIn();
    m = readIn();
    len = sqrt(n);

    for (int i = 1; i <= n; i++) {
        color[i] = readIn();
        temp.push_back(color[i]);
    }

    //离散化
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    for (int i = 1; i <= n; i++) {
        color[i] = lower_bound(temp.begin(), temp.end(), color[i]) - temp.begin();
    }

    for (int i = 1; i <= m; i++) {
        query[i].id = i;
        cin >> query[i].l >> query[i].r;
    }

    sort(query + 1, query + 1 + m);

    for (int x = 1; x <= m;) {
        int y = x;

        //块号
        int block = get(query[x].l);

        //块的右端点
        int right = (len - 1) + block * len;

        while (y <= m && query[y].l <= right)
            y++;

        while (x < y && query[x].r <= right) {
            LL res = 0;
            for (int i = query[x].l; i <= query[x].r; i++)
                add(color[i], res);
            ans[query[x].id] = res;

            for (int i = query[x].l; i <= query[x].r; i++)
                cnt[color[i]]--;

            x++;
        }

        int r = right;
        LL res = 0;
        while (x < y) {
            while (r < query[x].r) {
                add(color[++r], res);
            }

            LL backup = res;

            for (int i = right; i >= query[x].l; i--)
                add(color[i], res);

            ans[query[x].id] = res;

            res = backup;
            for (int i = right; i >= query[x].l; i--)
                cnt[color[i]]--;

            x++;
        }

        memset(cnt, 0, sizeof(cnt));
    }

    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;

    return 0;
}