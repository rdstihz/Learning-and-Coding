#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 100;
long long a[maxn];
int n;

int main(){
	scanf("%d",&n);
	
	for(int i = 1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+1+n);
	long long t = a[(n+1)/2];
	long long ans = 0;
	
	for(int i = 1;i<=(n+1)/2;i++)
		ans += t - a[i];
	for(int i = (n+1)/2+1;i<=n;i++)
		ans += a[i] - t;
	printf("%lld\n",ans);
	
	return 0;
}
