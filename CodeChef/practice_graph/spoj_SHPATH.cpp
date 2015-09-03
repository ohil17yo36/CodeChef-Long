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
lli nodes,edges,start,dest;
char str[25];

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
		lli size=graph[u].size();
		for(lli i=0;i<size;i++)
		{
			lli v=graph[u][i].first;
			lli w=graph[u][i].second;
			if(!donewith[v] && dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				Q.push(make_pair(v,dist[v]));
			}
		}
		donewith[u]=true;
		if(u==dest)
			return;
	}
}
int main(int argc, char const *argv[])
{
	lli t,queries;
	scanf("%lld",&t);
	while(t--)
	{
		std::map<string,lli> mp;
		scanf("%lld",&nodes);
		for(lli i=0;i<=nodes;i++)
			graph[i].clear();
		for(lli i=1;i<=nodes;i++)
		{	
			scanf("%s",str);
			string str2(str);
			mp[str2]=i;
			scanf("%lld",&edges);
			lli v,w;
			for(lli j=1;j<=edges;j++)
			{
				scanf("%lld %lld",&v,&w);
				graph[i].push_back(make_pair(v,w));
				// graph[v].push_back(make_pair(u,w));
			}
		}
		scanf("%lld",&queries);
		while(queries--)
		{
			scanf("%s",str);
			string str3(str);
			start=mp[str3];
			scanf("%s",str);
			string str4(str);
			dest=mp[str4];
			dijkstra();
			printf("%lld\n",dist[dest]);			
		}
		mp.clear();
	}
	return 0;
}