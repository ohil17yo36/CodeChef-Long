#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli t,n,h,l,r,L,R,rowBottom[1000006],rowTop[1000006],rowTotal[1000006];
int main(int argc, char const *argv[])
{
	scanf("%lld",&t);
	while(t--)
	{
		lli maxxb=-1,minnt=(1<<30);
		scanf("%lld %lld",&n,&h);
		for(lli i=0;i<=n;i++)
			rowTotal[i]=0,rowTop[i]=0,rowBottom[i]=0;
		for(lli i=0;i<n;i++)
		{
			scanf("%lld %lld",&l,&r);
			if(l>0)
				rowBottom[l-1]++,maxxb=max(maxxb,l-1);
			if(r<n-1)
				rowTop[r+1]++,minnt=min(minnt,r+1);
		}
		lli sum=0;
		for(lli i=maxxb;i>=0;i--)
		{
			rowBottom[i]+=sum;
			sum=rowBottom[i];
		}
		sum=0;
		for(lli i=minnt;i<n;i++)
		{ 
			rowTop[i]+=sum;
			sum=rowTop[i];
		}
		for(lli i=0;i<=maxxb;i++)
			rowTotal[i]=rowTop[i]+rowBottom[i];
		for(lli i=minnt;i<n;i++)
			rowTotal[i]=rowTop[i]+rowBottom[i];
		for(lli i=1;i<n;i++)
			rowTotal[i]+=rowTotal[i-1];
		lli ans=rowTotal[h-1];
		for(lli row=0;row+h-1<n;row++)
		{
			ans=min(ans,rowTotal[row+h-1]-rowTotal[row-1]);
		}
		printf("%lld\n",ans);	
	}
	return 0;
} 