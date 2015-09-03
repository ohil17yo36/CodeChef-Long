#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli arr[100006],tree[400016],lazy[400016];
inline lli scan( )
{
lli n = 0;
char c;
for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
n = (n * 10) + (c & 0x0f);
return n;
}
void build_tree(lli node,lli a,lli b)
{
	if(a>b)
	return;
	if(a==b)
	{
		tree[node]=arr[a];
		return ;
	}
	build_tree(2*node,a,a+((b-a)/2));
	build_tree(2*node+1,1+a+((b-a)/2),b);
	tree[node]=max(tree[2*node],tree[2*node+1]);
}
lli query_tree(lli node,lli a,lli b,lli i,lli j)
{
	if(a>b||b<i||j<a)
		return 0;
	if(lazy[node]!=0)
	{
		tree[node]+=lazy[node];
		if(a!=b)
		{
			lazy[2*node]+=lazy[node];	
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(a>=i && b<=j)
	{
		return tree[node];
	}
	lli qleft=query_tree(2*node,a,a+((b-a)/2),i,j);
	lli qright=query_tree(2*node+1,1+a+((b-a)/2),b,i,j);
	return max(qleft,qright);
}
int main(int argc, char const *argv[])
{
	lli n,m,x,y,ans=0,left,right;
	n=scan();
	for(lli i=0;i<n;i++)
		arr[i]=scan();
	build_tree(1,0,n-1);
	m=scan();
	x=scan();
	y=scan();
	left=min(x,y);
	right=max(x,y);
	while(m--)
	{
		ans+=query_tree(1,0,n-1,left,right);
		x=(x+7)%(n-1);
		y=(y+11)%(n);
		left=min(x,y);
		right=max(x,y);
	}
	cout<<ans<<endl;
	return 0;
}