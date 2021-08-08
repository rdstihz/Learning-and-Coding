#include<bits/stdc++.h>
using namespace std;
int dis[2001][2001],f[2001][2001],n,m;
int u,v,w;
int main()
{
    memset(dis,0x3f,sizeof(dis));
    memset(f,0x3f,sizeof(f));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) f[i][i]=dis[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        f[u][v]=dis[u][v]=w;
    }
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        for(int k=1;k<=n;k++)
          if(f[i][k]+f[k][j]<f[i][j])
            {
                printf("k=%d,f[%d][%d]:%d->",k,i,j,f[i][j]);
                printf("%d\n",(f[i][j]=f[i][k]+f[k][j]));
            }
    for(int k=1;k<=n;k++)
      for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          if(dis[i][k]+dis[k][j]<dis[i][j])
            {
                printf("k=%d,f[%d][%d]:%d->",k,i,j,dis[i][j]);
                printf("%d\n",),(dis[i][j]=dis[i][k]+dis[k][j])
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          if(f[i][j]!=dis[i][j]) printf("f[%d][%d]=%d,dis[%d][%d]=%d\n",i,j,f[i][j],i,j,dis[i][j]);
}
