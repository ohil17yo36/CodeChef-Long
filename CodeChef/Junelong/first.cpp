#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli a[100005];
int main(int argc, char const *argv[])
{
	lli t,n,sum;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&a[0]);
		sum=a[0];
		for(lli i=1;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i-1]<a[i])
				sum+=(a[i]-a[i-1]);
		}
		printf("%lld\n",sum);
	}
	return 0;
}