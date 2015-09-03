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
lli a[100005]; 
int main(int argc, char const *argv[])
{
	lli t,n;
	t=scan();
	while(t--)
	{
		lli sum=0,minim=100000;
		bool minusoneflag=false;
		n=scan();
		if(n==1)
		{
			a[0]=scan();
			if(a[0]<2)
				printf("-1\n");
			else
				printf("2\n");
			continue;
		}
		for(lli i=0;i<n;i++)
		{
			a[i]=scan();
			if(a[i]<2)
				minusoneflag=true;
			minim=min(minim,a[i]);
			sum+=a[i];
		}
		if(minusoneflag)
			printf("-1\n");
		else
			printf("%lld\n",sum-minim+2);
	}	
	return 0;
}