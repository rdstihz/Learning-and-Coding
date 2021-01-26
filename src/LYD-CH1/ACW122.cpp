#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long LL;
const int maxn = 1000000 + 10;

LL c[maxn];
LL s[maxn];

int main(){
	int n;
	scanf("%d",&n);
	LL sum = 0;
	for(int i = 1;i<=n;i++) {
		scanf("%lld",c+i);
		sum += c[i];
	}
	LL t = sum / n;
	
	for(int i = 1;i<=n;i++) c[i] -= t;
	
	for(int i = 1;i<=n;i++) s[i] = s[i-1] + c[i];
	sort(s+1,s+1+n);
	
	t = s[(n+1)/2];
	LL ans = 0;
	for(int i = 1;i<=n;i++) ans += abs(t-s[i]);
	printf("%lld\n",ans);
	
	return 0;
}
