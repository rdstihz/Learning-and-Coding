
#include <bits/stdc++.h>


using namespace std;

const int maxn = 1000000 + 100;

char s[10 * maxn];

int trie[maxn][26];
int tot;
int cnt[maxn];

/*
void insert(char *s) {
    int n = strlen(s);
    int u = 0;

    for (int i = 0; i < n; i++) {
        if (!trie[u][s[i] - 'a'])
            trie[u][s[i] - 'a'] = ++tot;
        u = trie[u][s[i] - 'a'];
    }

    cnt[u] += 1;
}
*/

void insert(char *s){
    int len=strlen(s);int now=0;
    for(int i=0;i<len;i++){
        int v=s[i]-'a';
        if(!trie[now][v])trie[now][v]=++tot;
        now=trie[now][v];
    }
    cnt[now]++;
}

int fail[maxn];


void getFail() {
    fail[0] = 0;
    queue<int> Q;

    for (int i = 0; i < 26; i++) {
        if (trie[0][i])
            Q.push(trie[0][i]);
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

int query(char *s) {
    int n = strlen(s);
    int u = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        u = trie[u][s[i] - 'a'];
        for (int j = u; j && cnt[j] != -1; j = fail[j]) {
            res += cnt[j];
            cnt[j] = -1;
        }

    }
    return res;

}


int main() {

    freopen("P3808_2.in", "r", stdin);
    int n;
    scanf("%d", &n);
    tot = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        insert(s);
    }
    getFail();
    scanf("%s", s);
    printf("%d\n", query(s));

    return 0;
}

