#include <cstdio>

typedef long long LL;

int main(){
	LL a,b,p;
	scanf("%lld%lld%lld",&a,&b,&p);
	
	LL res = 0;
	while(b){
		if(b&1) res = (res+a) % p;
		a = (2*a) % p;
		b >>= 1;
	}
	printf("%lld\n",res);
	
	return 0;
} 
