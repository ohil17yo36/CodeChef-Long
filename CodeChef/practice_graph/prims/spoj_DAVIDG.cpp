	#include <bits/stdc++.h>
	using namespace std;
	#define lli long long int
	#define lld long double
	#define nodecnt 100005
	#define INF (1<<20)
	#define mod 1000000007
	inline lli scan( )
	{
		register lli n1 = 0;
		char c;
		for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
		for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
		n1 = (n1 * 10) + (c & 0x0f);
		return n1;
	}
	lld key[nodecnt],x,y;
	std::vector<pair<lld,lld> > cord;
	bool donewith[nodecnt];
	lli nodes,edges,start,dest,p,ans;
	std::vector<pair<lli,lli> > graph[nodecnt] ;
	lld eucdist(lli i,lli j)
	{
		return ceil(p*sqrt(((cord[i].first-cord[j].first)*(cord[i].first-cord[j].first))+((cord[i].second-cord[j].second)*(cord[i].second-cord[j].second))));
	}
	void prims()
	{
		ans=0;
		set<pair<lld,lli> > Q;
		for(lli i=1;i<=nodes;i++)
			key[i]=INF,donewith[i]=false,Q.insert(make_pair(key[i],i));
			
		Q.erase(Q.find(make_pair(key[start],start)));
		key[start]=0;

		Q.insert(make_pair(key[start],start));
		while(!Q.empty())
		{
			pair<lld,lli> top=*(Q.begin());
			Q.erase(Q.begin());
			lli u=top.second;
			donewith[u]=true;
			if(u!=start)
			{
				ans+=top.first;
				if(ans>=mod)
					ans=ans%mod;
			}		
			lli size=graph[u].size();
			for(lli i=0;i<size;i++)
			{
				lli v=graph[u][i].first;
				lld w=graph[u][i].second;
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
		lli t;
		t=scan();
		for(lli T=1;T<=t;T++)
		{
			nodes=scan(),p=scan();
			for(lli i=1;i<=nodes;i++)
				graph[i].clear();
			cord.clear();
			cord.push_back(make_pair(INF,INF));
			for(lli i=1;i<=nodes;i++)
				x=scan(),y=scan(),cord.push_back(make_pair(x,y));
			sort(cord.begin()+1,cord.end());
			for(lli i=1;i<nodes;i++)
			{
				lld temp=eucdist(i+1,i);
				graph[i].push_back(make_pair(i+1,temp));
				graph[i+1].push_back(make_pair(i,temp));
				for(lli j=i+2;j<=nodes;j++)
				{
					lld temp=eucdist(i,j);
					if(temp<=eucdist(j,j-1)+eucdist(j-1,i))
					{	
						graph[i].push_back(make_pair(j,temp));
						graph[j].push_back(make_pair(i,temp));
					}
				}
			}
			start=1,ans=0;
			prims();
			printf("Scenario #%lld: %lld\n",T,ans);
		}
		return 0;
	}	