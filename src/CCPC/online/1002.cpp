#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;

char s[maxn][maxn];
int len[maxn];
int pos[maxn];
char seq[2 * 100 * 30000 + 10];
bool vis[maxn];
int id[maxn];

int cnt[maxn];
int num;

void add(int i) {
    cnt[i]++;
    if (cnt[i] == 1)
        num++;
}

void remove(int i) {
    cnt[i]--;
    if (cnt[i] == 0)
        num--;
}

void solve() {
    int n;
    scanf("%d", &n);
    int m = 1;
    memset(vis, 0, sizeof(vis));
    memset(pos, 0, sizeof(pos));
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        len[i] = strlen(s[i] + 1);
        m = m / __gcd(m, len[i]) * len[i];

        for (int j = 1; j <= len[i]; j++)
            vis[s[i][j] - 'a'] = true;
    }

    int ps = 0;
    int i = 0, j = 0;
    m *= n;
    m *= 2;
    for (int k = 1; k <= m; k++) {
        i++;
        if (i > n) i = 1;
        pos[i]++;
        if (pos[i] > len[i]) pos[i] = 1;
        seq[k] = s[i][pos[i]];
    }
    seq[m + 1] = 0;

    vector<int> chs;
    for (int i = 0; i < 26; i++)
        if (vis[i]) {
            chs.push_back(i);
            id[i] = chs.size() - 1;
        }
    int tot = chs.size();
    num = 0;
    int ans = m;
    for (int i = 0; i < 26; i++)
        cnt[i] = 0;

    i = 1;
    for (j = 1; j <= m; j++) {
        add(id[seq[j] - 'a']);
        while (i <= j && cnt[id[seq[i] - 'a']] > 1) {
            remove(id[seq[i] - 'a']);
            i++;
        }
        if (num == tot) ans = min(ans, j - i + 1);
    }
    printf("%d\n", ans);
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}
/*
2
2
abc
bd
2
bab
bbc
*/