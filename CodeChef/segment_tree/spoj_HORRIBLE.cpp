#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli tree[400012],lazy[400012],t,n,c,chc,p,q,v,l,r;
void build(lli node,lli start,lli end)
{
	if(start>end)
		return;
	if(start==end)
	{
		tree[node]=0;
		lazy[node]=0;
		return;
	}
	build(2*node,start,(start+end)/2);
	build(2*node + 1,((start+end)/2)+1,end);
	tree[node]=tree[2*node]+tree[2*node+1];
	lazy[node]=lazy[2*node]+lazy[2*node+1];
}
lli query(lli node,lli start,lli end)
{
	if(l>r || end<l || start>r)
		return 0;
	if(lazy[node]!=0)
	{
		tree[node]+=lazy[node]*(end-start+1);
		if(start!=end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>=l && end<=r)
		return tree[node];
	return query(2*node,start,(start+end)/2)+query(2*node+1,((start+end)/2)+1,end);
}
void update(lli node,lli start,lli end,lli value)
{
	
	if(lazy[node]!=0)
	{
		tree[node]+=lazy[node]*(end-start+1);
		if(start!=end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;	
	}
	if(l>r || end<l || start>r)
		return ;
	if(start>=l && end<=r)
	{
		tree[node]+=value*(end-start+1);
		if(start!=end)
		{
			lazy[2*node]+=value;
			lazy[2*node+1]+=value;
		}
		lazy[node]=0;
		return ;	
	}
	update(2*node,start,(start+end)/2,value);
	update(2*node+1,((start+end)/2) + 1,end,value);
	tree[node]=tree[2*node]+tree[2*node+1];
	return;
}
int main(int argc, char const *argv[])
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&c);
		build(1,0,n-1);

		while(c--)
		{
			scanf("%lld",&chc);
			if(chc)
			{
				scanf("%lld %lld",&p,&q);
				l=p-1,r=q-1;
				printf("%lld\n",query(1,0,n-1));
			}
			else
			{
				scanf("%lld %lld %lld",&p,&q,&v);
				l=p-1,r=q-1;
				update(1,0,n-1,v);
			}
		}
	}
	return 0;
}