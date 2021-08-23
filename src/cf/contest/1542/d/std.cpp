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
const int p=998244353;
char s[5];
int a[505];
int f[505][505];
void add(int &x,int y) {
	x+=y;
	if (x>=p) x-=p;
}
int main() {
	int n=read();
	for (int i=1; i<=n; i++) {
		scanf("%s", s);
		if (s[0]=='+') a[i]=read();
		else a[i]=-1;
	}
	int ans=0;
	for (int x=1; x<=n; x++) {
		if (a[x]>0) {
			f[0][0]=1;
			for (int j=1; j<=n; j++) f[0][j]=0;
			for (int i=1; i<=n; i++) {
				for (int j=0; j<=n; j++) {
					if (i==x) {
						if (j>0) f[i][j]=f[i-1][j-1];
						else f[i][j]=0;
						continue;
					}
					f[i][j]=f[i-1][j];
					if (a[i]==-1) {
						if (j==0 && i>x) {
							
						}
						else {
							if (j+1<=n) add(f[i][j],f[i-1][j+1]);
							if (j==0) add(f[i][j],f[i-1][j]);
						}
					}
					else if (a[i]<a[x] || (a[i]==a[x] && i<=x)) {
						if (j>0) add(f[i][j],f[i-1][j-1]);
					}
					else {
						add(f[i][j],f[i-1][j]);
					}
				}
			}
			int s=0;
			for (int j=1; j<=n; j++) add(s,f[n][j]);
//			cout<<s<<" "<<x<<endl;
			add(ans,1LL*s*a[x]%p);
		}
	}
	printf("%d\n", ans);
	return 0;
}
