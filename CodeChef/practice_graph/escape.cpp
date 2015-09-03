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
lli dist[nodecnt],donewith[nodecnt],xcord[nodecnt],ycord[nodecnt];
lli nodes,edges,start;

void dijkstra()
{
	for(lli i=1;i<=nodes;i++)
		dist[i]=INF,donewith[i]=false;
	dist[start]=0;
	Q=priority_queue<pair<lli,lli>,vector<pair<lli,lli> >,compare>();
	Q.push(make_pair(start,0));
	while(!Q.empty())
	{
		lli u=Q.top().first;
		Q.pop();
		if(donewith[u])
			continue;
		lli size=graph[u].size();
		for(lli i=0;i<size;i++)
		{
			lli v=graph[u][i].first;
			lli w=graph[u][i].second;
			if(!donewith[v] && (dist[v]>dist[u]+w))
			{
				dist[v]=dist[u]+w;
				Q.push(make_pair(v,dist[v]));
			}
		}
		donewith[u]=true;
	}

}
lli distance_func(lli i,lli j)
{
	return (xcord[i]-xcord[j])*(xcord[i]-xcord[j]) + (ycord[i]-ycord[j])*(ycord[i]-ycord[j]);
}
int main(int argc, char const *argv[])
{
	scanf("%lld",&nodes);
	nodes+=2;
	xcord[1]=0,ycord[1]=0;
	for(lli i=2;i<=nodes;i++)
	{
		scanf("%lld %lld",&xcord[i],&ycord[i]);
	}
	for(lli i=1;i<=nodes;i++)
	{
		for(lli j=i+1;j<=nodes;j++)
		{
			graph[i].push_back(make_pair(j,distance_func(i,j)));
			graph[j].push_back(make_pair(i,distance_func(j,i)));
		}
	}
	start=1;
	dijkstra();
	printf("%lld\n",dist[nodes]);
	return 0;
}