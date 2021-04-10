#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 100; 
const int maxm = 200000 + 100;

int to[maxm],flow[maxm],cap[maxm];
int nxt[maxm],fir[maxn];
int tot;

int n,m,s,t;

void add(int a,int b,int c,int f){
	tot++;
	to[tot] = b;cap[tot]=c; flow[tot] = f;
	nxt[tot] = fir[a]; fir[a] = tot; 
}

int dep[maxn];

int q[maxn],l,r;
int maxflow;
bool bfs(){
	memset(dep,0,sizeof(dep));
	dep[s] = 1;
	l = r=  0;
	q[++r] = s;
	
	while(l<r){
		int u = q[++l];
		for(int e = fir[u];e;e=nxt[e]) if(cap[e] > flow[e]){
			int v = to[e];
			if(!dep[v]){
				dep[v] = dep[u]+1;
				q[++r] = v;
				if(v == t) return true;
			}
		}
	}
	return false;
}

int dfs(int u,int rest){
	if(u == t) return rest;
	int fl = 0;
	for(int e = fir[u];e;e=nxt[e]) if(dep[u] + 1== dep[to[e]] && cap[e] > flow[e]){
		int v = to[e];
		int lim = cap[e] - flow[e];
		int k = dfs( v,min(rest, lim ) );
		fl += k;
		flow[e] += k;
		flow[e^1] -= k;
		rest -= k;
		
		if(k == 0) dep[v] = 0;//剪枝 ，v点不可能增广 
		
	}
	if(rest) dep[u] = -1;//剪枝,u点不可能再增广 
	return fl;
}


int main(){
	
	tot = 1;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i =1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c,0);
		add(b,a,0,0);
	}
	int maxflow = 0;
	while(bfs()){
		maxflow += dfs(s,1<<29);
	} 
	printf("%d\n",maxflow);
	
	return 0;
}