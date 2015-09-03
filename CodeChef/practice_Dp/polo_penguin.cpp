#include <bits/stdc++.h>
using namespace std;
int c[102],p[102],t[102];
int ans[102][102];
int knapsack(int n,int w)
{
	int i,j;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=w;j++)
			{
				if(i==0||j==0)
				ans[i][j]=0;
				else if(t[i]>j)
				ans[i][j]=ans[i-1][j];
				else
				ans[i][j]=max(ans[i-1][j],(ans[i-1][j-t[i]]+c[i]*p[i]));
			}
		}
	return ans[n][w];	
}
int main(int argc, char const *argv[])
{
	int test,n,w;
	cin>>test;
	while(test--)
	{
		cin>>n>>w;
		
		for (int i = 1; i <= n; ++i)
		{
			cin>>c[i]>>p[i]>>t[i];
		}
		cout<<knapsack(n,w)<<endl;
	}
	return 0;
}