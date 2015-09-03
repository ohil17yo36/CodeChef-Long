//Wrong approach..Try out later
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
struct freq
{
	lli leftFrequency,rightFrequency,middleFrequency;
}tree[400020]; 
lli arr[100005],n,q,L,R;
void init(lli node,lli start,lli end)
{
	if(start==end)
	{
		tree[node].leftFrequency=tree[node].rightFrequency=tree[node].middleFrequency=1;
		return;
	}
	lli mid=(start+end)/2;
	init(2*node,start,mid);
	init(2*node+1,mid +1,end);
	if(arr[mid]==arr[mid + 1])
	{
		tree[node].leftFrequency=tree[2*node].leftFrequency+((arr[mid]==arr[start])?tree[2*node+1].leftFrequency:0);
		tree[node].rightFrequency=tree[2*node+1].rightFrequency+((arr[mid+ 1]==arr[end])?tree[2*node].rightFrequency:0);
		tree[node].middleFrequency=max(tree[2*node+1].leftFrequency+tree[2*node].rightFrequency,max(tree[2*node].middleFrequency,tree[2*node+1].middleFrequency));
	}
	else
	{
		tree[node].leftFrequency=tree[2*node].leftFrequency;
		tree[node].rightFrequency=tree[2*node+1].rightFrequency;
		tree[node].middleFrequency=max(tree[2*node].middleFrequency,tree[2*node+1].middleFrequency);
	}
}
lli query(lli node,lli start,lli end,lli l,lli r)
{
	if(start==l && end==r)
		return tree[node].middleFrequency;
	lli mid=(start+end)/2;
	if(r<=mid)
		return query(2*node,start,mid,l,r);
	if(l>mid)
		return query(2*node+1,mid+1,end,l,r);
	lli qLeft=query(2*node,start,mid,l,mid);
	lli qRight=query(2*node+1,mid +1,end,mid+1,r);
	
	if(arr[mid]==arr[mid+1])
		return max(min(tree[2*node].rightFrequency,mid-l+1)+min(tree[2*node+1].leftFrequency,r-mid),max(qLeft,qRight));
	else
		return max(qLeft,qRight);
}
int main(int argc, char const *argv[])
{
	while(1)
	{
		scanf("%lld %lld",&n,&q);
		if(n==0)
			return 0;
		for(lli i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		init(1,0,n-1);
		while(q--)
		{
			scanf("%lld %lld",&L,&R);
			printf("%lld\n",query(1,0,n-1,L-1,R-1));
		}
	}
	return 0;
}	