//Luogu P3796

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

char s[200][100];
char t[1000000 + 100];
int trie[20000][26], fail[20000], tag[20000], tot;
int n;

void insert(char* s, int id) {
    int len = strlen(s), u = 0;
    for (int i = 0; i < len; i++) {
        if (!trie[u][s[i] - 'a']) trie[u][s[i] - 'a'] = ++tot;
        u = trie[u][s[i] - 'a'];
    }
    tag[u] = id;
}

void getFail() {
    queue<int> Q;
    for (int i = 0; i < 26; i++)
        if (trie[0][i])
            Q.push(trie[0][i]);

    while (Q.size()) {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < 26; i++) {
            if (trie[u][i]) {
                fail[trie[u][i]] = trie[fail[u]][i];
                Q.push(trie[u][i]);
            } else
                trie[u][i] = trie[fail[u]][i];
        }
    }
}

int cnt[200];

void query(char* s) {
    int len = strlen(s);
    int u = 0;
    for (int i = 0; i < len; i++) {
        u = trie[u][s[i] - 'a'];
        for (int j = u; j; j = fail[j])
            if (tag[j])
                cnt[tag[j]]++;
    }
}

int main() {

    while (scanf("%d", &n), n) {
        memset(trie, 0, sizeof(trie));
        memset(tag, 0, sizeof(tag));
        memset(fail, 0, sizeof(fail));
        memset(cnt, 0, sizeof(cnt));

        tot = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%s", s[i]);
            insert(s[i], i);
        }

        getFail();
        scanf("%s", t);
        query(t);

        int ans = 0, maxv = 0;
        for (int i = 1; i <= n; i++)
            if (cnt[i] > maxv)
                maxv = cnt[i], ans = i;

        printf("%d\n", maxv);
        for(int i = 1; i <= n; i++)
            if(cnt[i] == maxv)
                printf("%s\n", s[i]);
    }

    return 0;
}