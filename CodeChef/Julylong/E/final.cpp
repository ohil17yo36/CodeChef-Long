#include <vector>
#include <utility>
#include <fstream>
#define mod 1000000007
#define lli long long int
using namespace std;
lli tree[400020],a[100005],lastthirdtypeoccurence[400020],chc,x,y,l,r,v,n,q,ans,type,i,siz,jval,j,temp;
std::vector<pair<lli,lli> > lazyorder[400020];
void init(lli node,lli start,lli end)
{
	if(start>end)
		return;
	if(start==end)
	{
		tree[node]=a[start];
		return;
	}
	init(2*node,start,(start+end)/2);
	init(2*node+1,((start+end)/2)+1,end);
	tree[node]=tree[2*node]+tree[2*node+1];
	if(tree[node]>=mod)
		tree[node]%=mod;
}
void update(lli node,lli start,lli end)
{
	if(!lazyorder[node].empty())
	{
		siz=lazyorder[node].size();
		j=lastthirdtypeoccurence[node];
		jval=j;
		if(jval>0 && start!=end)
		{
			lastthirdtypeoccurence[2*node]=lazyorder[2*node].size();
			lastthirdtypeoccurence[2*node+1]=lazyorder[2*node+1].size();
		}
		for(;j<siz;j++)
		{
			if(lazyorder[node][j].first==1)
			{
				tree[node]+=(end-start+1)*(lazyorder[node][j].second);
				if(tree[node]>=mod)
					tree[node]%=mod;
			}
			else if(lazyorder[node][j].first==2)
			{
				tree[node]*=(lazyorder[node][j].second)%mod;
				if(tree[node]>=mod)
					tree[node]%=mod;
			}
			else
			{
				tree[node]=(end-start+1)*(lazyorder[node][j].second);
				if(tree[node]>=mod)
					tree[node]%=mod;
			}
			if(start!=end)
			{
				lazyorder[2*node].push_back(lazyorder[node][j]);
				lazyorder[2*node+1].push_back(lazyorder[node][j]);
			}	
		}
		lazyorder[node].clear();
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
		}
		else if(type==2)
		{
			tree[node]*=(v%mod);
			if(tree[node]>=mod)
				tree[node]%=mod;
		}
		else
		{
			tree[node]=(end-start+1)*v;
			if(tree[node]>=mod)
				tree[node]%=mod;
			if(start!=end)
			{
				lastthirdtypeoccurence[2*node]=lazyorder[2*node].size();
				lastthirdtypeoccurence[2*node+1]=lazyorder[2*node+1].size();
			}
		}
		if(start!=end)
		{
			lazyorder[2*node].push_back(make_pair(type,v));
			lazyorder[2*node+1].push_back(make_pair(type,v));
		}
		lastthirdtypeoccurence[node]=0;
		lazyorder[node].clear();		
		return;
	}
	update(2*node,start,(start+end)/2);
	update(2*node+1,((start+end)/2)+1,end);
	tree[node]=tree[2*node]+tree[2*node+1];
	if(tree[node]>=mod)
		tree[node]%=mod;
	return;
}
lli query(lli node,lli start,lli end)
{
	if(start>end || end<l || start>r)
		return 0;
	if(!lazyorder[node].empty())
	{
		siz=lazyorder[node].size();
		j=lastthirdtypeoccurence[node];
		jval=j;
		if(jval>0 && start!=end)
		{
			lastthirdtypeoccurence[2*node]=lazyorder[2*node].size();
			lastthirdtypeoccurence[2*node+1]=lazyorder[2*node+1].size();
		}

		for(;j<siz;j++)
		{
			if(lazyorder[node][j].first==1)
			{
				tree[node]+=(end-start+1)*(lazyorder[node][j].second);
				if(tree[node]>=mod)
					tree[node]%=mod;
			}
			else if(lazyorder[node][j].first==2)
			{
				tree[node]*=(lazyorder[node][j].second)%mod;
				if(tree[node]>=mod)
					tree[node]%=mod;
			}
			else
			{
				tree[node]=(end-start+1)*(lazyorder[node][j].second);
				if(tree[node]>=mod)
					tree[node]%=mod;
			}
			if(start!=end)
			{
				lazyorder[2*node].push_back(lazyorder[node][j]);
				lazyorder[2*node+1].push_back(lazyorder[node][j]);
			}
		}
		lazyorder[node].clear();
	}
	if(start>=l && end<=r)
		return tree[node];
	 temp=(query(2*node,start,(start+end)/2) + query(2*node+1,((start+end)/2)+1,end));
	 if(temp>=mod)
	 	temp%=mod;
	 return temp;
}
int main(int argc, char const *argv[])
{
	
	ifstream fin;
	ofstream fout;
	fin.open("inp.txt");
	fout.open("final.txt");
	// n=read_int(),q=read_int();
	fin>>n>>q;
	for( i=0;i<n;i++)
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
		{
			fin>>v;/* v=read_int()*/;
			update(1,0,n-1);
		}
		else		
		{
			ans=query(1,0,n-1)%mod;
			fout<<ans<<endl;							
		}
	}	
	return 0;
}