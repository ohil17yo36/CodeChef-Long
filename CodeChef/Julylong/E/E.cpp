#include <vector>
#include <utility>
#include <cstdio>
#include <fstream>
using namespace std;
#define lli long long int
#define left (node<<1)
#define gtc getchar_unlocked()
#define mod 1000000007

inline lli read_int()
{
	register lli noRead=0,isneg=0;
	register char ph=gtc;
	for(;ph<48 || ph>57;ph=gtc){if(ph=='-') isneg=1;}
	while(ph>47 && ph<58){ noRead = (noRead << 3) + (noRead << 1) + (ph - '0');ph=gtc;}
	if(isneg) noRead = -noRead;
	return noRead;
}
inline void fastWrite(lli aa)
{
	char snum[35];
	lli I=0;
	do
	{
	snum[I++]=aa%10+48;
	aa=aa/10;
	}while(aa!=0);
	I=I-1;
	while(I>=0)
	putchar_unlocked(snum[I--]);
	putchar_unlocked('\n');
}
lli a[100005],tree[400020],n,q,x,y,l,r,v,ans,lnode,mid;
int type,chc;
std::vector<pair<int,lli> > lazyorder[400020];
void init(lli node,lli start,lli end)
{
	if(start>end)
		return;
	if(start==end)
	{
		tree[node]=a[start];
		return;
	}
	register lli lnode=left,mid=(start+end)>>1;
	init(lnode,start,mid);
	init(lnode|1,mid+1,end);
	tree[node]=(tree[2*node]+tree[2*node+1]);
	if(tree[node]>=mod)
		tree[node]%=mod;
}
void update(lli node,lli start,lli end)
{
	register lli i,temp1,temp3,lnode=left,mid=((start+end)>>1);
	register int temp2;
	if(!lazyorder[node].empty())
	{
		temp1=tree[node];
		if(start!=end)
		{
			for(i=0;i<lazyorder[node].size();i++)
			{
				temp2=lazyorder[node][i].first;
				temp3=lazyorder[node][i].second;
				if(temp2==1)
					temp1+=((end-start+1)*(temp3));
			
				else if(temp2==2)
					temp1*=(temp3)%mod;
			
				else
					temp1=((end-start+1)*temp3);

				if(temp1>=mod)
					temp1%=mod;
				
				if(temp2==3)
				{
					lazyorder[2*node].clear();
					lazyorder[2*node+1].clear();
				}
				lazyorder[2*node].push_back(lazyorder[node][i]);
				lazyorder[2*node+1].push_back(lazyorder[node][i]);
			}
		}
		else
		{
			for(i=0;i<lazyorder[node].size();i++)
			{
				temp2=lazyorder[node][i].first;
				temp3=lazyorder[node][i].second;
				if(temp2==1)
					temp1+=((end-start+1)*(temp3));
			
				else if(temp2==2)
					temp1*=(temp3)%mod;
			
				else
					temp1=((end-start+1)*temp3);

				if(temp1>=mod)
					temp1%=mod;
			}
		}
		lazyorder[node].clear();
		tree[node]=temp1;
	}
	if(start>end || start>r || end<l)
		return;
	if(start>=l && end<=r)
	{
		if(type==1)
		{
			tree[node]+=((end-start+1)*v);
			if(tree[node]>=mod)
				tree[node]%=mod;
			if(start!=end)
			{
				lazyorder[2*node].push_back(make_pair(type,v));
				lazyorder[2*node+1].push_back(make_pair(type,v));
			}		
		}
		else if(type==2)
		{
			tree[node]*=(v);
			if(tree[node]>=mod)
				tree[node]%=mod;
			if(start!=end)
			{
				lazyorder[2*node].push_back(make_pair(type,v));
				lazyorder[2*node+1].push_back(make_pair(type,v));
			}
		}
		else
		{
			tree[node]=((end-start+1)*v);
			if(tree[node]>=mod)
				tree[node]%=mod;
			if(start!=end)
			{
				lazyorder[2*node].clear();
				lazyorder[2*node+1].clear();
				lazyorder[2*node].push_back(make_pair(type,v));
				lazyorder[2*node+1].push_back(make_pair(type,v));
			}
		}
		return;
	}
	
	update(lnode,start,mid);
	update(lnode|1,mid+1,end);
	tree[node]=(tree[2*node]+tree[2*node+1]);
	if(tree[node]>=mod)
		tree[node]%=mod;
	return;
}
lli query(lli node,lli start,lli end)
{
	if(start>end || start>r || end<l)
		return 0;
	register lli i,temp3,temp1,lnode=left,mid=(start+end)>>1;
	register int temp2;
	if(!lazyorder[node].empty())
	{
		temp1=tree[node];
		if(start!=end)
		{
			for(i=0;i<lazyorder[node].size();i++)
			{
				temp2=lazyorder[node][i].first;
				temp3=lazyorder[node][i].second;
				if(temp2==1)
					temp1+=((end-start+1)*(temp3));
			
				else if(temp2==2)
					temp1*=(temp3)%mod;
			
				else
					temp1=((end-start+1)*temp3);

				if(temp1>=mod)
					temp1%=mod;
				
				if(temp2==3)
				{
					lazyorder[2*node].clear();
					lazyorder[2*node+1].clear();
				}
				lazyorder[2*node].push_back(lazyorder[node][i]);
				lazyorder[2*node+1].push_back(lazyorder[node][i]);
			}
		}
		else
		{
			for(i=0;i<lazyorder[node].size();i++)
			{
				temp2=lazyorder[node][i].first;
				temp3=lazyorder[node][i].second;
				if(temp2==1)
					temp1+=((end-start+1)*(temp3));
			
				else if(temp2==2)
					temp1*=(temp3)%mod;
			
				else
					temp1=((end-start+1)*temp3);

				if(temp1>=mod)
					temp1%=mod;
			}
		}
		lazyorder[node].clear();
		tree[node]=temp1;
	}
	if(start>=l && end<=r)
		return tree[node];
	return (query(lnode,start,mid) + query(lnode|1,mid + 1,end))%mod;
}
int main(int argc, char const *argv[])
{
	
	// ifstream fin;
	// ofstream fout;
	// fin.open("inp.txt");
	// fout.open("E.txt");
	n=read_int(),q=read_int();
	// fin>>n>>q;
	for(lli i=0;i<n;i++)
		a[i]=read_int(); //fin>>a[i];
	init(1,0,n-1);
	while(q--)
	{
		chc=read_int();
		// fin>>chc>>x>>y;
		x--,y--;
		l=x,r=y;
		type=chc;
		if(chc!=4)
		{
			x=read_int(),y=read_int();
			/*fin>>v;*/v=read_int();
			l=x-1,r=y-1;
			update(1,0,n-1);
		}
		else		
		{
			x=read_int(),y=read_int();
			l=x-1,r=y-1;
			ans=query(1,0,n-1);
			fastWrite(ans);
			// fout<<ans<<endl;							
		}
	}	
	return 0;
}