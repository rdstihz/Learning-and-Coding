#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 1000000 + 100;

int trie[20000][26];
int n;
int tot;

char s[maxn];
char str[200][100];
int val[20000];

void insert(char *s, int id) {
    int u = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (!trie[u][s[i] - 'a'])
            trie[u][s[i] - 'a'] = ++tot;
        u = trie[u][s[i] - 'a'];
    }
    val[u] = id;
}

int fail[20000];

void getFail() {

    queue<int> Q;
    for (int i = 0; i < 26; i++) {
        if (trie[0][i]) {
            Q.push(trie[0][i]);
        }
    }

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < 26; i++) {
            if (trie[u][i]) {
                fail[trie[u][i]] = trie[fail[u]][i];
                Q.push(trie[u][i]);
            } else {
                trie[u][i] = trie[fail[u]][i];
            }
        }
    }

}

int cnt[maxn];

void query(char *s) {
    int len = strlen(s);

    int u = 0;

    for (int i = 0; i < len; i++) {
        u = trie[u][s[i] - 'a'];

        for (int j = u; j ; j = fail[j]) {
            if (val[j] > 0) cnt[val[j]]++;
        }

    }

}

int main() {

    while (scanf("%d", &n), n) {

        memset(trie, 0, sizeof(trie));
        memset(val, 0, sizeof(val));
        memset(fail, 0, sizeof(fail));
        memset(cnt, 0, sizeof(cnt));

        tot = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%s", str[i]);
            insert(str[i], i);
        }

        getFail();
        scanf("%s", s);
        query(s);

        int ans = 0;

        for (int i = 1; i <= n; i++) ans = max(ans, cnt[i]);
        printf("%d\n", ans);
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == ans) {
                printf("%s\n", str[i]);
            }
        }

    }


    return 0;
}