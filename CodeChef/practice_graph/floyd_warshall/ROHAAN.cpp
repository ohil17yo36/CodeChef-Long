#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t,n,m,r,s,d;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		scanf("%d",&n);
		int graph[n+3][n+3];
		memset(graph,0,sizeof(graph));
		for (int i = 1; i <=n; ++i)
		{
			for(int j=1;j<=n;j++)
				scanf("%d",&graph[i][j]);
		}
		scanf("%d",&r);
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(graph[i][j]>=(graph[i][k]+graph[k][j]))
						graph[i][j]=(graph[i][k]+graph[k][j]);
				}
			}
		}
		int sum=0;
		while(r--)
		{
			scanf("%d %d",&s,&d);
			sum+=graph[s][d];
		}
		printf("Case #%d: %d\n",tt,sum );	
	}
	return 0;
}	