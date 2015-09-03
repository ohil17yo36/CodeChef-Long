#include <bits/stdc++.h>
#define lli long long int
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
lli a[100005],n,counti,t;
int main(int argc, char const *argv[])
{
	t=scan();
	while(t--)
	{
		counti=0;
		n=scan();
		for(lli i=1;i<=n;i++)
			a[i]=scan();
		if(a[1]!=a[2])
			counti++;
		if(a[n-1]!=a[n])
			counti++;
		for(lli i=2;i<n;i++)
		{
			if((a[i]!=a[i-1]) || (a[i]!=a[i+1]))
			{
				counti++;
			}
		}
		cout<<counti<<endl;
	}
	return 0;
}