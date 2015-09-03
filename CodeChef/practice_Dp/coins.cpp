#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli a[30][30];
lli func(lli n,lli i,lli j)
{
	if(n<12)
		a[i][j]=n;
	else if(a[i][j]==0)
			a[i][j]=func(n/2,i+1,j)+func(n/3,i,j+1)+func(n/4,i+2,j);
	return a[i][j];
}
int main(int argc, char const *argv[])
{
	lli t=10;
	while(t--)
	{
		for (lli i = 0; i < 30; ++i)
		{
			for(lli j=0;j<30;j++)
			{
				a[i][j]=0;
			}
		}
		lli n;
		scanf("%lld",&n);
		printf("%lld\n",func(n,0,0));
	}
	return 0;
}	