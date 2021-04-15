#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
int N[65],M[65],k,mem[2][2][2][65][2];
ll read() {
	char c=getchar(); ll x=0;
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
void add(int &x,int y) {
	x+=y;
	if (x>=mod) x-=mod;
}
int times(int x,int y) {
	return 1LL*x*y%mod;
}
int dfs(int lim1,int lim2,int equal,int p,int f) {
	if (p<0) {
		if (f) return 1;
		else return 0;
	}
	if (mem[lim1][lim2][equal][p][f]!=-1) return mem[lim1][lim2][equal][p][f];
	int ans=0;
	if (lim1) {
		if (lim2) {
			if (equal) {
				if (N[p]==M[p]) {
					add(ans,dfs(1,1,1,p-1,f));
					add(ans,times(N[p],dfs(1,0,0,p-1,f)));
				}
				else if (N[p]<M[p]) {
					add(ans,dfs(1,0,1,p-1,f));
					add(ans,times(N[p],dfs(1,0,0,p-1,f)));
				}
				else {
					add(ans,times(M[p],dfs(1,0,0,p-1,f)));
					add(ans,dfs(1,1,0,p-1,f));
				}
			}
			else {
				if (N[p]<M[p]) {
					add(ans,times(M[p]-N[p]-1,dfs(1,0,0,p-1,1)));
					add(ans,times(N[p]+1,dfs(1,0,0,p-1,f)));
					add(ans,dfs(1,1,0,p-1,1));
				}
				else {
					add(ans,times(M[p],dfs(1,0,0,p-1,f)));
					add(ans,dfs(1,1,0,p-1,f));
				}
			}
			
			if (equal) {
				if (N[p]<=M[p]) {
					add(ans,times(N[p],dfs(0,0,1,p-1,f)));
					add(ans,times(1LL*N[p]*(N[p]-1)/2%mod,dfs(0,0,0,p-1,f)));
				}
				else {
					add(ans,dfs(0,1,1,p-1,f));
					add(ans,times(M[p],dfs(0,0,0,p-1,f)));
					add(ans,times(M[p],dfs(0,0,1,p-1,f)));
					add(ans,times(1LL*M[p]*(M[p]-1)/2%mod,dfs(0,0,0,p-1,f)));
					add(ans,times(1LL*M[p]*(N[p]-M[p]-1)%mod,dfs(0,0,0,p-1,f)));
					add(ans,times(N[p]-M[p]-1,dfs(0,1,0,p-1,f)));
				}
			}
			else {
				if (N[p]<=M[p]) {
					add(ans,times(((1LL*M[p]*N[p]-1LL*N[p]*(N[p]+1)/2)%mod+mod)%mod,dfs(0,0,0,p-1,1)));
					add(ans,times(1LL*N[p]*(N[p]+1)/2%mod,dfs(0,0,0,p-1,f)));
					add(ans,times(N[p],dfs(0,1,0,p-1,1)));
				}
				else {
					add(ans,times(((1LL*M[p]*M[p]-1LL*M[p]*(M[p]+1)/2)%mod+mod)%mod,dfs(0,0,0,p-1,1)));
					add(ans,times(1LL*M[p]*(M[p]+1)/2%mod,dfs(0,0,0,p-1,f)));
					add(ans,times(M[p],dfs(0,1,0,p-1,1)));
					add(ans,times(1LL*M[p]*(N[p]-M[p])%mod,dfs(0,0,0,p-1,f)));
					add(ans,times(N[p]-M[p],dfs(0,1,0,p-1,f)));
				}
			}
		}
		else {
			if (equal) {
				if (N[p]<k) {
					add(ans,dfs(1,0,1,p-1,f));
					add(ans,times(N[p],dfs(1,0,0,p-1,f)));
				}
				else {
					add(ans,times(k,dfs(1,0,0,p-1,f)));
				}
			}
			else {
				add(ans,times(k-N[p]-1,dfs(1,0,0,p-1,1)));
				add(ans,times(N[p]+1,dfs(1,0,0,p-1,f)));
			}
			
			if (equal) {
				if (N[p]<=k) {
					add(ans,times(N[p],dfs(0,0,1,p-1,f)));
					add(ans,times(1LL*N[p]*(N[p]-1)/2%mod,dfs(0,0,0,p-1,f)));
				}
				else {
					add(ans,times(k,dfs(0,0,1,p-1,f)));
					add(ans,times(1LL*k*(k-1)/2%mod,dfs(0,0,0,p-1,f)));
					add(ans,times(1LL*k*(N[p]-k)%mod,dfs(0,0,0,p-1,f)));
				}
			}
			else {
				add(ans,times(((1LL*k*N[p]-1LL*N[p]*(N[p]+1)/2)%mod+mod)%mod,dfs(0,0,0,p-1,1)));
				add(ans,times(1LL*N[p]*(N[p]+1)/2%mod,dfs(0,0,0,p-1,f)));
			}
		}
	}
	else {
		if (lim2) {
			if (k<=M[p]) {
				if (equal) {
					add(ans,times(k,dfs(0,0,1,p-1,f)));
					add(ans,times(1LL*k*(k-1)/2%mod,dfs(0,0,0,p-1,f)));
				}
				else {
					add(ans,times(((1LL*M[p]*k-1LL*k*(k+1)/2)%mod+mod)%mod,dfs(0,0,0,p-1,1)));
					add(ans,times(1LL*k*(k+1)/2%mod,dfs(0,0,0,p-1,f)));
					add(ans,times(k,dfs(0,1,0,p-1,1)));
				}
			}
			else {
				if (equal) {
					add(ans,dfs(0,1,1,p-1,f));
					add(ans,times(M[p],dfs(0,0,0,p-1,f)));
					add(ans,times(M[p],dfs(0,0,1,p-1,f)));
					add(ans,times(1LL*M[p]*(M[p]-1)/2%mod,dfs(0,0,0,p-1,f)));
					add(ans,times(1LL*(k-M[p]-1)*M[p]%mod,dfs(0,0,0,p-1,f)));
					add(ans,times(k-M[p]-1,dfs(0,1,0,p-1,f)));
				}
				else {
					add(ans,times(1LL*M[p]*(M[p]-1)/2%mod,dfs(0,0,0,p-1,1)));
					add(ans,times(1LL*M[p]*(M[p]+1)/2%mod,dfs(0,0,0,p-1,f)));
					add(ans,times(M[p],dfs(0,1,0,p-1,1)));
					add(ans,times(1LL*(k-M[p])*M[p]%mod,dfs(0,0,0,p-1,f)));
					add(ans,times(k-M[p],dfs(0,1,0,p-1,f)));
				}
			}
		}
		else {
			if (equal) {
				add(ans,times(k,dfs(0,0,1,p-1,f)));
				add(ans,times(1LL*k*(k-1)/2%mod,dfs(0,0,0,p-1,f)));
			}
			else {
				add(ans,times(1LL*k*(k-1)/2%mod,dfs(0,0,0,p-1,1)));
				add(ans,times(1LL*k*(k+1)/2%mod,dfs(0,0,0,p-1,f)));
			}
		}	
	}
	return mem[lim1][lim2][equal][p][f]=ans;
}
int main() {
	int T=read(); k=read();
	while (T--) {
		ll n=read(),m=read();
		if (m>n) m=n;
		memset(N,0,sizeof(N));
		memset(M,0,sizeof(M));
		int p=0;
		while (m) {
			M[p++]=m%k;
			m/=k;
		}
		p=0;
		while (n) {
			N[p++]=n%k;
			n/=k;
		}
		--p;
		memset(mem,-1,sizeof(mem));
		printf("%d\n", dfs(1,1,1,p,0));
	}
	return 0;
}

