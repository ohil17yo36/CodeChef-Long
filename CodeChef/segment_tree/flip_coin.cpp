#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
inline lli scan( )
{
	lli n1 = 0;
	char ch;
	for( ch = getchar_unlocked(); ch==' ' || ch=='\n' || ch == '\t'; ch = getchar_unlocked());
	for( ; ch > 0x2f && ch < 0x3a; ch = getchar_unlocked())
	n1 = (n1 * 10) + (ch & 0x0f);
	return n1;
}
inline void fastWrite(lli a)
{
	char snum[20];
	int i=0;
	do
	{
	snum[i++]=a%10+48;
	a=a/10;
	}while(a!=0);
	i=i-1;
	while(i>=0)
	putchar_unlocked(snum[i--]);
	putchar_unlocked('\n');
}
struct flip
{
	lli head,tail;
	flip()
	{
		head=0;
		tail=0;
	}
}tree[400012];
lli lazy[400012],n,q,chc,L,R;
void init(lli node,lli l,lli r)
{
	if(l>r)
		return;
	if(l==r)
	{
		tree[node].head=0;
		tree[node].tail=1;
		return;
	}
	init(2*node,l,l+(r-l)/2);
	init(2*node+1,l+(r-l)/2+1,r);
	tree[node].head=tree[2*node].head+tree[2*node+1].head;
	tree[node].tail=tree[2*node].tail+tree[2*node+1].tail;
	return;
}
lli query(lli node,lli start,lli end,lli l,lli r)
{

	if(start>end || end<l || start>r)
		return 0;
	if(lazy[node]!=0)
	{
		swap(tree[node].head,tree[node].tail);
		if(start!=end)
		{
			lazy[2*node]^=1;
			lazy[2*node+1]^=1;
		}
		lazy[node]=0;
	}

	if(start>=l && end<=r)
		return tree[node].head;

	return query(2*node,start,start+(end-start)/2,l,r)+query(2*node+1,start+(end-start)/2 +1,end,l,r);
}
void update(lli node,lli start,lli end,lli l,lli r)
{
	if(start>end)
		return ;
	if(lazy[node]!=0)
	{
		swap(tree[node].head,tree[node].tail);
		if(start!=end)
		{
			lazy[2*node]^=1;
			lazy[2*node+1]^=1;
		}
		lazy[node]=0;
	}

	if(start>end || end<l || start>r)
		return ;
	if(start>=l && end<=r)
	{
		swap(tree[node].head,tree[node].tail);
		if(start!=end)
		{
			lazy[2*node]^=1;
			lazy[2*node+1]^=1;
		}
		return;
	}
	update(2*node,start,start+(end-start)/2,l,r);
	update(2*node+1,start+(end-start)/2 +1,end,l,r);
	tree[node].head=tree[2*node].head+tree[2*node+1].head;
	tree[node].tail=tree[2*node].tail+tree[2*node+1].tail;
	return;
}
int main(int argc, char const *argv[])
{
	n=scan();
	q=scan();
	init(1,0,n-1);
	while(q--)
	{
		chc=scan();
		L=scan();
		R=scan();
		if(chc==0)
			update(1,0,n-1,L,R);
		else
			fastWrite(query(1,0,n-1,L,R));
	}
	return 0;
}	