#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli dp[1004],dp_flg[1004],dp_hold[1004],t,n;
int main(int argc, char const *argv[])
{
	dp_flg[0]=dp_hold[0]=0;
	dp[0]=dp[1]=dp_flg[1]=dp_hold[1]=1;
	for(lli i=2;i<1004;i++)
	{
		dp[i]=dp[i-1]+dp[i-2]+ 2*dp_flg[i-1] + dp_hold[i-1];
		dp_flg[i]=dp[i-1] + dp_flg[i-1];
		dp_hold[i]=dp[i-1] + dp_hold[i-2];
	}
	scanf("%lld",&t);
	for(lli i=1;i<=t;i++)
	{
		scanf("%lld",&n);
		printf("%lld %lld\n",i,dp[n]);
	}
	return 0;
}	