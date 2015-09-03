#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli arr[50006],tree[300024],n,m,L,R;
void init(lli node,lli start,lli end)
{
	if(start>end)
		return;
	if(start==end)
	{
		tree[node]=arr[start];
		return;
	}
	init((node<<1),start,start+(end-start)/2);
	init(((node<<1)) + 1,(start+((end-start)/2)) + 1, end);
	tree[node]=max(tree[(node<<1)],tree[(node<<1) + 1]);
	return;
}
lli query(lli node,lli start,lli end,lli l,lli r)
{
	if(start>end || start>r || end<l)
		return -1;
	if(start>=l && end<=r)
		return tree[node];
	lli q1=query(((node<<1)),start,start+((end-start)/2),l,r);
	lli q2=query(((node<<1))+1,(start+((end-start)/2)) + 1,end,l,r);
	lli ans=max(q1,q2);
	return ans;
}
int main(int argc, char const *argv[])
{
	scanf("%lld %lld",&n,&m);
	for(lli i=0;i<n;i++)
		scanf("%lld",&arr[i]);
	init(1,0,n-1);
	lli cnt=0;
	while(m--)
	{
		scanf("%lld %lld",&L,&R);
		if(arr[L-1]>=query(1,0,n-1,L-1,R-2))
			cnt++;
	}
	printf("%lld\n",cnt);
	return 0;
}