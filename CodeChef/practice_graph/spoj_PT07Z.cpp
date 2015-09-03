#include <bits/stdc++.h>
using namespace std;
inline int scan( )
{
	int n = 0;
	char c;
	for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
	for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
	n = (n * 10) + (c & 0x0f);
	return n;
}
std::vector<int> vec[100005];
int n,dist[100005];
int bfs_modified(int u,bool *visited)
{
	for(int i=1;i<=n;i++)
	{
		visited[i]=false;
		dist[i]=0;
	}
	int maximum=-1,max_index=u;
	
	list<int>queue;
	queue.push_back(u);
	dist[u]=0;
	visited[u]=true;
	while(queue.empty()==false)
	{
		int front=queue.front();
		queue.pop_front();
		for (std::vector<int>::iterator i = vec[front].begin(); i != vec[front].end(); ++i)
		{
			if(visited[*i]==false)
			{
				
				visited[*i]=true;
				dist[*i]=dist[front]+1;
				queue.push_back(*i);
				if(maximum<dist[*i])
				{
					maximum=dist[*i];
					max_index=*i;
				}
			}
		}
	}
	return max_index;
}
int main(int argc, char const *argv[])
{
	int u,v;
	n=scan();
	
	bool visited[n+1];
	for (int i = 1; i <= n; ++i)
	{
		vec[i].clear();		
		visited[i]=false;
	}
	for (int i = 1; i < n; ++i)
	{
		u=scan();
		v=scan();
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	int outer_node=bfs_modified(1,visited);
	printf("%d\n",dist[bfs_modified(outer_node,visited)]);
	return 0;
}