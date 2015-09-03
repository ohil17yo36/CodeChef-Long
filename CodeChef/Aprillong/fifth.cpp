#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli t,n,k,m,x,y,a[200002],b[200002];
inline lli scan( )
{
lli n = 0;
char c;
for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
n = (n * 10) + (c & 0x0f);
return n;
}
vector<long long int>v[200002];
vector<bool>visited;
int main(int argc, char const *argv[])
{
	t=scan();
	while(t--)
	{
		m=scan();
		k=scan();
		n=scan();
		while(k--)
		{
			x=scan();
			y=scan();
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(lli i=1;i<=n;i++)
		{
			a[i]=scan();
			b[i]=a[i];
		}
		sort(b,b+n);

	}
	return 0;
}