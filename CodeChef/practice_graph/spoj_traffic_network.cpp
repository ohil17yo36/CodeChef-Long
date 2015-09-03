#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define nodecntmax 1000000
#define INF (1<<20)
inline lli scan( )
{
	lli n1 = 0;
	char c;
	for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
	for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
	n1 = (n1 * 10) + (c & 0x0f);
	return n1;
}
struct compare
{
	bool operator ()(const pair<lli,lli> &a,const pair<lli,lli> &b)
	{
		return a.second>b.second;
	}
};
priority_queue< pair<lli,lli>,vector<pair<lli,lli> >,compare > Q;
lli distfor[nodecntmax],donewithfor[nodecntmax],distback[nodecntmax],donewithback[nodecntmax];
vector<pair<lli,lli> > gfor[nodecntmax],gback[nodecntmax];
lli t,nodes,edges,q,start,dest,glbvar=0;
void dijkstra1()
{
	for(lli i=1;i<=nodes;i++)
		distfor[i]=INF,donewithfor[i]=false;
	distfor[start]=0;
	Q=priority_queue< pair<lli,lli>,vector<pair<lli,lli> >,compare >();
	Q.push(make_pair(start,0));
	while(!Q.empty())
	{
		lli u=Q.top().first;
		Q.pop();
		lli size=gfor[u].size();
		for(lli i=0;i<size;i++)
		{
			lli v=gfor[u][i].first;
			lli w=gfor[u][i].second;
			if(!donewithfor[v] && distfor[v]>distfor[u]+w)
			{
				// parent[v]=u;
				distfor[v]=distfor[u]+w;
				Q.push(make_pair(v,distfor[v]));				
			}
		}
		donewithfor[u]=true;
	}
}
void dijkstra2()
{
	for(lli i=1;i<=nodes;i++)
		distback[i]=INF,donewithback[i]=false;
	distback[dest]=0;
	Q=priority_queue< pair<lli,lli>,vector<pair<lli,lli> >,compare >();
	Q.push(make_pair(dest,0));
	while(!Q.empty())
	{
		lli u=Q.top().first;
		Q.pop();
		lli size=gback[u].size();
		for(lli i=0;i<size;i++)
		{
			lli v=gback[u][i].first;
			lli w=gback[u][i].second;
			if(!donewithback[v] && distback[v]>distback[u]+w)
			{
				// parent[v]=u;
				distback[v]=distback[u]+w;
				Q.push(make_pair(v,distback[v]));				
			}
		}
		donewithback[u]=true;
	}
}
int main(int argc, char const *argv[])
{
	lli u,v,w,minn=INF;
	t=scan();
	while(t--)
	{
		nodes=scan(),edges=scan(),q=scan(),start=scan(),dest=scan();
		for(lli i=1;i<=nodes;i++)
			gfor[i].clear(),gback[i].clear();
		for(lli i=1;i<=edges;i++)
		{
			u=scan(),v=scan(),w=scan();
			gfor[u].push_back(make_pair(v,w));
			gback[v].push_back(make_pair(u,w));
		}
		dijkstra1();
		dijkstra2();
		minn=min(distfor[dest],distback[start]);
		while(q--)
		{
			u=scan(),v=scan(),w=scan();
			minn=min(minn,min(distfor[u]+distback[v]+w,distfor[v]+distback[u]+w));
		}
		
		// minn=min(minn,dist[dest]);
		if(minn==INF)
			printf("-1\n");
		else
			printf("%lld\n",minn);
	}
	return 0;
}	