/*
    Created by rdstihz at 2021-11-17 21:38:51
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 1000000 + 100;

int a[maxn], b[maxn], c[maxn];
char s[maxn];

set<int> S0, S9, S;

int getVal(int i) {
    if(S0.count(i)) 
        return 0;
    else if(S9.count(i))
        return 9;
    else return c[i];
}

int main() {

    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; i++)
        a[i] = s[i] - '0';
    scanf("%s", s + 1);
    for(int i = 1; i <= n; i++)
        b[i] = s[i] - '0';
    
    for(int i = n; i >= 1; i--) {
        c[i] += a[i] + b[i];
        c[i - 1] += c[i] / 10;
        c[i] %= 10;
    }

    
    for(int i = 1; i <= n; i++) {
        if(c[i] == '9')
            S9.insert(i);
        else if(c[i] == '0')
            S0.insert(i);
        else
            S.insert(i);
    }
 

    while(q--) {
        int i, j, d;
        scanf("%d%d%d", &i, &j, &d);
        int delta = 0, cnt = 0;
        if(i == 1) {
            cnt += d != a[j];
            delta = d - a[j];
            a[j] = d;
        }else if(i == 2) {
            cnt += d != b[j];
            delta = d - b[j];
            b[j] = d;
        }

        if(delta == 0) {
            printf("%d %d\n",getVal(j),0);
            continue;
        }

        int pre = getVal(j);
        int suc = pre + delta;

        if(pre == 9 && (suc % 10 + 10) % 10 != 9)
            S9.erase(j);
        if(pre == 0 && (suc % 10 + 10) % 10 != 0)
            S0.erase(j);

        c[j] = (suc % 10 + 10) % 10;
        if(c[j] == 0) 
            S0.insert(j);
        else if(c[j] == 9)
            S9.insert(j);
        else 
            S.insert(j);

        if(suc > 9) { //进位
            auto it = S.lower_bound(j);
            if(it != S.begin()) {
                
            }
        }



    }


    return 0;
}