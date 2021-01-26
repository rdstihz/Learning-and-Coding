#include <cstdio>

typedef long long LL;

const int maxn = 100000 + 10;
LL a[maxn],b[maxn];





int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++) scanf("%d",a+i);
	
	for(int i = 1;i<=n;i++) b[i] = a[i] - a[i-1];
	LL p = 0;
	LL q = 0;
	
	for(int i = 2;i<=n;i++) {
		if(b[i] > 0) p += b[i];
		else if(b[i] < 0) q -= b[i];
	}
	
	printf("%lld\n%lld\n",p>q?p:q, p>q?p-q+1:q-p+1);
	
	
	return 0;
} 
