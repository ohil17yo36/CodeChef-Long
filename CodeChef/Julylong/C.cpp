#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli t,n,k,a[100005],brem,ans,temp;
int main(int argc, char const *argv[])
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&k);
		for(lli i=0;i<n;i++)
			scanf("%lld",&a[i]);
		brem=0,ans=0;
		for(lli i=0;i<n;i++)
		{
			if(brem>=a[i])
				brem-=a[i];
			else
			{
				a[i]-=brem;
				temp=((a[i]+k-1)/k);
				ans+=temp;
				brem=(temp*k - a[i] );
				
			}
			if(brem>0)
				brem--;
		}
		printf("%lld\n",ans);
	}
	return 0;
}