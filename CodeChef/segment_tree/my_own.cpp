#include <bits/stdc++.h>
#define lli long long int
#define inf 0x7fffffff
using namespace std;
lli n,m,L,R,arr[50006],tree[300024];
void init(lli node,lli l,lli r)
{
	if(l>r)
		return;
	if(l==r)
	{
		tree[node]=arr[l];
		return;
	}
	init(2*node,l,l+(r-l)/2);
	init(2*node+1,l+(r-l)/2+1,r);
	tree[node]=max(tree[2*node],tree[2*node+1]);
}
lli query(lli node,lli start ,lli end,lli l,lli r)
{
	if(l>end || r<start || start>end)
		return -inf;
	if(l<=start && r>=end)
		return tree[node];
	lli q1=query(2*node,start,start + (end-start)/2,l,r);
	lli q2=query(2*node+1,start+(end-start)/2+1,end,l,r);
	return max(q1,q2);
}
void update(lli node,lli start,lli end,lli l,lli r,lli value)
{
	if(start>end || r<start || l>end)
		return ;
	if(start==end)
	{
		tree[node]+=value;
		return;
	}
	update(2*node,start,start+(end-start)/2,l,r,value);
	update(2*node+1,start+(end-start)/2 +1,end,l,r,value);
	tree[node]=max(tree[2*node],tree[2*node+1]);
	return;
}
int main(int argc, char const *argv[])
{
	scanf("%lld",&n);
	for(lli i=0;i<n;i++)
		scanf("%lld",&arr[i]);
	init(1,0,n-1);
	scanf("%lld",&m);
	getchar();
	while(m--)
	{
		scanf("%lld %lld",&L,&R);
		getchar();
		printf("%lld\n",query(1,0,n-1,L-1,R-1));
		update(1,0,n-1,1,2,3);
		printf("%lld\n",query(1,0,n-1,L-1,R-1));
	}
	return 0;
}