// Trying to correct multiplication and addition
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define mod 1000000007
#define gtc getchar_unlocked()
#define lli long long int
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
lli n,q,a[100005],tree[400020],chc,x,y,l,r,v,siz,f,type,value,itType,itValue,ans;
lli lazymul[400020],lazyaddmul[400020],lazysub[400020];
void init(lli node,lli start,lli end)
{
	if(start>end)
		return;
	lazysub[node]=0;
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
	// printf("Hello3 start=%lld end=%lld l=%lld r=%lld lazysub[node]=%lld tree[node]=%lld\n",start,end,l,r,lazysub[node],tree[node]);
	if(lazymul[node]!=1 || lazyaddmul[node]!=0 || lazysub[node]!=0)
	{
		// printf("Hello start=%lld end=%lld l=%lld r=%lld lazysub[node]=%lld tree[node]=%lld\n",start,end,l,r,lazysub[node],tree[node]);
		if(lazysub[node]!=0)
		{
			// printf("Hello start=%lld end=%lld l=%lld r=%lld lazysub[node]=%lld tree[node]=%lld\n",start,end,l,r,lazysub[node],tree[node]);
			tree[node]=((end-start+1)*(lazysub[node]))%mod;
			// printf("Hello start=%lld end=%lld l=%lld r=%lld lazysub[node]=%lld tree[node]=%lld\n",start,end,l,r,lazysub[node],tree[node]);
			lazyaddmul[node]=0;
			lazymul[node]=1;
			if(start!=end)
			{
				lazysub[2*node]=lazysub[node];
				lazysub[2*node+1]=lazysub[node];
				if(lazysub[2*node]>=mod)
					lazysub[2*node]%=mod;
				if(lazysub[2*node+1]>=mod)
					lazysub[2*node+1]%=mod;
			}
			lazysub[node]=0;
		}
		else
		{
			tree[node]=((tree[node]*lazymul[node])%mod + (lazyaddmul[node])*(end-start+1)%mod)%mod;
			if(start!=end)
			{
				if(lazysub[2*node]!=0)
				{
					tree[2*node]=((((start+end)/2)-start+1)*lazysub[2*node]);
					if(tree[2*node]>=mod)
						tree[2*node]%=mod;
					lazyaddmul[2*node]=0;
					lazymul[2*node]=1;
					if(start!=((start+end)/2))
					{
						lazysub[4*node]=lazysub[2*node];
						lazysub[4*node+1]=lazysub[2*node];
						if(lazysub[4*node]>=mod)
							lazysub[4*node]%=mod;
						if(lazysub[4*node+1]>=mod)
							lazysub[4*node+1]%=mod;
					}
					lazysub[2*node]=0;
				}
				if(lazysub[2*node+1]!=0)
				{
					tree[2*node+1]=(end-((start+end)/2))*lazysub[2*node+1];
					if(tree[2*node+1]>=mod)
						tree[2*node+1]%=mod;
					lazyaddmul[2*node+1]=0;
					lazymul[2*node+1]=1;
					if((((start+end)/2)+1)!=end)
					{
						lazysub[4*node+2]=lazysub[2*node+1];
						lazysub[4*node+3]=lazysub[2*node+1];
						if(lazysub[4*node+2]>=mod)
							lazysub[4*node+2]%=mod;
						if(lazysub[4*node+3]>=mod)
							lazysub[4*node+3]%=mod;
					}
					lazysub[2*node+1]=0;
				}
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
	}
	if(start>=l && end<=r)
		return tree[node];
	return (query(2*node,start,(start+end)/2)+query(2*node+1,((start+end)/2)+1,end))%mod;
}
void update(lli node,lli start,lli end)
{

	if(lazymul[node]!=1 || lazyaddmul[node]!=0 || lazysub[node]!=0)
	{
		if(lazysub[node]!=0)
		{
			tree[node]=((end-start+1)*(lazysub[node]))%mod;
			lazyaddmul[node]=0;
			lazymul[node]=1;
			if(start!=end)
			{
				lazysub[2*node]=lazysub[node];
				lazysub[2*node+1]=lazysub[node];
				if(lazysub[2*node]>=mod)
					lazysub[2*node]%=mod;
				if(lazysub[2*node+1]>=mod)
					lazysub[2*node+1]%=mod;
			}
			lazysub[node]=0;
		}
		else
		{	
			tree[node]=((tree[node]*lazymul[node])%mod + (lazyaddmul[node])*(end-start+1)%mod)%mod;
			if(start!=end)
			{
				if(lazysub[2*node]!=0)
				{
					tree[2*node]=((((start+end)/2)-start+1)*lazysub[2*node]);
					if(tree[2*node]>=mod)
						tree[2*node]%=mod;
					lazyaddmul[2*node]=0;
					lazymul[2*node]=1;
					if(start!=((start+end)/2))
					{
						lazysub[4*node]=lazysub[2*node];
						lazysub[4*node+1]=lazysub[2*node];
						if(lazysub[4*node]>=mod)
							lazysub[4*node]%=mod;
						if(lazysub[4*node+1]>=mod)
							lazysub[4*node+1]%=mod;
					}
					lazysub[2*node]=0;
				}
				if(lazysub[2*node+1]!=0)
				{
					tree[2*node+1]=(end-((start+end)/2))*lazysub[2*node+1];
					if(tree[2*node+1]>=mod)
						tree[2*node+1]%=mod;
					lazyaddmul[2*node+1]=0;
					lazymul[2*node+1]=1;
					if((((start+end)/2)+1)!=end)
					{
						lazysub[4*node+2]=lazysub[2*node+1];
						lazysub[4*node+3]=lazysub[2*node+1];
						if(lazysub[4*node+2]>=mod)
							lazysub[4*node+2]%=mod;
						if(lazysub[4*node+3]>=mod)
							lazysub[4*node+3]%=mod;
					}
					lazysub[2*node+1]=0;
				}
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
				if(lazysub[2*node]!=0)
				{
					tree[2*node]=(((start+end)/2)-start+1)*lazysub[2*node];
					if(tree[2*node]>=mod)
						tree[2*node]%=mod;
					lazyaddmul[2*node]=0;
					lazymul[2*node]=1;
					if(start!=((start+end)/2))
					{
						lazysub[4*node]=lazysub[2*node];
						lazysub[4*node+1]=lazysub[2*node];
						if(lazysub[4*node]>=mod)
							lazysub[4*node]%=mod;
						if(lazysub[4*node+1]>=mod)
							lazysub[4*node+1]%=mod;
					}
					lazysub[2*node]=0;
				}
				if(lazysub[2*node+1]!=0)
				{
					tree[2*node+1]=(end-((start+end)/2))*lazysub[2*node+1];
					if(tree[2*node+1]>=mod)
						tree[2*node+1]%=mod;
					lazyaddmul[2*node+1]=0;
					lazymul[2*node+1]=1;
					if((((start+end)/2)+1)!=end)
					{
						lazysub[4*node+2]=lazysub[2*node+1];
						lazysub[4*node+3]=lazysub[2*node+1];
						if(lazysub[4*node+2]>=mod)
							lazysub[4*node+2]%=mod;
						if(lazysub[4*node+3]>=mod)
							lazysub[4*node+3]%=mod;
					}
					lazysub[2*node+1]=0;
				}
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
				if(lazysub[2*node]!=0)
				{
					tree[2*node]=((((start+end)/2)-start+1)*lazysub[2*node]);
					if(tree[2*node]>=mod)
						tree[2*node]%=mod;
					lazyaddmul[2*node]=0;
					lazymul[2*node]=1;
					if(start!=((start+end)/2))
					{
						lazysub[4*node]=lazysub[2*node];
						lazysub[4*node+1]=lazysub[2*node];
						if(lazysub[4*node]>=mod)
							lazysub[4*node]%=mod;
						if(lazysub[4*node+1]>=mod)
							lazysub[4*node+1]%=mod;
					}
					lazysub[2*node]=0;
				}
				if(lazysub[2*node+1]!=0)
				{
					tree[2*node+1]=(end-((start+end)/2))*lazysub[2*node+1];
					if(tree[2*node+1]>=mod)
						tree[2*node+1]%=mod;
					lazyaddmul[2*node+1]=0;
					lazymul[2*node+1]=1;
					if((((start+end)/2)+1)!=end)
					{
						lazysub[4*node+2]=lazysub[2*node+1];
						lazysub[4*node+3]=lazysub[2*node+1];
						if(lazysub[4*node+2]>=mod)
							lazysub[4*node+2]%=mod;
						if(lazysub[4*node+3]>=mod)
							lazysub[4*node+3]%=mod;
					}
					lazysub[2*node+1]=0;
				}
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
		else if(type==3)
		{
			tree[node]=(end-start+1)*v;
			// printf("Hello2 start=%lld end=%lld l=%lld r=%lld lazysub[node]=%lld tree[node]=%lld\n",start,end,l,r,lazysub[node],tree[node]);
			if(tree[node]>=mod)
				tree[node]%=mod;
			if(start!=end)
			{
				if(lazysub[2*node]!=0)
				{
					tree[2*node]=((((start+end)/2)-start+1)*lazysub[2*node]);
					if(tree[2*node]>=mod)
						tree[2*node]%=mod;
					lazyaddmul[2*node]=0;
					lazymul[2*node]=1;
					if(start!=((start+end)/2))
					{
						lazysub[4*node]=lazysub[2*node];
						lazysub[4*node+1]=lazysub[2*node];
						if(lazysub[4*node]>=mod)
							lazysub[4*node]%=mod;
						if(lazysub[4*node+1]>=mod)
							lazysub[4*node+1]%=mod;
					}
					lazysub[2*node]=0;
				}
				if(lazysub[2*node+1]!=0)
				{
					tree[2*node+1]=(end-((start+end)/2))*lazysub[2*node+1];
					if(tree[2*node+1]>=mod)
						tree[2*node+1]%=mod;
					lazyaddmul[2*node+1]=0;
					lazymul[2*node+1]=1;
					if((((start+end)/2)+1)!=end)
					{
						lazysub[4*node+2]=lazysub[2*node+1];
						lazysub[4*node+3]=lazysub[2*node+1];
						if(lazysub[4*node+2]>=mod)
							lazysub[4*node+2]%=mod;
						if(lazysub[4*node+3]>=mod)
							lazysub[4*node+3]%=mod;
					}
					lazysub[2*node+1]=0;
				}
				lazysub[2*node]=v;
				lazysub[2*node+1]=v;
				if(lazysub[2*node]>=mod)
					lazysub[2*node]%=mod;
				if(lazysub[2*node+1]>=mod)
					lazysub[2*node+1]%=mod;
			}
			lazysub[node]=0;
			lazymul[node]=1;
			lazyaddmul[node]=0;
		}
		return;
	}
	update(2*node,start,(start+end)/2);
	update(2*node+1,((start+end)/2) + 1,end);
	tree[node]=tree[2*node]+tree[2*node+1];
	if(tree[node]>=mod)
		tree[node]%=mod;
}
int main(int argc, char const *argv[])
{
	// ifstream fin;
	// ofstream fout;
	// fin.open("inp.txt");
	// fout.open("outtreetry.txt");
	n=read_int(),q=read_int();
	// fin>>n>>q;
	for(lli i=0;i<n;i++)
		a[i]=read_int();
	init(1,0,n-1);
	while(q--)
	{
		chc=read_int(),x=read_int(),y=read_int();
		// fin>>chc>>x>>y;
		x--,y--;
		l=x,r=y;
		type=chc;
		if(chc!=4)
			v=read_int();
		
			if(chc==1) 
				update(1,0,n-1);
			else if(chc==2)
				update(1,0,n-1);
			else if(chc==3)
				update(1,0,n-1);
			else		
			{
				ans=query(1,0,n-1)%mod;
				if(ans>=0)
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