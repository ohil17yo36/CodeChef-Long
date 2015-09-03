#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define lli long long int
#define mod 1000000007
lli n=100000,q=100000,l,r,v,prev;
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	ofstream fout;
	fout.open("inp.txt");
	fout<<n<<" "<<q<<endl;
	for(lli i=0;i<n;i++)
		fout<<rand()%mod+1<<" ";
	fout<<endl;
	for(lli j=0;j<q;j++)
	{
		int chc=rand()%4+1;
		// if(chc==2)
		// 	chc++;
		// if(j!=0)
		// {
		// 	if(prev!=4)
		// 		chc=4;
		// }
		l=rand()%n;
		r=rand()%n;
		if(l>r)
			swap(l,r);
		if(chc==4)
			fout<<chc<<" "<<l<<" "<<r<<endl;
		else
		{
			v=rand()%mod+1;
			fout<<chc<<" "<<l<<" "<<r<<" "<<v<<" "<<endl;
		}
		prev=chc;
	}
	return 0;
}
/*

*/
/*
lli query(lli node,lli start,lli end)
{
	if(start>end || end<l || start>r)
		return 0;
	if(!lazy[node].event.empty())
	{

		siz=lazy[node].event.size();
		f=0;

		for( idx=siz-1;idx>=0;idx--)
			if(lazy[node].event[idx].first==3)
			{
				printf("Hello2 %lld %lld %lld %lld  size=%lld type=%lld value=%lld node=%lld\n",start,end,l,r,siz,lazy[node].event[idx].first,lazy[node].event[idx].second,node);
				f=1;
				break;
			}
			
		if(!f)
			idx=0,j=0;
		else
		{
			value=lazy[node].event[idx].second;
			tree[node]=(end-start+1)*(value);
			if(tree[node]>=mod)
				tree[node]=tree[node]%mod;
			j=idx+1;
		}

		for(;j<siz;j++)
		{

			itType=lazy[node].event[j].first;
			itValue=lazy[node].event[j].second;
			if(itType==1)
				tree[node]=(tree[node] + itValue*(end-start+1) );
			else if(itType==2)
				tree[node]=(tree[node] * itValue);
			if(tree[node]>=mod)
				tree[node]=tree[node]%mod;
		}
		if(start!=end)
		{
			lazy[2*node].event.insert(lazy[2*node].event.end(),lazy[node].event.begin() + idx ,lazy[node].event.end());
			lazy[2*node + 1].event.insert(lazy[2*node + 1].event.end(),lazy[node].event.begin() + idx,lazy[node].event.end());
		}
		lazy[node].event.clear();
	}
	if(start>=l && end<=r)
		return tree[node];
	return (query(2*node,start,(start+end)/2) + query(2*node + 1,((start+end)/2) + 1,end))%mod;
}
void update(lli node,lli start,lli end)
{
	if(start>end || end<l || start>r)
		return ;
	if(!lazy[node].event.empty())
	{
		siz=lazy[node].event.size();
		f=0;
		for( idx=siz-1;idx>=0;idx--)
			if(lazy[node].event[idx].first==3)
			{
				f=1;
				break;
			}

		if(!f)
			idx=0,j=0;
		else
		{
			value=lazy[node].event[idx].second;
			tree[node]=(end-start+1)*(value);
			if(tree[node]>=mod)
				tree[node]=tree[node]%mod;
			j=idx+1;
		}	
		for(;j<siz;j++)
		{
			itType=lazy[node].event[j].first;
			itValue=lazy[node].event[j].second;
			if(itType==1)
				tree[node]=(tree[node] + itValue*(end-start+1) );
			else if(itType==2)
				tree[node]=(tree[node] * itValue);
			if(tree[node]>=mod)
				tree[node]=tree[node]%mod;
		}
		if(start!=end)
		{
			lazy[2*node].event.insert(lazy[2*node].event.end(),lazy[node].event.begin() + idx ,lazy[node].event.end());
			lazy[2*node + 1].event.insert(lazy[2*node + 1].event.end(),lazy[node].event.begin() + idx,lazy[node].event.end());
		}
		lazy[node].event.clear();
	}
	if(start>end || end<l || start>r)
		return ;
	if(start>=l && end<=r)
	{
		if(type==1)
		{
			tree[node]=(tree[node] + v*(end-start+1));
			if(tree[node]>=mod)
				tree[node]=tree[node]%mod;
		}
		else if(type==2)
		{
			tree[node]=(tree[node] * v);
			if(tree[node]>=mod)
				tree[node]=tree[node]%mod;		
		}
		else if(type==3)
		{
			tree[node]=v*(end-start+1);
			if(tree[node]>=mod)
				tree[node]=tree[node]%mod;
		}
		if(start!=end)
		{
			lazy[2*node].event.push_back(make_pair(type,v));
			lazy[2*node + 1].event.push_back(make_pair(type,v));
			printf("Hello %lld %lld %lld %lld  size=%lld type=%lld value=%lld node=%lld\n",start,(start+end)/2,l,r,siz,type,v,2*node);
			printf("Hello %lld %lld %lld %lld  size=%lld type=%lld value=%lld node=%lld\n",(start+end)/2 + 1,end,l,r,siz,type,v,2*node + 1);
		}
		lazy[node].event.clear();
		return ;
	}
	update(2*node,start,(start+end)/2);
	update(2*node + 1,((start+end)/2) + 1,end);
	tree[node]=(tree[2*node]+tree[2*node + 1])%mod;
	return ;
}
*/

/*
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
		i=siz-1;
		for(;i>=0;i--)
		{
			if(lazyorder[node][i].first==3)
				break;
		}
		if(i==-1)
			j=0;
		else
			j=i;
		jval=j;
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
		}
		if(start!=end)
		{
			if(jval>0)
			{
				lazyorder[2*node].clear();
				lazyorder[2*node+1].clear();	
			}
			for(i=jval;i<siz;i++)
			{
				lazyorder[2*node].push_back(lazyorder[node][i]);
				lazyorder[2*node+1].push_back(lazyorder[node][i]);
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
				lazyorder[2*node].clear();
				lazyorder[2*node+1].clear();
			}
		}
		if(start!=end)
		{
			lazyorder[2*node].push_back(make_pair(type,v));
			lazyorder[2*node+1].push_back(make_pair(type,v));
		}
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
		i=siz-1;
		for(;i>=0;i--)
		{
			if(lazyorder[node][i].first==3)
				break;
		}
		if(i==-1)
			j=0;
		else
			j=i;
		jval=j;
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
		}
		if(start!=end)
		{
			if(jval>0)
			{
				lazyorder[2*node].clear();
				lazyorder[2*node+1].clear();	
			}
			for(i=jval;i<siz;i++)
			{
				lazyorder[2*node].push_back(lazyorder[node][i]);
				lazyorder[2*node+1].push_back(lazyorder[node][i]);
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
			fin>>v;/* v=read_int()*//*;
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
*/