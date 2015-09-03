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
lli dist[nodecnt],donewith[nodecnt];
lli nodes,edges,start;

lli waitingTimeToGetvFromu(lli u,lli v,lli currNetDist)
{
	lli totalDist=((lli)abs(v-u))*10;
	lli temp=currNetDist%totalDist;
	if(u>v)
		return temp;	
	else
		return (totalDist-temp)%totalDist;
}
void dijkstra()
{
	for(lli i=1;i<=nodes;i++)
		donewith[i]=false;
	dist[start]=0;
	Q=priority_queue<pair<lli,lli>,vector<pair<lli,lli> >,compare>();
	Q.push(make_pair(start,0));
	while(!Q.empty())
	{
		lli u=Q.top().first;
		dist[u]=Q.top().second;
		Q.pop();
		if(u==nodes)
			return;
		if(donewith[u])
			continue;
		lli size=graph[u].size();
		for(lli i=0;i<size;i++)
		{
			lli v=graph[u][i].first;
			lli w2=graph[u][i].second;
			Q.push(make_pair(v,w2+dist[u]+waitingTimeToGetvFromu(u,v,dist[u])));
		}
		donewith[u]=true;
	}
}
int main(int argc, char const *argv[])
{
	lli t,dest;
	scanf("%lld %lld",&nodes,&edges);
	for(lli i=0;i<=nodes;i++)
		graph[i].clear();
	dest=nodes,start=1;
	lli u,v,w;
	for(lli i=0;i<edges;i++)
	{
		scanf("%lld %lld",&u,&v);
		w=5*(v-u);
		graph[u].push_back(make_pair(v,w));
		graph[v].push_back(make_pair(u,w));
	}
	dijkstra();
	printf("%lld\n",dist[dest]);
	return 0;
}