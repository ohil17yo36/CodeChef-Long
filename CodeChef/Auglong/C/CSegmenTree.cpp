#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli t,n,h,l,r,L,R,lazy[4000012],tree[4000012],rowTotal[1000006],ans;
void init(lli node,lli start,lli end)
{
	if(start>end)
		return ;
	if(start==end)
	{
		tree[node]=0;
		lazy[node]=0;
		return ;
	}
	init(2*node,start,(start+end)/2);
	init(2*node+1,(start+end)/2 +1,end);
	tree[node]=0;
	lazy[node]=0;
}
void update(lli node,lli start,lli end)
{
	if(start>end)
		return ;
	if(lazy[node]!=0)
	{
		tree[node]+=(end-start+1)*lazy[node];
		if(start!=end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>end || start>r || end<l)
		return ;
	if(start>=l && end<=r)
	{
		tree[node]+=(end-start+1);
		if(start!=end)
		{
			lazy[2*node]+=1;
			lazy[2*node+1]+=1;
		}
		lazy[node]=0;
		return ;
	}
	update(2*node,start,(start+end)/2);
	update(2*node+1,(start+end)/2 + 1,end);
	tree[node]=tree[2*node]+tree[2*node+1];
	return ;
}
lli query(lli node,lli start,lli end)
{
	if(start>end || start>r || end<l)
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
	return query(2*node,start,(start+end)/2) + query(2*node+1,(start+end)/2 + 1,end);
}
int main(int argc, char const *argv[])
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&h);
		init(1,0,n-1);
		for(lli i=0;i<n;i++)
		{
			scanf("%lld %lld",&L,&R);
			if(L>0)
				l=0,r=L-1,update(1,0,n-1);
			if(R<n-1)
				l=R+1,r=n-1,update(1,0,n-1);
		}
		for(lli i=0;i<n;i++)
			l=r=i,rowTotal[i]=query(1,0,n-1);
		ans=(1<<30);
		for(lli i=1;i<n;i++)
			rowTotal[i]+=rowTotal[i-1];
		for(lli i=0;i+h-1<n;i++)
		{
			if(i==0)
				ans=min(ans,rowTotal[i+h-1]);
			else
				ans=min(ans,rowTotal[i+h-1]-rowTotal[i-1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}	