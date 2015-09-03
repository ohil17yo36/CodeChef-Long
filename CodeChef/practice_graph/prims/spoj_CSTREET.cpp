#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define INF (1<<30)
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
lli nodes,edges,start,dest,ans=0,p;
void prims()
{
	ans=0;
	for(lli i=0;i<=nodes;i++)
		key[i]=INF,donewith[i]=false;
	set<pair<lli,lli> > Q;
	for(lli i=1;i<=nodes;i++)
		Q.insert(make_pair(key[i],i));
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
	lli u,v,w,t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld %lld",&p,&nodes,&edges);
		
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
		printf("%lld\n",ans*p);
	}
	return 0;
}	