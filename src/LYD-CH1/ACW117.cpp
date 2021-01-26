#include <cstdio>
#include <cctype>

int read(){
	char c = getchar();
	while(!(isalpha(c) || isdigit(c))) c = getchar();
	if(isdigit(c)) return c-'0' ? c-'0':10;
	else if(c == 'J') return 11;
	else if(c == 'Q') return 12;
	else if(c == 'K') return 13;
	else if(c == 'A') return 1;
	else return -1;
	 
} 

int a[20][5];
int p[20];

int main(){
	
	for(int i = 1;i<=13;i++)
		for(int j = 1;j<=4;j++)
			a[i][j] = read();
	
	for(int i = 1;i<=12;i++) p[i] = 4;
	
	for(int i = 1;i<=4;i++){
		for(int t = a[13][i];t != 13;t=a[t][p[t]--]) ;
	}
	int ans = 0;
	for(int i = 1;i<=12;i++) if(!p[i]) ans++;
	printf("%d\n",ans);
	
	
	return 0;
} 
