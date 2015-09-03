#include <bits/stdc++.h>
#define lli long long int 
using namespace std;
lli n,m,L,R,arr[50005];
struct gss1
{
	lli left_contiguos_sum;
	lli right_contiguos_sum;
	lli total_sum;
	lli max_sum;
}tree[4 * 50005];
void build_tree(lli node,lli l,lli r)
{
	if(l==r)
	{
		tree[node].left_contiguos_sum=arr[l];
		tree[node].right_contiguos_sum=arr[l];
		tree[node].total_sum=arr[l];
		tree[node].max_sum=arr[l];
		return ;
	}
	build_tree(2*node,l,l+(r-l)/2);
	build_tree(2*node+1,l+(r-l)/2 +1,r);
	tree[node].total_sum=tree[2*node].total_sum+tree[2*node+1].total_sum;
	tree[node].max_sum=max(tree[2*node].max_sum,max(tree[2*node+1].max_sum,tree[2*node+1].left_contiguos_sum+tree[2*node].right_contiguos_sum));
	tree[node].right_contiguos_sum=max(tree[2*node+1].right_contiguos_sum,tree[2*node+1].total_sum+tree[2*node].right_contiguos_sum);	
	tree[node].left_contiguos_sum=max(tree[2*node].left_contiguos_sum,tree[2*node].total_sum+tree[2*node+1].left_contiguos_sum);
}
void update(lli node,lli start,lli end,lli l,lli value)
{
	lli mid=start+(end-start)/2;
	if(start==end && start==l)
	{
		tree[node].total_sum=tree[node].max_sum=tree[node].left_contiguos_sum=tree[node].right_contiguos_sum=value;
		return;
	}
	if(l<=mid)
		update(2*node,start,mid,l,value);
	else
		update(2*node+1,mid +1,end,l,value);
	tree[node].total_sum=tree[2*node].total_sum+tree[2*node+1].total_sum;
	tree[node].max_sum=max(tree[2*node].max_sum,max(tree[2*node+1].max_sum,tree[2*node+1].left_contiguos_sum+tree[2*node].right_contiguos_sum));
	tree[node].right_contiguos_sum=max(tree[2*node+1].right_contiguos_sum,tree[2*node+1].total_sum+tree[2*node].right_contiguos_sum);	
	tree[node].left_contiguos_sum=max(tree[2*node].left_contiguos_sum,tree[2*node].total_sum+tree[2*node+1].left_contiguos_sum);	
}
gss1 query(lli node, lli start,lli end,lli l,lli r)
{
	if(l<=start && r>=end)
		return tree[node];
	lli mid=start+(end-start)/2;
	if(r<=mid)
		return query(2*node,start,mid,l,r);
	if(l>mid)
		return query(2*node+1,mid+1,end,l,r);
	gss1 q1=query(2*node,start,mid,l,r);
	gss1 q2=query(2*node+1,mid+1,end,l,r);
	gss1 temp;
	temp.total_sum=q1.total_sum+q2.total_sum;
	temp.max_sum=max(q1.max_sum,max(q2.max_sum,q1.right_contiguos_sum + q2.left_contiguos_sum));
	temp.right_contiguos_sum=max(q2.right_contiguos_sum,q2.total_sum+q1.right_contiguos_sum);
	temp.left_contiguos_sum=max(q1.left_contiguos_sum,q1.total_sum+q2.left_contiguos_sum);
	return temp;
}
int main(int argc, char const *argv[])
{
	scanf("%lld",&n);
	for(lli i=1;i<=n;i++)
	{
		scanf("%lld",&arr[i]);
	}
	getchar();
	build_tree(1,1,n);
	scanf("%lld",&m);
	lli chc;
	while(m--)
	{
		scanf("%lld %lld %lld",&chc,&L,&R);
		if(chc)
			printf("%lld\n",query(1,1,n,L,R).max_sum);
		else
			update(1,1,n,L,R);
		getchar();
	}	
	return 0;
}