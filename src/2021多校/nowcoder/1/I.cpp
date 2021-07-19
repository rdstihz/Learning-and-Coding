#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int read() {
	char c=getchar(); int x=0,f=1;
	while (c<'0' || c>'9') {
		  if (c=='-') f=-1;
		  c=getchar();
	}
	while (c>='0' && c<='9') {
		  x=x*10+c-'0';
		  c=getchar();
	}
	return x*f;
}
const int mod=998244353;
int dp[5005][5005];
int n,p[5005],pos[5005];
int pow_mod(int x,int k) {
	int ans=1;
	while (k) {
		if (k&1) ans=1LL*ans*x%mod;
		x=1LL*x*x%mod;
		k>>=1;
	}
	return ans;
}
void add(int &x,int y) {
	x+=y;
	if (x>=mod) x-=mod;
}
pii t[2][5005];
pii operator + (pii x,pii y) {
	return make_pair((x.first+y.first)%mod,x.second+y.second);
}
pii operator - (pii x,pii y) {
	return make_pair((x.first-y.first+mod)%mod,x.second-y.second);
}
void modify(int x,int y,pii k) {
	for (; y<=n; y+=(y&-y)) t[x][y]=t[x][y]+k;
}
pii query(int x,int y) {
	pii ans=make_pair(0,0);
	for (; y; y-=(y&-y)) ans=ans+t[x][y];
	return ans;
}
int inve[5005];
int main() {
	n=read();
	for (int i=1; i<=n; i++) p[i]=read(),pos[p[i]]=i;
	for (int i=1; i<=n; i++) inve[i]=pow_mod(i,mod-2);
    for (int i=1; i<=n; i++) cout<<i<<" "<<inve[i]<<endl;
	for (int d=n; d>=1; d--) {
		for (int x=1; x<=2; x++) {
			for (int y=1; y<=n; y++) {
				t[x][y]=make_pair(0,0);
			}
		}
		for (int b=d+1; b<=n; b++) {
			modify(1,pos[b],make_pair(dp[pos[d]][pos[b]],1));
			modify(2,pos[b],make_pair(dp[pos[b]][pos[d]],1));
		}
		for (int i=pos[d],c=d-1; c>=0; c--) {
			int j=pos[c];
			pii q=query(1,n)-query(1,j);
			dp[i][j]=(1LL*q.first*pow_mod(q.second,mod-2)+1)%mod;
//			dp[i][j]=0;
//			for (int k=j+1; k<=n; k++) {
//				if (p[k]>p[i]) {
//					add(dp[i][j],dp[i][k]);
//					++cnt;
//				}
//			}
//			dp[i][j]=(1LL*dp[i][j]*pow_mod(cnt,mod-2)+1)%mod;
		}
		for (int j=pos[d],c=d-1; c>=0; c--) {
			int i=pos[c];
			pii q=query(2,n)-query(2,i);
			dp[i][j]=(1LL*q.first*pow_mod(q.second,mod-2)+1)%mod;
			cout<<pow_mod(q.second,mod-2)<<" "<<inve[q.second]<<' '<<q.second<<endl;
//			dp[i][j]=0;
//			for (int k=i+1; k<=n; k++) {
//				if (p[k]>p[j]) {
//					add(dp[i][j],dp[k][j]);
//					++cnt;
//				}
//			}
//			dp[i][j]=(1LL*dp[i][j]*pow_mod(cnt,mod-2)+1)%mod;
		}
	}
    for (int i=1; i<=n; i++) cout<<i<<" "<<inve[i]<<endl;
	int ans=0;
	for (int i=1; i<=n; i++) ans=(ans+dp[i][0])%mod;
	ans=1LL*ans*pow_mod(n,mod-2)%mod;
	printf("%d\n", ans);
	return 0;
}
