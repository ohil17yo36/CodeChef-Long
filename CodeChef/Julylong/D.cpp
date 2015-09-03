#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define gtc getchar_unlocked()
#define inf (1<<20)
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
lli t,n,k,m,l,r,c,a[100005],minCostArray[100005],minCostArrayNeg[100005],aNeg[100005],knap[100005][505],tree[400020],sum=0,len,left,right,temp,minn;
void init(lli node,lli start,lli end)
{
	if(start>end)
		return;
	tree[node]=inf;
	if(start==end)
		return;
	init(2*node,start,(start+end)/2);
	init(2*node+1,((start+end)/2)+1,end);
	return;
}
void update(lli node,lli start,lli end)
{
	if(start>end || start>r || end<l)
		return;
	if(start>=l && end<=r)
	{
		tree[node]=min(tree[node],c);
		return;
	}
	update(2*node,start,(start+end)/2);
	update(2*node+1,((start+end)/2)+1,end);
	return;
}
lli traverse(lli node,lli start,lli end)
{
	if(start>end || start>r || end<l)
		return inf;
	if(start==end && start==l)
	{
		minn=min(minn,tree[node]);
		return minn;
	}
	if(start!=end)
	{
		lli tl=traverse(2*node,start,(start+end)/2);
		lli tr=traverse(2*node+1,((start+end)/2) + 1,end);
		minn=min(minn,min(tree[node],min(tl,tr)));
	}
	else
		minn=min(minn,tree[node]);
	return minn;
}
int main(int argc, char const *argv[])
{
	register lli temp1,temp2,temp3,temp4,temp5,temp6,temp7,ans;
	t=read_int();
	while(t--)
	{
		sum=0;
		n=read_int(),k=read_int(),m=read_int();
		for(lli i=0;i<n;i++)
			a[i]=read_int(),minCostArray[i]=minCostArrayNeg[i]=inf,sum+=a[i];
		minCostArrayNeg[n]=minCostArray[n]=inf;
		init(1,0,n-1);
		for(lli i=1;i<=m;i++)
		{
			l=read_int(),r=read_int(),c=read_int();
			l--,r--;
			update(1,0,n-1);
		}
		for(lli i=0;i<n;i++)
		{
			l=r=i,minn=inf;
			minCostArray[i]=traverse(1,0,n-1);
		}
		len=0;
		for(lli i=0;i<n;i++)
		{
			if(a[i]<0 && minCostArray[i]!=inf)
				aNeg[len]=-1*a[i],minCostArrayNeg[len]=minCostArray[i],len++;
		}
		for(lli i=0;i<=len;i++)
		{
			for(lli w=0;w<=k;w++)
			{
				if(i==0 || w==0)
					knap[i][w]=0;
				else 
				{	
					temp6=minCostArrayNeg[i-1];
					if(temp6<=w)
					{
						temp7=knap[i-1][w - temp6];
						if(aNeg[i-1]+temp7>knap[i-1][w])
							knap[i][w]=aNeg[i-1]+temp7;
						else
							knap[i][w]=knap[i-1][w];
					}
					else
						knap[i][w]=knap[i-1][w];
				}
			}
		}
		ans=knap[len][k]+sum;
		if(ans>=0)
			fastWrite(ans);
		else
		{
			printf("-");
			fastWrite(-1*ans);
		}
	}
	return 0;
}	