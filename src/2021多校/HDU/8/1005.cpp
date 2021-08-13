#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod=998244353;

const int N=1100;

ll quick_pow(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
char s[N];
ll dp[N];
ll C[N][N];
ll sum[N];

int main()
{
	for(int i=0;i<=1000;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			C[i][j]%=mod;
		}
	}
	int T;
	scanf("%d",&T);
	while(T--){
		int k;
		scanf("%d",&k);
		scanf("%s",s+1);
		int n=strlen(s+1);
		for(int i=0;i<=1000;i++){
			for(int j=0;j<=min(k,i);j++){
				sum[i]+=C[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			int cur=0;
			for(int j=i-1;j>=0;j--){
				cur+=(s[j+1]-'0')*quick_pow(10,i-j-1);
				if(j==0){
					dp[i]+=cur;
					dp[i]%=mod;
					continue;
				}
				dp[i]=(dp[i]+dp[j]+1ll*sum[j-1]*cur%mod)%mod;
			}
		}
		printf("%lld\n",dp[n]);
	}	
	return 0;
}