#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mod 1000000007
inline lli scan( )
{
	register lli n1 = 0;
	char c;
	for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
	for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
	n1 = (n1 * 10) + (c & 0x0f);
	return n1;
}
std::vector<lli> li[5005];
lli sort_index[17][5005],suffix_array[5005],L[5005],R[5005],lcparr[5005],ans[5005];
lli t,n,q,k,idx,step,cnt,otherEnd[5005],counter[5005],nckdp[5005][5005];
char str[5005],ch;


struct entry
{
	lli nr[2];
	lli p;
}List[5005];



lli cmp(struct entry a, struct entry b)
{
    return a.nr[0]==b.nr[0] ?(a.nr[1]<b.nr[1] ?1: 0): (a.nr[0]<b.nr[0] ?1: 0);
}

void construct_suffix_array()
{
	for(lli i=0;i<n;i++)
		sort_index[0][i]=str[i]-'a';
	for(step=1,cnt=1;cnt<n;step++,cnt*=2)
	{
		for(lli i=0;i<n;i++)
		{
			List[i].nr[0]=sort_index[step-1][i];
			List[i].nr[1]=((i+cnt)<n)?sort_index[step-1][i+cnt]:-1;
			List[i].p=i;
		}
		sort(List,List+n,cmp);
		for(lli i=0;i<n;i++)
			sort_index[step][List[i].p]=(i>0 && List[i].nr[0]==List[i-1].nr[0] && List[i].nr[1]==List[i-1].nr[1])?sort_index[step][List[i-1].p]:i;
	}
	step--;
	for(lli i=0;i<n;i++)
		suffix_array[sort_index[step][i]]=i;
}

lli lcp(lli x,lli y)
{
	if(x==y)
		return n-x;
	lli answer=0;
	for(lli k=step;k>=0 && x<n && y<n;k--)
		if(sort_index[k][x]	== sort_index[k][y])
			answer+=(1<<k),x+=(1<<k),y+=(1<<k);
	return answer;	
}

int main(int argc, char const *argv[])
{
	for(lli i=0;i<=5002;i++)
		nckdp[i][i]=1,nckdp[i][0]=1;
	for(lli i=2;i<=5002;i++)
	{	for(lli j=1;j<i;j++)
		{
			nckdp[i][j]=(nckdp[i-1][j-1]+nckdp[i-1][j]);
			if(nckdp[i][j]>=mod)
				nckdp[i][j]-=mod;
		}
	}	
	t=scan();
	while(t--)
	{
		// idx=0,n=scan(),q=scan();
		idx=0;
		while((ch=getchar_unlocked())!='\n')
			str[idx++]=ch;
		str[idx]='\0';
		n=idx;
		// puts(str);
		construct_suffix_array();
		for(lli i=0;i<n;i++)
			printf("%lld ",suffix_array[i]);
		printf("\n");
		for(lli i=1;i<n;i++)
			lcparr[i]=lcp(suffix_array[i-1],suffix_array[i]),printf("%lld ",lcparr[i]);//li[i].clear(),counter[i]=0;
		printf("\n");
		// for(lli i=0;i<n-1;i++)
		// {
		// 	li[lcparr[i]=lcp(suffix_array[i],suffix_array[i+1])].push_back(i);
		// 	otherEnd[i]=i;
		// }	
		// for(lli i=n;i>=1;i--)
		// {
		// 	lli j=0;
		// 	if(li[i].size())
		// 	{
		// 		lli l=li[i][0],r=otherEnd[l];
		// 		while(j<li[i].size())
		// 		{
		// 			bool lr=false;
		// 			if(l>0 && lcparr[l-1]>=i)
		// 			{
		// 				lr=true;
		// 				l=otherEnd[l-1];
		// 			}
		// 			if(r<n-2 && lcparr[r+1]>=i)
		// 			{
		// 				lr=true;
		// 				r=otherEnd[r+1];
		// 			}
		// 			if(lr)
		// 				continue;
		// 			otherEnd[l]=r;
		// 			otherEnd[r]=l;
		// 			lli mini=i;
		// 			if(l>0 && mini>(i-lcparr[l-1]))
		// 				mini=i-lcparr[l-1];
		// 			if(r<n-2 && mini>(i-lcparr[r+1]))
		// 				mini=i-lcparr[r+1];
		// 			counter[r-l+2]+=mini;
		// 			while(j<li[i].size() && li[i][j]<=r)j++;
		// 			if(j<li[i].size())
		// 				l=li[i][j],r=otherEnd[l];
		// 		}
		// 	}
		// }
		// for(lli i=1;i<=n;i++)
		// {
		// 	ans[i]=0;
		// 	for(lli j=i;j<=n;j++)
		// 		if(counter[j]>0)
		// 		{
		// 			ans[i]=(ans[i]+(counter[j]*nckdp[j][i]));
		// 			if(ans[i]>=mod)
		// 				ans[i]=ans[i]%mod;
		// 		}
		// }
		// ans[1]=(n*(n+1))/2;
		// while(q--)
		// {
		// 	k=scan();
		// 	if(k>n || k<1)
		// 		printf("0\n");
		// 	else
		// 		printf("%lld\n",ans[k]);
		// }
	}
	return 0;
}