#include <bits/stdc++.h>
#define lli long long int
using namespace std;
inline lli scan( )
{
	lli n1 = 0;
	char ch;
	for( ch = getchar_unlocked(); ch==' ' || ch=='\n' || ch == '\t'; ch = getchar_unlocked());
	for( ; ch > 0x2f && ch < 0x3a; ch = getchar_unlocked())
	n1 = (n1 * 10) + (ch & 0x0f);
	return n1;
}
lli t,n,m1,m2;
struct edge
{
	lli src,dest,cost;
}temp;
std::vector<struct edge> chef;
std::vector<struct edge> company;
struct subset
{
	lli parent;
	lli rank;
}subsets[5005];
lli find(lli i)
{
	if(subsets[i].parent!=i)
		subsets[i].parent=find(subsets[i].parent);
	return subsets[i].parent;
}
void Union(lli x,lli y)
{
	lli x_head=find(subsets[x].parent);
	lli y_head=find(subsets[y].parent);
	if(subsets[x_head].rank>subsets[y_head].rank)
		subsets[y_head].parent=x_head;
	else if(subsets[x_head].rank<subsets[y_head].rank)
		subsets[x_head].parent=y_head;
	else
	{
		subsets[y_head].parent=x_head;
		subsets[x_head].rank++;
	}
}
bool cmp_func(const edge a,const edge b)
{
	return a.cost < b.cost;
}
void kruskals()
{

	sort(company.begin(),company.end(),cmp_func);
	sort(chef.begin(),chef.end(),cmp_func);
	lli chef_cost=0,company_cost=0,edge_cnt=0;
	for(lli i=0;i<n;i++)
	{
		subsets[i].parent=i;
		subsets[i].rank=0;
	}
	for(lli i=m2-1;i>=0 ;i--)
	{
		if(find(chef[i].src)!=find(chef[i].dest))
		{
			chef_cost+=chef[i].cost;
			Union(chef[i].src,chef[i].dest);
			edge_cnt++;
		}
	}
	for(lli i=0;i<m1;i++)
	{
		if(find(company[i].src)!=find(company[i].dest))
		{
			company_cost+=company[i].cost;
			Union(company[i].src,company[i].dest);
			edge_cnt++;
		}
	}
	if(edge_cnt!=n-1)
		printf("Impossible\n");
	else
		printf("%lld %lld\n",chef_cost,chef_cost+company_cost);
}
int main(int argc, char const *argv[])
{
	t=scan();
	while(t--)
	{
		company.clear();
		chef.clear();
		n=scan();
		m1=scan();
		m2=scan();
		for(lli i=0;i<m1;i++)
		{
			temp.src=scan();
			temp.dest=scan();
			temp.cost=scan();
			company.push_back(temp);
		}
		for(lli i=0;i<m2;i++)
		{
			temp.src=scan();
			temp.dest=scan();
			temp.cost=scan();
			chef.push_back(temp);
		}
		kruskals();	
	}
	return 0;
}