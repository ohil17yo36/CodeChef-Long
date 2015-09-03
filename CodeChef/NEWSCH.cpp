#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
inline long long int scan( )
{
long long int n = 0;
char c;
for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
n = (n * 10) + (c & 0x0f);
return n;
}
long long int power(long long int base,long long int exponent)
{
	if(exponent==1)
		return base;
	else
	{
		long long int x=power(base,(long long int)floor(exponent/2));
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
int main(int argc, char const *argv[])
{
	long long int n;
	int t;
	t=scan();
	while(t--)
	{
		n=scan();
		if(n%2==0)
		{
			cout<<((power(3,n)%mod)+3%mod)%mod<<endl;
			continue;
		}
		else
		{
			cout<<((power(3,n)%mod)-3%mod + mod)%mod<<endl;
		}
	}
	return 0;
}