#include <bits/stdc++.h>
using namespace std;
int graph[15][15],visited[15];
int n,m;
long long int minn,ans;
void f(int vertex,int netsum)
{
	
	if(netsum>minn)
		return;
	if(vertex==n)
	{
		if(minn>netsum)
			minn=netsum,ans=1;
		else if(minn==netsum)
			ans++;
		return;
	}
	visited[vertex]=1;
	for(int i=1;i<=n;i++)
		if(!visited[i] && graph[vertex][i]>0)
			f(i,netsum+graph[vertex][i]);
	visited[vertex]=0;	
}

int main(int argc, char const *argv[])
{
	int t,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		memset(visited,0,sizeof(visited));
		memset(graph,0,sizeof(graph));
		minn=(1<<20),ans=0;
		while(m--)
		{
			scanf("%d %d %d",&a,&b,&c);
			graph[a][b]=c;
			graph[b][a]=c;
		}
		f(1,0);
		printf("%lld\n",ans);
	}
	return 0;
}