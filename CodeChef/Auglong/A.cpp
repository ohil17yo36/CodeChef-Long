#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli a[10000007],A,B,t;
int main(int argc, char const *argv[])
{
	lli i=1,ans;
	while(i<10000007)
	{
		a[i]=1;
		i*=2;
	}
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&A,&B);
		ans=0;
		while(A>B)
		{
			A/=2;
			ans++;
		}
		while(a[A]==0)
		{
			A/=2;
			ans++;	
		}
		while(A!=B)
		{
			A*=2;
			ans++;
		}
		
		printf("%lld\n",ans );
	}
	
	return 0;
}	