#include <bits/stdc++.h>


using namespace std;

const int maxn = 1000000 + 100;

char s[maxn];

int tot;

int ch[maxn][26];
int root;
int cnt[maxn];

void insert(){
    int u = root;
    int len = strlen(s);

    for(int i = 0;i < len; i++) {
        if(!ch[u][s[i] - 'a'])
            ch[u][s[i] - 'a'] = ++tot;
        u = ch[u][s[i] - 'a'];
    }
    cnt[u]++;
}

int query(){
    int res = 0;
    int u = root;
    int len = strlen(s);

    for(int i = 0; i < len;i++) {
        if(ch[u][s[i] - 'a']) {
            u = ch[u][s[i] - 'a'];
            res += cnt[u];
        }
        else{
            break;
        }

    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    tot = 0;
    root = ++tot;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        insert();
    }

    for (int i = 1; i <= m; i++) {
        cin >> s;
        cout << query() << endl;
    }


    return 0;
}