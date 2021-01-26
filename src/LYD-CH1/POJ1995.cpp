#include <cstdio>
typedef long long LL;


LL pow_mod(LL a,LL b,LL p){
	LL res = 1;
	
	while(b){
		if(b&1) res = (res*a) %p;
		a = (a*a) % p;
		b >>= 1;
	}
	
	return res % p;
}


int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		LL p;
		int n;
		scanf("%lld%d",&p,&n);
		LL a,b;
		LL res = 0;
		for(int i = 1;i<=n;i++) {
			scanf("%lld%lld",&a,&b);
			res = (res + pow_mod(a,b,p)) % p;
		}
		
		printf("%lld\n",res);
		
	}
	
	
	return 0;
} 
