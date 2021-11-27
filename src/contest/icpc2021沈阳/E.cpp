#include <bits/stdc++.h>

using namespace std;
const int maxn = 400000 + 100;

struct Node {
    int len, fa;
    int ch[26];
} node[maxn];
int es[maxn];
int idx = 1, last = 1;
char s[maxn];

int q[maxn], c[maxn];

void extend(int c) {
    int p = last, np = ++idx;
    es[np] = 1;
    node[np].len = node[p].len + 1;
    for(;p && !node[p].ch[c]; p = node[p].fa) {
        node[p].ch[c] = np;
    }
    if(!p)
        node[np].fa = 1;
    else {
        int q = node[p].ch[c];
        if(node[q].len == node[p].len + 1) {
            node[np].fa = q;
        }else {
            int nq = ++idx;
            node[nq] = node[q];
            node[nq].len = node[p].len + 1;
            node[q].fa = node[np].fa = nq;
            for(;p && node[p].ch[c] == q; p = node[p].fa)
                node[p].ch[c] = nq; 
        }
    }
    last = np;
}

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for(int i = 0; i < n; i++)
        extend(s[i] - 'a');
    
    for(int i = 1; i <= idx; i ++)
        c[node[i].len] ++;
    for(int i = 1; i <= idx; i++)
        c[i] += c[i - 1];
    
    for(int i = idx; i >= 1; i--)
        q[c[node[i].len]--] = i;
    

    for(int i = idx; i >= 1; i--) {
        int u = q[i];
        es[node[u].fa] += es[u];
    }

    char T[] = "edgnb";
    int cur = 1;
    for(int i = 0; i < 5 && cur; i++)
        cur = node[cur].ch[T[i] - 'a'];
    es[0] = 0;
    printf("%d\n", es[cur]);
    return 0;
}