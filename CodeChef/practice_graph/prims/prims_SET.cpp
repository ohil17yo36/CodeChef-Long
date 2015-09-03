#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define nodecnt 100005
#define INF (1<<28)
lli key[nodecnt];
bool donewith[nodecnt];
lli nodes,edges,start,dest,ans=0;
std::vector<pair<lli,lli> > graph[nodecnt];
void prims()
{
	set<pair<lli,lli> > Q;
	for(lli i=0;i<=nodes;i++)
		key[i]=INF,donewith[i]=false,Q.insert(make_pair(key[i],i));
		
	Q.erase(Q.find(make_pair(key[start],start)));
	key[start]=0;

	Q.insert(make_pair(0,start));
	while(!Q.empty())
	{
		pair<lli,lli> top=*(Q.begin());
		Q.erase(Q.begin());
		lli u=top.second;
		donewith[u]=true;
		if(u!=start)
			ans+=top.first;	
		lli size=graph[u].size();
		for(lli i=0;i<size;i++)
		{
			lli v=graph[u][i].first;
			lli w=graph[u][i].second;
			if(donewith[v]==false)
			{	
				if(key[v]>w)
				{
					Q.erase(Q.find(make_pair(key[v],v)));
					key[v]=w;
					Q.insert(make_pair(key[v],v));
				}
			}
		}
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