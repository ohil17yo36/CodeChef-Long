#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli t,a[1000006],num;
inline long long int scan( )
{
long long int n = 0;
char c;
for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
n = (n * 10) + (c & 0x0f);
return n;
}
int main(int argc, char const *argv[])
{
	t=scan();
	while(t--)
	{
		num=scan();
		a[num]++;
	}
	for(lli i=0;i<=1000000;i++)
	{
		while(a[i]--)
		{
			printf("%lld\n",i);
		}
	}
	return 0;
}