#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define mod 1000000007
#define gtc getchar_unlocked()
#define lli long long int
lli n,q,a[100005],tree[400020],chc,x,y,l,r,v,siz,f,type,value,itType,itValue,ans;
lli lazymul[400020],lazyaddmul[400020],bit[400020];
void init(lli node,lli start,lli end)
{
	if(start>end)
		return;
	lazyaddmul[node]=0;
	lazymul[node]=1;
	if(start==end)
	{
		tree[node]=a[start];
		if(tree[node]>=mod)
			tree[node]=tree[node]%mod;
		return;
	}
	init(2*node,start,(start+end)/2);
	init(2*node + 1,((start+end)/2) + 1,end);
	tree[node]=tree[2*node]+tree[2*node + 1];
	if(tree[node]>=mod)
		tree[node]=(tree[node]%mod);	
	return; 
}
lli query(lli node,lli start,lli end)
{
	if(start>end || end<l || start>r)
		return 0;
	if(lazymul[node]!=1 || lazyaddmul[node]!=0)
	{
		tree[node]=((tree[node]*lazymul[node])%mod + (lazyaddmul[node])*(end-start+1)%mod)%mod;
		if(start!=end)
		{
			lazyaddmul[2*node]=lazyaddmul[2*node]*lazymul[node] + lazyaddmul[node];
			lazyaddmul[2*node+1]=lazyaddmul[2*node+1]*lazymul[node] + lazyaddmul[node];
			lazymul[2*node]*=lazymul[node];
			lazymul[2*node+1]*=lazymul[node];
			if(lazyaddmul[2*node]>=mod)
				lazyaddmul[2*node]%=mod;
			if(lazyaddmul[2*node+1]>=mod)
				lazyaddmul[2*node+1]%=mod;
			if(lazymul[2*node]>=mod)
				lazymul[2*node]%=mod;
			if(lazymul[2*node+1]>=mod)
				lazymul[2*node+1]%=mod;
		}
		lazymul[node]=1;
		lazyaddmul[node]=0;
	}
	if(start>=l && end<=r)
		return tree[node];
	return (query(2*node,start,(start+end)/2)+query(2*node+1,((start+end)/2)+1,end))%mod;
}
void update(lli node,lli start,lli end)
{
	if(lazymul[node]!=1 || lazyaddmul[node]!=0)
	{
		tree[node]=((tree[node]*lazymul[node])%mod + (lazyaddmul[node])*(end-start+1)%mod)%mod;
		if(start!=end)
		{
			lazyaddmul[2*node]=lazyaddmul[2*node]*lazymul[node] + lazyaddmul[node];
			lazyaddmul[2*node+1]=lazyaddmul[2*node+1]*lazymul[node] + lazyaddmul[node];
			lazymul[2*node]*=lazymul[node];
			lazymul[2*node+1]*=lazymul[node];
			if(lazyaddmul[2*node]>=mod)
				lazyaddmul[2*node]%=mod;
			if(lazyaddmul[2*node+1]>=mod)
				lazyaddmul[2*node+1]%=mod;
			if(lazymul[2*node]>=mod)
				lazymul[2*node]%=mod;
			if(lazymul[2*node+1]>=mod)
				lazymul[2*node+1]%=mod;
		}
		lazymul[node]=1;
		lazyaddmul[node]=0;
	}
	if(start>end || end<l || start>r)
		return ;
	if(start>=l && end<=r)
	{
		if(type==1)
		{
			tree[node]+=(end-start+1)*v;
			if(tree[node]>=mod)
				tree[node]%=mod;
			if(start!=end)
			{
				lazyaddmul[2*node]+=v;
				lazyaddmul[2*node+1]+=v;
				if(lazyaddmul[2*node]>=mod)
					lazyaddmul[2*node]%=mod;
				if(lazyaddmul[2*node+1]>=mod)
					lazyaddmul[2*node+1]%=mod;
			}
		}
		else if(type==2)
		{
			tree[node]*=v;
			if(tree[node]>=mod)
				tree[node]%=mod;
			if(start!=end)
			{
				lazyaddmul[2*node]*=v;
				lazyaddmul[2*node+1]*=v;
				lazymul[2*node]*=v;
				lazymul[2*node+1]*=v;
				if(lazyaddmul[2*node]>=mod)
					lazyaddmul[2*node]%=mod;
				if(lazyaddmul[2*node+1]>=mod)
					lazyaddmul[2*node+1]%=mod;
				if(lazymul[2*node]>=mod)
					lazymul[2*node]%=mod;
				if(lazymul[2*node+1]>=mod)
					lazymul[2*node+1]%=mod;
			}

		}
		return;
	}
	update(2*node,start,(start+end)/2);
	update(2*node+1,((start+end)/2) + 1,end);
	tree[node]=tree[2*node]+tree[2*node+1];
	if(tree[node]>=mod)
		tree[node]%=mod;
}
void updatesub(lli node,lli start,lli end)
{
	if(lazymul[node]!=1 || lazyaddmul[node]!=0)
	{
		tree[node]=((tree[node]*lazymul[node])%mod + (lazyaddmul[node])*(end-start+1)%mod)%mod;
		if(start!=end)
		{
			lazyaddmul[2*node]=lazyaddmul[2*node]*lazymul[node] + lazyaddmul[node];
			lazyaddmul[2*node+1]=lazyaddmul[2*node+1]*lazymul[node] + lazyaddmul[node];
			lazymul[2*node]*=lazymul[node];
			lazymul[2*node+1]*=lazymul[node];
			if(lazyaddmul[2*node]>=mod)
				lazyaddmul[2*node]%=mod;
			if(lazyaddmul[2*node+1]>=mod)
				lazyaddmul[2*node+1]%=mod;
			if(lazymul[2*node]>=mod)
				lazymul[2*node]%=mod;
			if(lazymul[2*node+1]>=mod)
				lazymul[2*node+1]%=mod;
		}
		lazymul[node]=1;
		lazyaddmul[node]=0;
	}
	if(start>end || end<l || start>r)
		return ;

	if(start>=l && end<=r)
	{
		tree[node]=v*(end-start+1);
		lazyaddmul[node]=0;
		lazymul[node]=1;
	}
	if(start==end)
		return;
	updatesub(2*node,start,(start+end)/2);
	updatesub(2*node + 1,((start+end)/2)+1,end);
	tree[node]=tree[2*node]+tree[2*node+1];
	if(tree[node]>=mod)
		tree[node]%=mod;
	return;
}
int main(int argc, char const *argv[])
{
	ifstream fin;
	ofstream fout;
	fin.open("inp.txt");
	fout.open("outtreetry2.txt");
	// n=read_int(),q=read_int();
	fin>>n>>q;
	for(lli i=0;i<n;i++)
		fin>>a[i];
	init(1,0,n-1);
	while(q--)
	{
		// chc=read_int(),x=read_int(),y=read_int();
		fin>>chc>>x>>y;
		// x--,y--;
		l=x,r=y;
		type=chc;
		if(chc!=4)
			 fin>>v;/* v=read_int()*/;
		
			if(chc==1) 
				update(1,0,n-1);
			else if(chc==2)
				update(1,0,n-1);
			else if(chc==3)
				updatesub(1,0,n-1);
			else		
			{
				ans=query(1,0,n-1)%mod;
				// if(ans>=0)
				// 	fastWrite(ans);
				// else
				// {
				// 	printf("-");
				// 	fastWrite(-1*ans);
				// }
				fout<<ans<<endl;							
			}
	}

	return 0;
}	