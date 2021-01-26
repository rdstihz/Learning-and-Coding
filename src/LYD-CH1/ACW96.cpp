#include <cstdio>

int f[15];
int g[15];

int min(int a,int b){
	return a<b?a:b; 
}

int main(){
    
    f[0] = 0;
    f[1] = 1;
    for(int i = 1;i<=12;i++) f[i] = 2*f[i-1] + 1;
	
	g[0] = 0;
	g[1] = 1;
	printf("1\n");
	for(int n = 2; n <= 12;n++){
		g[n] = 1000000;
		for(int k = 1;k<n;k++)
			g[n] = min(g[n], 2*g[k] + f[n-k] );
		printf("%d\n",g[n]);
	}
	
	
    
    return 0;
}
