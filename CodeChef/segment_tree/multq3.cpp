#include <cstdio>	
using namespace std;
#define lli long long int
inline lli scan( )
{
	lli n1 = 0;
	char c;
	for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
	for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
	n1 = (n1 * 10) + (c & 0x0f);
	return n1;
}
/*
inline void fastWrite(lli a)
{
	char snum[20];
	int i1=0;
	do
	{
	snum[i1++]=a%10+48;
	a=a/10;
	}while(a!=0);
	i1=i1-1;
	while(i1>=0)
	putchar_unlocked(snum[i1--]);
	putchar_unlocked('\n');
}*/

struct multq3
{
	lli rem_0;
	lli rem_1;
	lli rem_2;
}tree[4000012];

lli lazy[4000012];
//lazy[node] stores the number of updations that have happened to that node either directly calling update or from higher up nodes
void init(lli node,lli start,lli end)
{
	if(start>end)
		return;
	if(start==end)
	{
		tree[node].rem_0=1;
		tree[node].rem_1=0;
		tree[node].rem_2=0;
		return;
	}
	init((node<<1),start,((start+end)>>1));
	init((node<<1)+1,((start+end)>>1)+1,end);
	tree[node].rem_0=tree[(node<<1)].rem_0+tree[(node<<1)+1].rem_0;
	tree[node].rem_1=tree[(node<<1)].rem_1+tree[(node<<1)+1].rem_1;
	tree[node].rem_2=tree[(node<<1)].rem_2+tree[(node<<1)+1].rem_2;
}

// inline void circulate(lli node)//circulate circulates the remainder values...circulate is called once an updation of values is required
// {
// 	lli temp=tree[node].rem_2;
// 	tree[node].rem_2=tree[node].rem_1;
// 	tree[node].rem_1=tree[node].rem_0;
// 	tree[node].rem_0=temp;
// }

lli query(lli node,lli start,lli end,lli l,lli r)
{
	if(start>end || start>r || end<l)
		return 0;
	if(lazy[node]!=0)
	{
		for(int i=0;i<lazy[node];i++)
		{
			lli temp=tree[node].rem_2;
			tree[node].rem_2=tree[node].rem_1;
			tree[node].rem_1=tree[node].rem_0;
			tree[node].rem_0=temp;
		}
		if(start!=end)
		{
			lazy[(node<<1)]=(lazy[(node<<1)]+lazy[node])%3;
			lazy[(node<<1)+1]=(lazy[(node<<1)+1]+lazy[node])%3;
		}
		lazy[node]=0;
	}
	
	if(start>=l && end<=r)
		return tree[node].rem_0;
	
	return query((node<<1),start,((start+end)>>1),l,r)+query((node<<1)+1,((start+end)>>1) + 1,end,l,r);
}

void update(lli node,lli start,lli end,lli l,lli r)
{
	if(start>end || start>r || end<l)
		return ;
	if(lazy[node]!=0)
	{
		for(int i=0;i<lazy[node];i++)
		{
			lli temp=tree[node].rem_2;
			tree[node].rem_2=tree[node].rem_1;
			tree[node].rem_1=tree[node].rem_0;
			tree[node].rem_0=temp;
		}
		if(start!=end)
		{
			lazy[(node<<1)]=(lazy[(node<<1)]+lazy[node])%3;
			lazy[(node<<1)+1]=(lazy[(node<<1)+1]+lazy[node])%3;
		}
		
		lazy[node]=0;
	}
	
	if(start>=l && end<=r)
	{
			lli temp=tree[node].rem_2;
			tree[node].rem_2=tree[node].rem_1;
			tree[node].rem_1=tree[node].rem_0;
			tree[node].rem_0=temp;
		
		if(start!=end)
		{
			lazy[(node<<1)]=(lazy[(node<<1)]+1)%3;
			lazy[(node<<1)+1]=(lazy[(node<<1)+1]+1)%3;
		}
		
		return;
	}
	update((node<<1),start,((start+end)>>1),l,r);
	update((node<<1)+1,((start+end)>>1) + 1,end,l,r);
	tree[node].rem_0=tree[(node<<1)].rem_0+tree[(node<<1)+1].rem_0;
	tree[node].rem_1=tree[(node<<1)].rem_1+tree[(node<<1)+1].rem_1;
	tree[node].rem_2=tree[(node<<1)].rem_2+tree[(node<<1)+1].rem_2;
	
	return;
} 

int main(int argc, char const *argv[])
{
	lli n,q,choice,A,B;
	n=scan();
	q=scan();
	init(1,0,n-1);
	while(q--)
	{
		choice=scan();
		A=scan();
		B=scan();
		if(choice)
			printf("%lld\n",query(1,0,n-1,A,B));
		else
			update(1,0,n-1,A,B);
	}
	return 0;
}	