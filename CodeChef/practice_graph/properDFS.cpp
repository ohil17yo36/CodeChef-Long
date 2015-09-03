#include <bits/stdc++.h>
using namespace std;
#define nodecnt 100005
std::vector<int> graph[nodecnt];
int timeIn[nodecnt],timeOut[nodecnt],color[nodecnt];
int nodes,edges,dfsTimer=0;
void dfs(int u)
{
	timeIn[u]=dfsTimer++;
	color[u]=1;
	for (std::vector<int>::iterator i = graph[u].begin(); i != graph[u].end(); ++i)
	{
		if(color[*i]==0)
			dfs(*i);
	}
	color[u]=2;
	timeOut[u]=dfsTimer++;
}
int main(int argc, char const *argv[])
{
	int u,v;
	scanf("%d %d",&nodes,&edges);
	for(int i=1;i<=nodes;i++)
	{
		graph[i].clear();
		timeIn[i]=0;
		timeOut[i]=0;
		color[i]=0;
	}
	for(int i=0;i<edges;i++)
	{
		scanf("%d %d",&u,&v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i=1;i<=nodes;i++)
	{
		if(color[i]==0)
			dfs(i);
	}
	return 0;
}