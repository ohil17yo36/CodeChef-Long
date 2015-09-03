#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define inf (1<<20)
lli n,k,m,q,graph[205][205],flag[205][205],u,v,w,ans,cnt;
int main(int argc, char const *argv[])
{
	for(lli i=0;i<=204;i++)
	{
		graph[i][i]=0;
		for(lli j=0;j<=204;j++)
		{
			graph[i][j]=inf;
		}
	}
	scanf("%lld %lld %lld %lld",&n,&m,&k,&q);
	for (int i = 0; i <m; ++i)
	{
		scanf("%lld %lld %lld",&u,&v,&w);
		graph[u][v]=w;
	}
	for(lli K=1;K<=n;K++)
	{
		for(lli i=1;i<=n;i++)
		{
			for(lli j=1;j<=n;j++)
			{
				graph[i][j]=min(graph[i][j],graph[i][K]+graph[K][j]);
			}
		}
	}

	while(q--)
	{
		
		scanf("%lld %lld",&u,&v);
		lli minn=graph[u][v];
		for(int i=1;i<=k;i++)
		{
			minn=min(minn,graph[u][i]+graph[i][v]);
		}
		if(minn<=graph[u][v])
			ans+=minn,cnt++;
	}
	printf("%lld\n%lld\n",cnt,ans);
	return 0;
}