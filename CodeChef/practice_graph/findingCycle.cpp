#include <bits/stdc++.h>
using namespace std;
#define nodecnt 100005
std::vector<int> graph[nodecnt];
int parent[nodecnt],color[nodecnt],cycleStart,cycleEnd,edges,nodes;
bool dfs(int u)
{
	color[u]=1;
	for(vector<int>::size_type i=0;i<graph[u].size();i++)
	{
		int v=graph[u][i];
		if(color[v]==0)
		{
			parent[v]=u;
			return dfs(v);
		}
		else if(color[v]==1 && v!=parent[u])
		{
			cycleStart=v;
			cycleEnd=u;
			return true;
		}
	}
	color[u]=2;
	return false;
}
int main(int argc, char const *argv[])
{
	int u,v;
	scanf("%d %d",&nodes,&edges);
	for(int i=1;i<=nodes;i++)
	{
		graph[i].clear();
		parent[i]=-1;
		color[i]=0;
	}
	for(int i=0;i<edges;i++)
	{
		scanf("%d %d",&u,&v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cycleStart=-1;
	for(int i=1;i<=nodes;i++)
	{
		if(dfs(i))
			break;
	}
	if(cycleStart==-1)
		printf("NoCycle\n");
	else
	{
		std::vector<int> Cycle;
		Cycle.push_back(cycleStart);
		for(int v=cycleEnd;v!=cycleStart;v=parent[v])
			Cycle.push_back(v);
		Cycle.push_back(cycleStart);
		reverse(Cycle.begin(),Cycle.end());
		for (std::vector<int>::iterator i = Cycle.begin(); i != Cycle.end(); ++i)
			printf("%d ",*i);
		printf("\n");
	}
	return 0;
}