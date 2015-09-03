#include <bits/stdc++.h>
using namespace std;
struct qset
{
	int remPrefix[3];
	int sum;
}tree[400020];
int n,m,a[100005],chc,l,r,left,right,x,y;
void init(int node,int start,int right)
{
	if(start>end)
		return;
	if(start==end)
	{
		tree[node].sum=a[start];
		tree[node].remPrefix[sum%3]=1;
		return;
	}
	init(2*node,start,(start+end)/2);
	init(2*node+1,(start+end)/2 + 1,end);
	tree[node].sum=(tree[2*node].sum+tree[2*node+1].sum)%3;
	for (int i = 0; i < 3; ++i)
	{
		tree[node].remPrefix[i]=tree[2*node].remPrefix[i];
		tree[node].remPrefix[(i+tree[2*node].sum)%3]+=tree[2*node+1].remPrefix[i];
	}
	return;
}
int query(int node,int start,int end)
{
	if(start>end || start>r || end<l)
		return 0;
	if(start>=l && end<=r)
	{
		int ans=0;
		for(int i=0;i<3;i++)
		{
			if(i==0)
				ans+=((tree[node].remPrefix[i])*(tree[node].remPrefix[i] +1))/2;
			else
				ans+=((tree[node].remPrefix[i])*(tree[node].remPrefix[i] -1))/2;
		}
		return ans;
	}
	int ans=0;
	ans=query(2*node,start,(start+end)/2);
	ans+=query(2*node+1,(start+end)/2 + 1,end);
	for(int i=0;i<3;i++)
	{
		ans+=tree[node].remPrefix[i];
		ans+=tree[node].remPrefix[(i+tree[2*node].sum)%3]
	}
}
int main(int argc, char const *argv[])
{
	char ch;
	scanf("%d %d",&n,&m);
	getchar();
	for(int i=0;i<n;i++)
	{
		ch=getchar();
		a[i]=ch-'0';
	}
	init(1,0,n-1);
	while(m--)
	{
		scanf("%d",&chc);
		if(chc==1)
		{
			scanf("%d %d",&x,&y);
			x--;
			update(1,0,n-1);
		}
		else
		{
			scanf("%d %d",&l,&r);
			l--,r--;
			printf("%d\n",query(1,0,n-1));
		}
	}
	return 0;
}