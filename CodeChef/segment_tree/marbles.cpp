#include <bits/stdc++.h>
#define lld long long int 
using namespace std;
 arr[1000002];
lld tree[4000008];
char ch;
void buildtree(lld node,lld a,lld b)
{
	
	if(a>b)
	return;
	if(a==b)
	{
		tree[node]=arr[a];
		return ;
	}
	buildtree(2*node,a,a+((b-a)/2));
	buildtree(2*node+1,a+((b-a)/2)+1,b);
	tree[node]=tree[2*node]+tree[2*node+1];	
}
void update(lld node,lld a,lld b,lld i,lld j,lld value)
{
	if(a>b||b<i||a>j)
	return ;
	if(a==i && b==i)
	{
		tree[node]+=value;
		return;
	}
	update(2*node,a,a+((b-a)/2),i,j,value);
	update(2*node+1,a+((b-a)/2)+1,b,i,j,value);
	tree[node]=tree[2*node]+tree[2*node+1];	
}
lld query(lld node,lld a,lld b,lld i,lld j)
{
	if(a>b || a>j||b<i)
	return 0;
	if(a>=i && b<=j)
	{
		return tree[node];
	}
	lld qleft=query(2*node,a,a+((b-a)/2),i,j);
	lld qright=query(2*node+1,a+((b-a)/2)+1,b,i,j);
	return qleft+qright;	
}
int main(int argc, char const *argv[])
{
	lld n,q,i,j;
	cin>>n>>q;
	for(lld i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	buildtree(1,0,n-1);
	while(q--)
	{
		scanf(" %c %lld %lld",&ch,&i,&j);
		if(ch=='S')
		{
			cout<<query(1,0,n-1,i,j)<<endl;
		}
		else if(ch=='G')
		{
			update(1,0,n-1,i,i,j);
		}
		else
		{
			update(1,0,n-1,i,i,-1*j);
		}
		getchar();
	}
	return 0;
}