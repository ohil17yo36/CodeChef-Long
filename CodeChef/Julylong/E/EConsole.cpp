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
inline void fastWrite(lli a)
{
	char snum[35];
	lli I=0;
	do
	{
	snum[I++]=a%10+48;
	a=a/10;
	}while(a!=0);
	I=I-1;
	while(I>=0)
	putchar_unlocked(snum[I--]);
	putchar_unlocked('\n');
}
lli n,q,a[100005],x,y,v,chc,tree[400020],l,r,type,ans,lazymul[400020],lazyrest[400020],lazysub[400020];
void init(lli node,lli start,lli end)
{
	if(start>end)
		return;
	if(start==end)
	{
		tree[node]=a[start];
		if(tree[node]>=mod)
			tree[node]=tree[node]%mod;
		lazysub[node]=0;
		lazyrest[node]=0;
		lazymul[node]=1;
		return;
	}
	init(2*node,start,(start+end)/2);
	init(2*node + 1,((start+end)/2) + 1,end);
	tree[node]=tree[2*node]+tree[2*node + 1];
	if(tree[node]>=mod)
		tree[node]=(tree[node]%mod);
	lazymul[node]=1;
	lazyrest[node]=0;
	lazysub[node]=0;
	return; 
}
lli query(lli node,lli start,lli end)
{
	if(start>end || end<l || start>r)
		return 0;
	if(lazymul[node]!=1 || lazyrest[node]!=0 || lazysub[node]!=0)
	{
		if(lazysub[node]!=0)
		{
			tree[node]=((lazysub[node]%mod)*((end-start+1)%mod))%mod;
			lazymul[node]=1;
			lazyrest[node]=0;
			if(start!=end)
			{
				lazysub[2*node]+=lazysub[node];
				lazysub[2*node + 1]+=lazysub[node];
				if(lazysub[2*node]>=mod)
					lazysub[2*node]=lazysub[2*node]%mod;
				if(lazysub[2*node + 1]>=mod)
					lazysub[2*node + 1]=lazysub[2*node + 1]%mod;
			}
			lazysub[node]=0;
		}
		else
		{
			tree[node]=(((tree[node]%mod)*(lazymul[node]%mod))%mod + (((end-start+1)%mod)*(lazyrest[node]%mod))%mod)%mod;
			if(start!=end)
			{
				lazymul[2*node]=((lazymul[2*node]%mod)*(lazymul[node]%mod))%mod;
				lazymul[2*node + 1]=((lazymul[2*node + 1]%mod)*(lazymul[node]%mod))%mod;
				lazyrest[2*node]+=lazyrest[node];
				lazyrest[2*node + 1]+=lazyrest[node];
				
				if(lazyrest[2*node]>=mod)
					lazyrest[2*node]=lazyrest[2*node]%mod;
				if(lazyrest[2*node + 1]>=mod)
					lazyrest[2*node + 1]=lazyrest[2*node + 1]%mod;
			}
			lazymul[node]=1;
			lazyrest[node]=0;
		}
	}
	if(start>=l && end<=r)
		return tree[node]%mod;
	return (query(2*node,start,(start+end)/2) + query(2*node + 1,((start+end)/2) + 1,end))%mod;
}
void update(lli node,lli start,lli end)
{
	if(start>end)
		return ;
	if(lazymul[node]!=1 || lazyrest[node]!=0 || lazysub[node]!=0)
	{
		if(lazysub[node]!=0)
		{
			tree[node]=((lazysub[node]%mod)*((end-start+1)%mod))%mod;
			lazymul[node]=1;
			lazyrest[node]=0;
			if(start!=end)
			{
				lazysub[2*node]+=lazysub[node];
				lazysub[2*node + 1]+=lazysub[node];
				if(lazysub[2*node]>=mod)
					lazysub[2*node]=(lazysub[2*node]%mod);
				if(lazysub[2*node + 1]>=mod)
					lazysub[2*node + 1]=(lazysub[2*node + 1]%mod);
			}
			lazysub[node]=0;
		}
		else
		{
			tree[node]=(((tree[node]%mod)*(lazymul[node]%mod))%mod + (((end-start+1)%mod)*(lazyrest[node]%mod))%mod)%mod;
			if(start!=end)
			{
				lazymul[2*node]=((lazymul[2*node]%mod)*(lazymul[node]%mod))%mod;
				lazymul[2*node + 1]=((lazymul[2*node + 1]%mod)*(lazymul[node]%mod))%mod;
				lazyrest[2*node]+=lazyrest[node];
				lazyrest[2*node + 1]+=lazyrest[node];
				
				if(lazyrest[2*node]>=mod)
					lazyrest[2*node]=lazyrest[2*node]%mod;
				if(lazyrest[2*node + 1]>=mod)
					lazyrest[2*node + 1]=lazyrest[2*node + 1]%mod;
			}
			lazymul[node]=1;
			lazyrest[node]=0;
		}
	}
	if(start>end || end<l || start>r)
		return ;
	if(start>=l && end<=r)
	{
		if(type==3)
		{
			lazysub[node]+=v;
			if(lazysub[node]>=mod)
				lazysub[node]=lazysub[node]%mod;
			tree[node]=((lazysub[node]%mod)*((end-start+1)%mod))%mod;
			lazyrest[node]=0;
			lazymul[node]=1;
			if(start!=end)
			{
				lazysub[2*node]+=lazysub[node];
				lazysub[2*node + 1]+=lazysub[node];
				if(lazysub[2*node]>=mod)
					lazysub[2*node]=(lazysub[2*node]%mod);
				if(lazysub[2*node + 1]>=mod)
					lazysub[2*node + 1]=(lazysub[2*node + 1]%mod);
			}
			lazysub[node]=0;
			return ;
		}
		else if(type==1)
			lazyrest[node]+=v,tree[node]=(((tree[node]%mod)*(lazymul[node]%mod))%mod + (((end-start+1)%mod)*(lazyrest[node]%mod))%mod)%mod;
		else if(type ==2)
			lazymul[node]=((lazymul[node]%mod)*(v%mod))%mod,lazyrest[node]=(((lazyrest[node])%mod)*(v%mod))%mod,tree[node]=((tree[node]%mod)*(lazymul[node]%mod))%mod;
		if(lazymul[node]>=mod)
			lazymul[node]=lazymul[node]%mod;
		if(lazyrest[node]>=mod)
			lazyrest[node]=lazyrest[node]%mod;
		
		if(start!=end)
		{
			lazymul[2*node]=((lazymul[2*node]%mod)*(lazymul[node]%mod))%mod;
			lazymul[2*node + 1]*=((lazymul[2*node + 1]%mod)*(lazymul[node]%mod))%mod;
			lazyrest[2*node]+=lazyrest[node];
			lazyrest[2*node + 1]+=lazyrest[node];	
			if(lazyrest[2*node]>=mod)
				lazyrest[2*node]=lazyrest[2*node]%mod;
			if(lazyrest[2*node + 1]>=mod)
				lazyrest[2*node + 1]=lazyrest[2*node + 1]%mod;		
		}
		lazymul[node]=1;
		lazyrest[node]=0;
		return;
	}
	update(2*node,start,(start+end)/2);
	update(2*node + 1,((start+end)/2) + 1,end);
	tree[node]=(tree[2*node]+tree[2*node + 1])%mod;
	return ;
}
int main(int argc, char const *argv[])
{
	ifstream fin;
	ofstream fout;
	fin.open("inp.txt");
	fout.open("outtree.txt");
	n=read_int(),q=read_int();
	// fin>>n>>q;
	for(lli i=0;i<n;i++)
		/*fin>>a[i];*/ a[i]=read_int();
	init(1,0,n-1);
	while(q--)
	{
		chc=read_int(),x=read_int(),y=read_int();
		// fin>>chc>>x>>y;
		// x--,y--;
		l=x,r=y;
		type=chc;
		if(chc!=4)
			/* fin>>v;*/ v=read_int();
		
			if(chc==1) 
				update(1,0,n-1);
			else if(chc==2)
				update(1,0,n-1);
			else if(chc==3)
				update(1,0,n-1);
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
				cout<<ans<<endl;							
			}
	}

	return 0;
}