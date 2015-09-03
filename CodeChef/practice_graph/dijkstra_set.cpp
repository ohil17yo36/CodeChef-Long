#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define nodecnt 100005
#define INF (1<<20)
std::vector<pair<lli,lli> > graph[nodecnt];
lli dist[nodecnt];
lli nodes,edges,start,dest;
void dijkstra()
{
	set<pair<lli,lli> > Q;
	for(lli i=1;i<=nodes;i++)
		dist[i]=INF,Q.insert(make_pair(dist[i],i));
	Q.erase(Q.find(make_pair(dist[start],start)));
	dist[start]=0;
	Q.insert(make_pair(0,start));
	while(!Q.empty())
	{
		pair<lli,lli> top=*(Q.begin());
		Q.erase(Q.begin());
		lli u=top.second;
		lli size=graph[u].size();
		for(lli i=0;i<size;i++)
		{
			lli v=graph[u][i].first;
			lli w=graph[u][i].second;
			if(dist[v]>dist[u]+w)
			{
				Q.erase(Q.find(make_pair(dist[v],v)));
				dist[v]=dist[u]+w;
				Q.insert(make_pair(dist[v],v));
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	lli t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld ",&nodes,&edges);
		for(lli i=0;i<=nodes;i++)
			graph[i].clear();
		lli u,v,w;
		for(lli i=0;i<edges;i++)
		{
			scanf("%lld %lld %lld",&u,&v,&w);
			graph[u].push_back(make_pair(v,w));
			// graph[v].push_back(make_pair(u,w));
		}
		scanf("%lld %lld",&start,&dest);
		dijkstra();
		if(dist[dest]==INF)
			printf("NO\n");
		else
			printf("%lld\n",dist[dest]);
	}
	return 0;
}