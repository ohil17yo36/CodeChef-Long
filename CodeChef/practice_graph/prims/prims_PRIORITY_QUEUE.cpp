#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define inf (1<<20)
#define nodecnt 100005
struct compare 
{	
	bool operator() (const pair<lli,lli>& a,const pair<lli,lli>& b)
	{
		return a.second > b.second;
	}	
};
lli key[nodecnt],donewith[nodecnt];
std::vector<pair<lli,lli> > graph[nodecnt];
priority_queue< pair<lli,lli>,vector<pair<lli,lli> >,compare> Q;
lli nodes,edges,start,dest,ans=0,edgcnt=-1;
void prims()
{
	for(lli i=0;i<=nodes;i++)
		key[i]=inf,donewith[i]=false;
	key[start]=0;
	Q=priority_queue<pair<lli,lli>,vector<pair<lli,lli> >,compare>();
	Q.push(make_pair(start,0));
	while(!Q.empty())
	{
		lli u=Q.top().first;
		ans+=Q.top().second;
		Q.pop();
		edgcnt++;
		if(edgcnt==nodes-1)
			return;
		lli size=graph[u].size();
		for(lli i=0;i<size;i++)
		{
			lli v=graph[u][i].first;
			lli w=graph[u][i].second;
			if(!donewith[v] && key[v]>=w)
			{
				key[v]=w;
				Q.push(make_pair(v,key[v]));
			}
		}
		donewith[u]=true;
	}
}
int main(int argc, char const *argv[])
{
	lli u,v,w;
	scanf("%lld %lld",&nodes,&edges);
	for(lli i=0;i<=nodes;i++)
		graph[i].clear();
	for(lli i=0;i<edges;i++)
	{
		scanf("%lld %lld %lld",&u,&v,&w);
		graph[u].push_back(make_pair(v,w));
		graph[v].push_back(make_pair(u,w));
	}
	start=1;
	prims();
	printf("%lld\n",ans);
	return 0;
}	