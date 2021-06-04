//Luogu P3808

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 1000000 + 100;

int trie[maxn][26], tag[maxn];
int tot;
char s[maxn];
int fail[maxn];

void insert(char* s) {
    int len = strlen(s), u = 0;
    for (int i = 0; i < len; i++) {
        if (!trie[u][s[i] - 'a'])
            trie[u][s[i] - 'a'] = ++tot;
        u = trie[u][s[i] - 'a'];
    }
    tag[u]++; //标记一个模式串
}

void getFail() {
    queue<int> Q;
    for (int i = 0; i < 26; i++)
        if (trie[0][i])
            Q.push(trie[0][i]);

    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < 26; i++)
            if (trie[u][i]) {
                fail[trie[u][i]] = trie[fail[u]][i];
                Q.push(trie[u][i]);
            } else
                trie[u][i] = trie[fail[u]][i];
    }
}

int query(char* s) {
    int res = 0;
    int n = strlen(s);
    int u = 0;
    for (int i = 0; i < n; i++) {
        u = trie[u][s[i] - 'a'];
        for (int j = u; j && tag[j] != -1; j = fail[j]) {
            res += tag[j];
            tag[j] = -1;
        }
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        insert(s);
    }
    getFail();
    scanf("%s", &s);
    printf("%d\n", query(s));
    return 0;
}