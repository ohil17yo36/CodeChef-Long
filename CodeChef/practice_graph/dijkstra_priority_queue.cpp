#include <bits/stdc++.h>
using namespace std;
#define nodecnt 100000
#define INF (1<<20)
#define lli long long int
struct compare 
{
	bool operator() (const pair<lli,lli> &a, const pair<lli,lli> &b) 
	{	
		return a.second > b.second;
	}
};
priority_queue< pair<lli,lli>,vector< pair<lli,lli> >,compare> Q;
std::vector<pair<lli,lli> > graph[nodecnt];
lli dist[nodecnt];
lli nodes,edges,start,dest;

void dijkstra()
{
	for(lli i=1;i<=nodes;i++)
		dist[i]=INF;
	dist[start]=0;
	Q=priority_queue<pair<lli,lli>,vector<pair<lli,lli> >,compare>();
	Q.push(make_pair(start,0));
	while(!Q.empty())
	{
		lli u=Q.top().first;
		lli d=Q.top().second;
		Q.pop();
		if(d<=dist[u])
		{
			lli size=graph[u].size();
			for(lli i=0;i<size;i++)
			{
				lli v=graph[u][i].first;
				lli w=graph[u][i].second;
				if(dist[v]>dist[u]+w)
				{
					dist[v]=dist[u]+w;
					Q.push(make_pair(v,dist[v]));
				}
			}
		}
		if(u==dest)
			return;
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