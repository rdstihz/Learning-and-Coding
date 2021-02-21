#include <iostream>

using namespace std;

int cnt[14];
long long ans;
void dfs(int d, int last) {
    if (d == 13) {
        ans++;
        return;
    } 
    if(last > 13) return;
    dfs(d, last + 1);

    if (cnt[last] < 4) {
        cnt[last]++;
        dfs(d + 1, last);
        cnt[last]--;
    }
}

int main() {
    ans = 0;
    dfs(0, 1);
    cout << ans << endl;
    return 0;
}