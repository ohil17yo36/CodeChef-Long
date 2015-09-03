#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		int a[n],dp[n][1025];
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		
		memset(dp,0,sizeof(dp));
		
		dp[0][0]=1,dp[0][a[0]]=1;

		for(int i=1;i<n;i++)
		{
			for(int j=0;j<=1024;j++)
			{
				dp[i][j]=dp[i-1][j]||dp[i][j];
				if(dp[i][j])
					dp[i][j^a[i]]=1;
			}
		}
		int maxx=-1;	
		for(int j=0;j<=1024;j++)
			if(dp[n-1][j])
				maxx=max(maxx,k^j);
		printf("%d\n",maxx);
	}
	return 0;
}