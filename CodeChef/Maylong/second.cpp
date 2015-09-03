#include <bits/stdc++.h>
#define lli long long int
#define mod 1000000007
using namespace std;
inline lli scan( )
{
lli n = 0;
char c;
for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
n = (n * 10) + (c & 0x0f);
return n;
}
lli power(lli base,lli exponent)
{
	if(exponent==0)
		return 1;
	else
	{
		lli x=power(base,(exponent/2));
		if(exponent%2==0)
		{
			return ((x%mod)*(x%mod))%mod;
		}
		else
		{
			return ((base%mod)*((((x%mod)*(x%mod))%mod)%mod))%mod;
		}
	}
}
lli a[100006];
int main(int argc, char const *argv[])
{
	lli t,n;
	t=scan();
	while(t--)
	{
		n=scan();
		for(lli i=1;i<=n;i++)
			a[i]=scan();
		sort(a+1,a+n+1);
		lli sum=0;
		for(lli i=1;i<=n;i++)
		{
			sum+=(((((power(2,i-1))%mod) - ((power(2,n-i))%mod) + mod)%mod)*(a[i]%mod))%mod;
			sum=(sum+mod)%mod;
		}
		printf("%lld\n",(sum+mod)%mod);
	}
	return 0;
}