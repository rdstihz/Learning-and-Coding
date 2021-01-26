#include <cstdio>

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int S = 0;S<(1<<n);S++){
		int cnt = 0;
		for(int i = 0;i<n;i++)
			if(S & (1<<i)) cnt++;
		if(cnt == m){
			for(int i = 0;i<n;i++)
				if(S&(1<<i)) printf("%d ",i+1);
			printf("\n");
			
		}
		
	}
	
	
	return 0;
}
