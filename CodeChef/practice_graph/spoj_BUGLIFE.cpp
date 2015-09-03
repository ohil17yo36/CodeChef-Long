#include <bits/stdc++.h>
#define lli long long int
using namespace std;

std::vector<lli> vec[2005];
lli visited[2005];

inline long long int scan( )
{
long long int n = 0;
char c;
for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
n = (n * 10) + (c & 0x0f);
return n;
}
bool dfs_modified(lli u)
{
	bool res=true;
	for (std::vector<lli>::iterator i = vec[u].begin(); i != vec[u].end(); ++i)
	{
		if(visited[u]==visited[*i])
			return false;
		if(visited[*i]==0)
		{
			if(visited[u]==1)
				visited[*i]=-1;
			else
				visited[*i]=1;
			res=res & dfs_modified(*i);
		}
	}
	return res;
}
int main(int argc, char const *argv[])
{
	lli t,num,inter,u,v;
	t=scan();
	for(lli T=1;T<=t;T++)
	{
		bool res=true;
		num=scan();
		inter=scan();
		for(lli i=1;i<=num;i++)
		{
			vec[i].clear();
			visited[i]=0;
		}
		for(lli i=1;i<=inter;i++)
		{
			u=scan();
			v=scan();
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		for(lli i=1;i<=num;i++)
		{
			if(visited[i]==0)
			{
				visited[i]=1;
				res=res & dfs_modified(i);
			}
		}
		printf("Scenario #%lld:\n",T);
		if(res)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
	}
	return 0;
}