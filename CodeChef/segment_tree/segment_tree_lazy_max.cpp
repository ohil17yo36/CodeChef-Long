#include <bits/stdc++.h>
using namespace std;
int arr[22];
int tree[90];
int lazy[90];
void build_tree(int node,int a,int b)
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
void update_tree(int node,int a,int b,int i,int j,int value)
{
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
	if(a>b||b<i||j<a)
		return ;
	if(a>=i && b<=j)
	{
		tree[node]+=value;
		if(a!=b)
		{
			lazy[2*node]+=value;
			lazy[2*node+1]+=value;
		}
		return ;
	}
	update_tree(2*node,a,a+((b-a)/2),i,j,value);
	update_tree(2*node+1,1+a+((b-a)/2),b,i,j,value);
	tree[node]=max(tree[2*node],tree[2*node+1]);
}
int query_tree(int node,int a,int b,int i,int j)
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
	int qleft=query_tree(2*node,a,a+((b-a)/2),i,j);
	int qright=query_tree(2*node+1,1+a+((b-a)/2),b,i,j);
	return max(qleft,qright);
}
int main(int argc, char const *argv[])
{
	int n=22;
	for (int i = 0; i < n; ++i)
	{
		arr[i]=1;
	}
	build_tree(1,0,n-1);
	update_tree(1,0,n-1,0,6,5);
	update_tree(1, 0, n-1, 7, 10, 12); 
	update_tree(1, 0, n-1, 10, n-1, 100);
	cout<<query_tree(1,0,n-1,0,n-1)<<endl;
	return 0;
}