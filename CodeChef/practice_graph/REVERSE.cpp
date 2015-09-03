#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define nodecnt 1000005
#define INF (1<<20)
struct compare
{
	bool operator ()(const pair<lli,lli> &a,const pair<lli,lli> &b)
	{
		return a.second>b.second;
	}
};
lli dist[nodecnt],donewith[nodecnt],start,dest,nodes,edges;
priority_queue< pair<lli,lli>,vector< pair<lli,lli> >,compare > Q;
std::vector<pair<lli,lli> > graph[nodecnt];
void dijkstra()
{
	for(lli i=1;i<=nodes;i++)
		dist[i]=INF,donewith[i]=0;
	dist[start]=0;
	Q=priority_queue<pair<lli,lli>,vector<pair<lli,lli> >,compare>();
	Q.push(make_pair(start,dist[start]));
	while(!Q.empty())
	{
		lli u=Q.top().first;
		Q.pop();
		if(donewith[u])
			continue;
		for (lli i = 0; i < graph[u].size(); ++i)
		{
			lli v=graph[u][i].first;
			lli w=graph[u][i].second;
			if(dist[v]>dist[u]+w && !donewith[v])
			{
				dist[v]=dist[u]+w;
				Q.push(make_pair(v,w));
			}
		}
		donewith[u]=1;
		if(u==dest)
			return;
	}
}
int main(int argc, char const *argv[])
{
	scanf("%lld %lld",&nodes,&edges);
	start=1,dest=nodes;
	lli x,y;
	for(lli i=0;i<edges;i++)
	{
		scanf("%lld %lld",&x,&y);
		graph[x].push_back(make_pair(y,0));
		graph[y].push_back(make_pair(x,1));
	}
	dijkstra();
	if(dist[dest]==INF)
		printf("-1\n");
	else
		printf("%lld\n",dist[dest]);
	return 0;
}