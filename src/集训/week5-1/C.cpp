#include <iostream>
#include <queue>

using namespace std;
int n;
int num[10];
void dfs(int sum, int last,int d) {

    if (sum == n) {
        if(d <= 1) return ;
        cout << num[1];
        for(int i = 2; i <= d;i++)
            cout << '+' << num[i];
        cout << endl;
        return;
    }

    for (int i = last; i <= n - sum; i++) {
        num[d + 1] = i;
        dfs(sum + i, i, d + 1);
    }
}

int main() {
 
    cin >> n;
    dfs(0,1,0);
    
    return 0;
}