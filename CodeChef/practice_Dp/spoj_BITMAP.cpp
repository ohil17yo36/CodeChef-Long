#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli t,n,m,a[200][200],b[200][200];
void func(lli i,lli j)
{
	if(a[i][j]!=-1)
		return a[i][j];
	if(i==0 && j==0)
		return min(func(i+1,j),min(func(i+1,j+1),func(i,j+1)));
	if(i==0 && j==m-1)
		return min(func(i,j-1),min(func(i+1,j-1),func(i+1,j)));
	if(i==n-1 && j==0)
		return min(func(i-1,j),min(func(i,j+1),func(i-1,j+1)));
	if(i==n-1 && j==m-1)
		return min(func(i-1,j),min(func(i,j-1),func(i-1,j-1)));
	if(i==0)
		return min(func(i+1,j),min(func(i-1,j),min(func(i,j+1),min(func(i-1,j+1),func(i+1,j+1)))));
	if(i==n-1)
		return min(func())
	if(j==0)
		return min(func())

}
int main(int argc, char const *argv[])
{
	scanf("%lld",&t);
	while(t--)
	{
		memset(b,-1,sizeof(b));
		scanf("%lld %lld",&n,&m);
		for(lli i=0;i<m;i++)
			for(lli j=0;j<n;j++)
			{
				scanf("%lld",&b[i][j]);
				if(b[i][j])
					a[i][j]=0;
			}
		func(0,0);
		for(lli i=0;i<n;i++)
		{
			for(lli j=0;j<m;j++)
			{
				printf("%lld ",a[i][j]);
			}
			printf("\n");
		}	
	}
 	return 0;
} 