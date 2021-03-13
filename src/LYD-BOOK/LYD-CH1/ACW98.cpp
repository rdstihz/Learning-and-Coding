#include <cstdio>
#include <cmath>

typedef long long LL;


void find(int n,LL a,int& x,int& y){
	if(n == 1) {
		if(a == 1) x = 1,y = 1;
		else if(a == 2) x = 1,y = 2;
		else if(a == 3) x = 2,y = 2;
		else if(a == 4) x = 2,y = 1;
		
		return ;
	}
	
	LL len = 1ll << n; //边长
	LL num = 1ll << (2*n - 2);//每部分的个数
	 
	int t = 1;
	while(a > num) {
		t++; a-= num;
	}
	
	find(n-1,a,x,y);
	
	if(t == 1){
		int temp = x; x = y; y = temp;
	}else if(t == 2){
		y += len/2;
	}else if(t == 3){
		x += len/2; y += len/2;
	}else if(t == 4){
		int temp = x;
		x = len+1-y;
		y = len/2+1 - temp;
	}
	
	 
}


int main(){
	int T;
	scanf("%d",&T);
	
	while(T--){
		int n;
		scanf("%d",&n);
		LL a,b;
		scanf("%lld%lld",&a,&b);
		
		int x1,y1,x2,y2;
		find(n,a,x1,y1);
		find(n,b,x2,y2);
		double ans = sqrt( 100.0*(x2-x1)*(x2-x1) + 100.0*(y2-y1)*(y2-y1));
		printf("%.0lf\n",ans);
	}
	
	
	return 0;
}
