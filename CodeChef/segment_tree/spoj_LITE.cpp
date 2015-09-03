#include <bits/stdc++.h>
using namespace std;
#define lli long long int
struct Lite
{
	lli on,off;
}tree[2000020];
lli arr[100005],lazy[2000020],n,m,chc,L,R;

void init(lli node,lli start,lli end)
{
	if(start>end)
		return ;
	if(start==end)
	{
		tree[node].on=0;
		tree[node].off=1;
		return;
	}
	init(2*node,start,(start+end)/2);
	init(2*node+1,(start+end)/2 + 1,end);
	tree[node].on=tree[2*node].on + tree[2*node+1].on;
	tree[node].off=tree[2*node].off + tree[2*node+1].off;
	return ;
}
lli query(lli node,lli start,lli end,lli l,lli r)
{
	if(start>end || start>r || end<l)
		return 0;
	if(lazy[node]!=0)
	{
		swap(tree[node].on,tree[node].off);
		if(start!=end)
		{	
			lazy[2*node]^=1;
			lazy[2*node+1]^=1;
		}
		lazy[node]=0;
	}
	
	if(start>=l && end<=r)
		return tree[node].on;

	lli q1=query(2*node,start,(start+end)/2,l,r);
	lli q2=query(2*node+1,(start+end)/2 + 1,end,l,r);
	return q1+q2;
}
void update(lli node,lli start,lli end,lli l,lli r)
{
	// if(start>end)
	// 	return;
	if(lazy[node]!=0)
	{
		swap(tree[node].on,tree[node].off);
		if(start!=end)
		{
			lazy[2*node]^=1;
			lazy[2*node+1]^=1;
		}
		lazy[node]=0;	
	}
	if(start>end || start>r || end<l)
		return ;
	if(start>=l && end<=r)
	{
		swap(tree[node].on,tree[node].off);
		if(start!=end)
		{
			lazy[2*node]^=1;
			lazy[2*node + 1]^=1;
		}
		return;	
	}
	update(2*node,start,(start+end)/2,l,r);
	update(2*node+1,(start+end)/2 +1,end,l,r);
	tree[node].on=tree[2*node].on + tree[2*node + 1].on;
	tree[node].off=tree[2*node].off + tree[2*node + 1].off;
}
int main(int argc, char const *argv[])
{
	scanf("%lld %lld",&n,&m);
	init(1,0,n-1);
	while(m--)
	{
		scanf("%lld %lld %lld",&chc,&L,&R);
		if(chc)
			printf("%lld\n",query(1,0,n-1,L-1,R-1));
		else
			update(1,0,n-1,L-1,R-1);
	}
	return 0;
}