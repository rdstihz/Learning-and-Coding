#include <cstdio>
#include <cstring>

const int maxn = 6000;

int l[maxn], r[maxn], u[maxn], d[maxn];
int row[maxn], col[maxn], cnt[maxn];
int n, m, idx;
int ans[maxn], top;

void init() {
    for (int i = 0; i <= m; i++) {
        l[i] = i - 1, r[i] = i + 1;
        u[i] = d[i] = i;
    }
    l[0] = m, r[m] = 0;
    idx = m;
}

void add(int& hh, int& tt, int x, int y) {
    idx++;
    row[idx] = x, col[idx] = y, cnt[y]++;
    u[idx] = y, d[idx] = d[y], u[d[y]] = idx, d[y] = idx;
    r[hh] = l[tt] = idx;
    r[idx] = tt, l[idx] = hh;
    tt = idx;
}

void remove(int p) {
    l[r[p]] = l[p], r[l[p]] = r[p];
    for (int i = d[p]; i != p; i = d[i]) {
        for (int j = r[i]; j != i; j = r[j]) {
            cnt[col[j]]--;
            u[d[j]] = u[j], d[u[j]] = d[j];
        }
    }
}

void resume(int p) {
    for (int i = u[p]; i != p; i = u[i]) {
        for (int j = l[i]; j != i; j = l[j]) {
            u[d[j]] = j, d[u[j]] = j;
            cnt[col[j]]++;
        }
    }
    l[r[p]] = p, r[l[p]] = p;
}

bool dfs() {
    if (!r[0]) return true;
    int p = r[0];
    for (int i = r[0]; i; i = r[i])
        if (cnt[i] < cnt[p])
            p = i;

    remove(p);
    for (int i = d[p]; i != p; i = d[i]) {
        ans[++top] = row[i];
        for (int j = r[i]; j != i; j = r[j])
            remove(col[j]);
        if (dfs()) return true;
        for (int j = l[i]; j != i; j = l[j])
            resume(col[j]);
        top--;
    }
    resume(p);
    return false;
}

int main() {

    scanf("%d%d", &n, &m);
    init();
    for (int i = 1; i <= n; i++) {
        int hh = idx + 1, tt = idx + 1;
        for (int j = 1; j <= m; j++) {
            int x;
            scanf("%d", &x);
            if (x) add(hh, tt, i, j);
        }
    }

    if (dfs()) {
        for (int i = 1; i <= top; i++)
            printf("%d ", ans[i]);
        printf("\n");
    } else {
        printf("No Solution!\n");
    }

    return 0;
}
