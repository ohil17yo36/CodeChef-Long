#include <bits/stdc++.h>
#define lli long long int
using namespace std;
inline lli scan( )
{
lli n = 0;
char c;
for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
n = (n * 10) + (c & 0x0f);
return n;
}
class graph
{
	lli V;
	list<lli>*a;
public:
	graph(lli V);
	void addEdge(lli u,lli v);
	lli bfsutil(lli s);
};
graph::graph(lli V)
{
	this->V=V;
	//this->s=s;
	a=new list<lli>[V];
}
void graph::addEdge(lli u,lli v)
{
	a[u].push_back(v);
	a[v].push_back(u);
}
lli graph::bfsutil(lli s)
{
	lli ans[V];
	bool visited[V];
	for(lli i=1;i<V;i++)
		visited[i]=false;
	visited[s]=true;
	list<lli>queue;
	queue.push_back(s);
	while(!queue.empty())
	{
		lli vertex=queue.front();
		//cout<<vertex<<"";
		queue.pop_front();
		for(list<lli>::iterator i=a[vertex].begin();i!=a[vertex].end();i++)
		{
			if(visited[*i]==false)
			{
				visited[*i]=true;
				queue.push_back(*i);
			}
		}
	}
	lli num=0;
	for(lli i=1;i<V;i++)
	{
		lli counti=0;
		if(visited[i]==false)
		{
			visited[i]=true;
			
			queue.push_back(i);
			
			while(!queue.empty())
			{
				lli vertex=queue.front();
				counti++;
				queue.pop_front();
				for(list<lli>::iterator itr=a[vertex].begin();itr!=a[vertex].end();itr++)
				{
					if(visited[*itr]==false)
					{
						visited[*itr]=true;
						queue.push_back(*itr);
					}
				}
			}
			//maximum=max(counti,maximum);
		}
		ans[num++]=counti;
	}
	lli maximum=ans[0];
	for (lli i = 1; i < num; ++i)
	{
		maximum=max(maximum,ans[i]);
	}
	return maximum;
}
int main(int argc, char const *argv[])
{	
	lli t;
	t=scan();
	while(t--)
	{
		lli n,s,f,a,b;
		n=scan(),s=scan(),f=scan();
		if(f==0)
		{
			cout<<n-1<<endl;
			continue;
		}
		graph G(n+1);
		while(f--)
		{
			a=scan(),b=scan();
			G.addEdge(a,b);
		}
		cout<<G.bfsutil(s)<<endl;
	}
	return 0;
}