#include <bits/stdc++.h>

using namespace std;

const int maxn = 500000 + 100;

struct Node {
    int len, fa;
    int ch[26];
} node[maxn];
int idx = 1, last = 1;

char s1[maxn], s2[maxn];

void extend(int c) {
    int p = last, np = ++idx;
    node[np].len = node[p].len + 1;
    for(;p && !node[p].ch[c]; p = node[p].fa) {
        node[p].ch[c] = np;
    }
    if(!p) {
        node[np].fa = 1;
    }else {
        int q = node[p].ch[c];
        if(node[q].len == node[p].len + 1) {
            node[np].fa = q;
        }else {
            int nq = ++idx;
            node[nq] = node[q];
            node[q].fa = node[np].fa = nq;
            node[nq].len = node[p].len + 1;

            for(;p && node[p].ch[c] == q; p = node[p].fa) {
                node[p].ch[c] = nq;
            }
 
        }
    }
    last = np;
}

int main() {
    scanf("%s%s", s1 + 1, s2 + 1);
    int n = strlen(s1 + 1), m = strlen(s2 + 1);
    for(int i = 1; i <= n; i++)
        extend(s1[i] - 'a');
    
    int ans = 0;
    int cur = 1, l = 0;

    for(int i = 1; i <= m; i++) {
        while(cur && !node[cur].ch[s2[i] - 'a']) {
            cur = node[cur].fa;
            l = node[cur].len;
        }
            
        
        if(cur) {
            l++;
            ans = max(ans, l);
            cur = node[cur].ch[s2[i] - 'a'];
        }else cur = 1;

    }

    printf("%d\n", ans);
    return 0;
}