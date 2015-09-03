#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli power(lli base,lli exponent,lli mod)
{
	if(exponent==1)
		return base%mod;
	else
	{
		lli x=power(base,exponent/2,mod);
		if(exponent%2==0)
			return ((x%mod)*(x%mod))%mod;
		else
			return ((base%mod)*(((x%mod)*(x%mod))%mod))%mod;
	}
}
lli number_of_digits(lli num)
{
	return ( (lli)log10(num) + 1);
}
int main(int argc, char const *argv[])
{
	lli n,k,t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&k);
		long double temp=n*log10(n);
		printf("%lld ",(lli)pow(10,(temp-((lli)temp)+(k-1))));
		lli ans2=power(n,n,pow(10,k));
		if(ans2==0)
		{
			for(lli i=0;i<(k);i++)
				printf("0");
			printf("\n");
			continue;		
		}
		lli number=number_of_digits(ans2);
		if(number<k)
		{
			for(lli i=0;i<(k-number);i++)
				printf("0");
		}
		printf("%lld\n",ans2);
	}
	return 0;
}