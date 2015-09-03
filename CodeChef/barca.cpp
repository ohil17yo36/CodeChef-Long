#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long int t,n,k,invmod;
inline long long int scan( )
{
long long int n = 0;
char c;
for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
n = (n * 10) + (c & 0x0f);
return n;
}
void ExtEuc(long long int a,long long int b,long long int& x,long long int& y)
{
	if(a%b==0)
	{
		x=0;
		y=1;
		return;
	}
	ExtEuc(b,a%b,x,y);
	long long int temp=x;
	x=y;
	y=(temp-y*(a/b));
}
long long int inverse(long long int a,long long int m)
{
	long long int x,y;
	ExtEuc(a,m,x,y);
	if(x<0)
		x+=m;
	return x;
}
long long int power(long long int base,long long int exponent)
{
	if(exponent==1)
		return base;
	else
	{
		long long int x=power(base,(exponent/2));
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
	
	t=scan();
	while(t--)
	{
		n=scan();
		k=scan();
		invmod=inverse(k+1,mod);
		if(n%2==0)
		{
			cout<<(((power(k,n)%mod + k%mod)%mod)*(invmod%mod))%mod<<endl;
		}
		else
		{
			cout<<(((power(k,n)%mod - k%mod + mod)%mod)*(invmod%mod))%mod<<endl;
		}
	}
	return 0;
}