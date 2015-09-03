#include <bits/stdc++.h>
#define lli unsigned long long int
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
lli gcd(lli a,lli b)
{
	if(a==0)
		return b;
	else
		return gcd(b%a,a);
}
void func(lli a,lli b)
{
	lli g_div=gcd(a,b);
	lli temp=b/g_div;
	if(g_div==1)
	{
		if(b!=1)
			printf("No\n");
		else
			printf("Yes\n");
		return;
	}
	func(g_div,temp);
}
int main(int argc, char const *argv[])
{
	lli t,a,b;
	t=scan();
	while(t--)
	{
		a=scan();
		b=scan();
		func(a,b);
	}
	return 0;
}