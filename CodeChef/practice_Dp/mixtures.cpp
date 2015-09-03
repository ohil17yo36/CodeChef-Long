#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{

	int n;
	while((scanf("%d",&n))==1)
	{// {printf("%d\n",n );
		int a[n+1];
	for (int i = 1; i <= n; ++i)
		scanf("%d",&a[i]);
	int smoke[n+1][n+1],result[n+1][n+1];
	for (int i = 1; i <= n; ++i)
	{
		result[i][i]=a[i];
		smoke[i][i]=0; 	
	}
	for(int chlen=2;chlen<=n;chlen++)
	{
		for (int i = 1; i <= n-chlen+1; ++i)
		{
			int j=i+chlen-1;
			smoke[i][j]=INT_MAX;
			int q;
			for (int k = i; k <=j-1 ; ++k)
			{
				q=smoke[i][k]+smoke[k+1][j]+result[i][k]*result[k+1][j];
				if(q<smoke[i][j])
				{
					smoke[i][j]=smoke[i][k]+smoke[k+1][j]+result[i][k]*result[k+1][j];
					result[i][j]=(result[i][k]+result[k+1][j])%100;	
				}
			}
		}
	}
	printf("%d\n",smoke[1][n]);
	}
	return 0;
}