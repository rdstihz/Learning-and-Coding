#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
#define N 100001 
struct Edge{
    int nxt,to;
}e[N<<1];
int n,tot,q,root,f[N][20],deep[N],head[N],col1[N],col2[N];
char ch[N];
void AddEdge(int u,int v)
{
    e[++tot].to=v;e[tot].nxt=head[u];head[u]=tot;
}
void dfs(int now)
{
    for(int i=1;i<=19;i++)
      f[now][i]=f[f[now][i-1]][i-1]; 
    for(int i=head[now];i;i=e[i].nxt)
      if(!deep[e[i].to])
      {
        deep[e[i].to]=deep[now]+1;
        f[e[i].to][0]=now;
        col1[e[i].to]+=col1[now];
        col2[e[i].to]+=col2[now];
		dfs(e[i].to);
      }
}
int LCA(int x,int y)
{
    if(deep[x]<deep[y]) std::swap(x,y);
    int dd = deep[x] - deep[y];
	for(int i=19;i>=0;i--)
		if((dd >> i) & 1)
			x = f[x][i];
    if(x==y) return x;
    for(int i=19;i>=0;i--)
      if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}
int main()
{
    scanf("%d%d",&n,&q);
    deep[1]=1;
    int x,y;
    for(int i=1;i<=n;i++)
    {
    	cin>>ch[i];
    	if(ch[i]=='H') col1[i]=1;
    	else col2[i]=1;
	}
    for(int i=1;i^n;i++)
    {
        scanf("%d%d",&x,&y);
        AddEdge(x,y),AddEdge(y,x);
    }
    dfs(1);
	char c; 
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&x,&y);
        cin>>c;
        root=LCA(x,y);
        if(c=='H')
        {
        	if(ch[root] == 'H' || ch[x]=='H'||ch[y]=='H'||col1[root]-col1[x]||col1[root]-col1[y]) putchar(49);
        	else putchar(48);
		}
		else
		{
			if(ch[root] == 'G' || ch[x]=='G'||ch[y]=='G'||col2[root]-col2[x]||col2[root]-col2[y]) putchar(49);
        	else putchar(48);
		}
    }
    return 0;
}
