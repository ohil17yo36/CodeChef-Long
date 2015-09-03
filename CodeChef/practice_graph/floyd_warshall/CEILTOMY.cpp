#include <bits/stdc++.h>
#define INF (1<<10)
using namespace std;
int graph[15][15],spathcnt[15][15];
int main(int argc, char const *argv[])
{
	int t,n,m,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				graph[i][j]=INF,spathcnt[i][j]=0;
	
		for(int i=1;i<=n;i++)
			graph[i][i]=0,spathcnt[i][i]=1;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d %d",&a,&b,&c);
			graph[a][b]=c;
			graph[b][a]=c;
			spathcnt[a][b]=1;
			spathcnt[b][a]=1;
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i==k || j==k)
						continue;
					if(graph[i][j]>(graph[i][k]+graph[k][j]))
					{
						graph[i][j]=(graph[i][k]+graph[k][j]);
						spathcnt[i][j]=(spathcnt[i][k]*spathcnt[k][j]);
					}
					else if(graph[i][j]==(graph[i][k]+graph[k][j]))
					{
						spathcnt[i][j]+=(spathcnt[i][k]*spathcnt[k][j]);	
					}
				}
			}
		}
		printf("%d\n",spathcnt[1][n]);
	}
	return 0;
}	