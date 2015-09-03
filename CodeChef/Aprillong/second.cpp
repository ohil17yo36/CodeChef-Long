#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli n,i,t,root,divcount,prod=1;
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
	if(exponent==1)
		return base;
	lli x=power(base,exponent/2);

	if(exponent%2==0)
		return x*x;
	else
		return base*x*x;
}
int main(int argc, char const *argv[])
{
	t=scan();
	while(t--)
	{
		n=scan(),prod=1;
		root=sqrt(n);
		divcount=0;
		while(n%2==0)
		{
			divcount++;
			n/=2;
		}
		if(divcount==1)
			prod*=3;
		if(divcount>1)
			prod*=(power(2,divcount+1)-1);
		for( i=3;i<=root;i+=2)
		{
			divcount=0;
			while(n%i==0)
			{
				divcount++;
				n/=i;
			}
			if(divcount==1)
				prod*=(i+1);
			if(divcount>1)
				prod*=((power(i,divcount+1)-1)/(i-1));
		}
		divcount=0;
		if(n>2)
		prod*=(n+1);
		cout<<prod<<endl;	
	}
	return 0;
}