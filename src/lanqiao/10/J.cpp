#include <bits/stdc++.h>

using namespace std;

const int maxn = 3010;

int p[maxn];

void init(int n,int k){
    p[0] = 0;

    for(int i = 1;i <= n; i++) {
        p[i] = p[i - 1];
        int t = i;
        while(t % k == 0) {
            p[i]++;
            t /= k;
        }
    }
}

int main(){
    int t,k;
    cin >> t >> k;

    init(3000, k);

    int n,m;
    while(t--) {
        cin >> n >> m;
        long long ans = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= i && j <= m; j++)
                if(p[i] > p[j] + p[i - j])
                    ans++;

        }

        cout << ans << endl;
    }

    return 0;
}