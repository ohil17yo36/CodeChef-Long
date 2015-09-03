#include <bits/stdc++.h>
#define gtc getchar_unlocked()
#define mod 1000000007
#define lli long long int
using namespace std;
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
lli tree[400020],a[100005],chc,x,y,l,r,v,n,q,ans,type;
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
	register lli temp1,temp2,temp3,siz,i,j,jval;
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
		temp3=tree[node];
			
			if(jval>0 && start!=end)
			{
				lazyorder[2*node].clear();
				lazyorder[2*node+1].clear();	
			}
			for(;j<siz;j++)
			{
				temp1=lazyorder[node][j].first;
				temp2=lazyorder[node][j].second;
				if(temp1==1)
				{
					temp3+=(end-start+1)*(temp2);
					if(temp3>=mod)
						temp3%=mod;
				}
				else if(temp1==2)
				{
					temp3*=(temp2)%mod;
					if(temp3>=mod)
						temp3%=mod;
				}
				else
				{
					temp3=(end-start+1)*(temp2);
					if(temp3>=mod)
						temp3%=mod;
				}
				if(start!=end)
				{
					lazyorder[2*node].push_back(lazyorder[node][j]);
					lazyorder[2*node+1].push_back(lazyorder[node][j]);
				}
			}
		tree[node]=temp3;
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
	register lli temp1,temp2,temp3,siz,i,j,jval,temp;
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
		temp3=tree[node];
			
			if(jval>0 && start!=end)
			{
				lazyorder[2*node].clear();
				lazyorder[2*node+1].clear();	
			}
			for(;j<siz;j++)
			{
				temp1=lazyorder[node][j].first;
				temp2=lazyorder[node][j].second;
				if(temp1==1)
				{
					temp3+=(end-start+1)*(temp2);
					if(temp3>=mod)
						temp3%=mod;
				}
				else if(temp1==2)
				{
					temp3*=(temp2)%mod;
					if(temp3>=mod)
						temp3%=mod;
				}
				else
				{
					temp3=(end-start+1)*(temp2);
					if(temp3>=mod)
						temp3%=mod;
				}
				if(start!=end)
				{
					lazyorder[2*node].push_back(lazyorder[node][j]);
					lazyorder[2*node+1].push_back(lazyorder[node][j]);
				}
			}
		tree[node]=temp3;
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
	
	// ifstream fin;
	// ofstream fout;
	// fin.open("inp.txt");
	// fout.open("Ediff2.txt");
	n=read_int(),q=read_int();
	// fin>>n>>q;
	for(lli i=0;i<n;i++)
		a[i]=read_int();// fin>>a[i];
	init(1,0,n-1);
	while(q--)
	{
		chc=read_int(),x=read_int(),y=read_int();
		// fin>>chc>>x>>y;
		x--,y--;
		l=x,r=y;
		type=chc;
		if(chc!=4)
		{
			/*fin>>v;*/v=read_int();
			update(1,0,n-1);
		}
		else		
		{
			ans=query(1,0,n-1);
			if(ans>0)
				fastWrite(ans);
			else
			{
				printf("-");
				fastWrite(-1*ans);
			}
			// fout<<ans<<endl;							
		}
	}	
	return 0;
}