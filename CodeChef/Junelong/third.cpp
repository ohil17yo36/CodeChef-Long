#include <bits/stdc++.h>
using namespace std;
#define mod 1000000000
#define lli unsigned long long int
lli dp[2005][2005],nckdp[4010][4010],r,c;
int main(int argc, char const *argv[])
{
	lli t,n,m,ans=0;
	for(lli i=0;i<=4002;i++)
		nckdp[i][i]=1,nckdp[i][0]=1;
	for(lli i=2;i<=4002;i++)
		for(lli j=1;j<i;j++)
			nckdp[i][j]=(nckdp[i-1][j-1]+nckdp[i-1][j])%mod;	
	scanf("%lld",&t);
	while(t--)
	{	
		scanf("%lld %lld",&n,&m);	
		memset(dp,-1,sizeof(dp));
		r=n,c=m;
		for(lli i=1;i<=n;i++)
			dp[i][0]=1;
		for(lli i=1;i<=m;i++)
			dp[1][i]=nckdp[c+i][c];
		for(lli i=2;i<=n;i++)
		{
			ans=dp[i][0]%mod;
			for(lli j=1;j<=m;j++)
			{
				dp[i][j]=((dp[i-1][j]%mod)*(nckdp[c+j-1][j]))%mod;
				ans=(ans+dp[i][j])%mod;
				dp[i][j]=ans;
			}
		}
		printf("%lld\n",dp[n][m]);	
	}
	return 0;
}