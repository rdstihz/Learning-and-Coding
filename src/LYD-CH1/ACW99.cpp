#include <cstdio>
#define p (i+r-1)
#define q (j+r-1)


const int maxn = 5010;
const int N = 5001;

int w[maxn][maxn];

int main(){
	int n,r;
	scanf("%d%d",&n,&r);
	int a,b,c;
	while(n--){
		scanf("%d%d%d",&a,&b,&c);
		w[a+1][b+1] += c;
	}
	
	for(int i = 1;i<=N;i++)
		for(int j = 1;j<=N;j++)
			w[i][j] += w[i-1][j] + w[i][j-1] - w[i-1][j-1];
	int ans = 0;
	int t;
	for(int i = 1;p<=N;i++)
		for(int j = 1;q<=N;j++){
			t = w[p][q] - w[p][j-1] - w[i-1][q] + w[i-1][j-1];
			ans = ans < t? t: ans;
		}
	if(r >= N) ans = w[N][N];
	printf("%d\n",ans);
	
	return 0;
}
