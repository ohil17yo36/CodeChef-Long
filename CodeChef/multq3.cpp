#include <bits/stdc++.h>
using namespace std;
#define lli long long int
inline lli scan( )
{
	register lli n = 0;
	register char c;
	for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
	for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
		n = (n * 10) + (c & 0x0f);
	return n;
}
struct mult3
{
	lli rem_0,rem_1,rem_2,add_cnt;
}tree[400012];

lli N,q,chc,L,R;

void init(lli node,lli start,lli end)
{
	if(start==end)
	{
		tree[node].rem_0=1;
		tree[node].rem_1=0;
		tree[node].rem_2=0;
		tree[node].add_cnt=0;
		return ;
	}
	lli mid=(start+end)>>1;

	tree[node].rem_0=end-start+1;
	tree[node].rem_1=0;
	tree[node].rem_2=0;
	tree[node].add_cnt=0;
	
	init(2*node,start,mid);
	init(2*node + 1,mid + 1,end);
}
inline void circulate(lli node)
{
	lli temp=tree[node].rem_2;
	tree[node].rem_2=tree[node].rem_1;
	tree[node].rem_1=tree[node].rem_0;
	tree[node].rem_0=temp;
}
void update(lli node,lli start,lli end,lli l,lli r)
{
	if(start==l && end==r)
	{
		tree[node].add_cnt++;
		circulate(node);
		return;	
	}
	lli mid=start +(end-start)/2;	
	if(r<=mid)
		update(2*node,start,mid,l,r);
	else if(l>mid)
			update(2*node +1,mid +1,end,l,r);
	else
	{
		update(2*node,start,mid,l,mid);
		update(2*node +1,mid +1,end,mid +1,r);
	}
	tree[node].rem_0=tree[2*node].rem_0+tree[2*node+1].rem_0;
	tree[node].rem_1=tree[2*node].rem_1+tree[2*node+1].rem_1;
	tree[node].rem_2=tree[2*node].rem_2+tree[2*node+1].rem_2;
	lli cnt=((tree[node].add_cnt)%3);
	for(int i=0;i<cnt;i++)
	{
		circulate(node);
	}
}
lli query(lli node,lli start,lli end,lli l,lli r,lli add_cnt_total)
{
	if(start==l && end==r)
	{
		if(add_cnt_total%3==0)
			return tree[node].rem_0;
		else if(add_cnt_total%3==1)
			return tree[node].rem_2;
		else
			return tree[node].rem_1;
	}
	add_cnt_total+=tree[node].add_cnt;
	lli mid=start+(end-start)/2;
	if(r<=mid)
		return query(2*node,start,mid,l,r,add_cnt_total);
	else if(l>mid)
		return query(2*node +1,mid +1,end,l,r,add_cnt_total);
	else
		return query(2*node,start,mid,l,mid,add_cnt_total)+query(2*node +1,mid +1,end,mid +1,r,add_cnt_total);
}

int main(int argc, char const *argv[])
{
	N=scan();
	q=scan();

	init(1,0,N-1);
	while(q--)
	{
		chc=scan();
		L=scan();
		R=scan();
		if(chc==1)
			printf("%lld\n",query(1,0,N-1,L,R,0));
		else
			update(1,0,N-1,L,R);
	}
	return 0;
}