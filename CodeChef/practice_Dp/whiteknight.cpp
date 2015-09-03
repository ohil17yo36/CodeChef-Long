#include <bits/stdc++.h>
using namespace std;
char b[1008][1008];
long long int ans[1008][1008];
int main(int argc, char const *argv[])
{
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		scanf("%lld\n",&n);
		for (int i = 0; i < n; ++i)
		{
			gets(b[i]);
		}
		
		long long int flag=0;
		for (long long int j = n-1; j>=0; j--)
		{
			
			for(long long int i=0;i<n;i++)
			{	
				long long int maxval=0,extra=0;
				if(b[i][j]=='P')
				extra=1;	
				if(i-2>=0 && j+1<n)
					maxval=max(maxval,ans[i-2][j+1]);
				if(i-1>=0 && j+2<n)
					maxval=max(maxval,ans[i-1][j+2]);
				if(i+1<n && j+2<n)
					maxval=max(maxval,ans[i+1][j+2]);
				if(i+2<n && j+1<n)
					maxval=max(maxval,ans[i+2][j+1]);
				
				ans[i][j]=maxval+extra;

				if(b[i][j]=='K')
				{
					cout<<ans[i][j]<<endl;
					flag=1;
					break;
				}

			}
			if(flag==1)
				break;
			
		}
		for (long long int i = 0; i < n; ++i)
		{
			for (long long int j= 0; j < n; ++j)
			{
				ans[i][j]=0;
			}
		}
	}
	return 0;
}