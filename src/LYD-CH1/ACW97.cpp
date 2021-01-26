#include <cstdio>


const int P = 9901;


int pow_mod(int a,int b){
	int res = 1;
	while(b){
		if(b&1) res = (res*a) % P;
		a = (a*a) % P;
		b >>= 1;
	}
	return res%P;
}

int sum(int p,int c){
	if(c == 0) return 1;
	if(c%2){
		return ( sum(p,c/2) * (1+pow_mod(p,c/2+1))  )% P;
	}else{
		return ((sum(p,c/2-1)*(1+pow_mod(p,c/2))%P) + pow_mod(p,c) ) % P; ;
	}
	
}

int main(){
	
	int a,b;
	scanf("%d%d",&a,&b);
	int ans = 1;
	for(int i = 2;i<=a;i++){
		int c = 0;
		while(a % i == 0){
			c ++;
			a /= i;
		}
		if(c) ans = (ans*sum( i%P,b*c )) % P;
	} 
	if(!a) printf("0\n");
	else printf("%d\n",ans);
	
	return 0;
}
