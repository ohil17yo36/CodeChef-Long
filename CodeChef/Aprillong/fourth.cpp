#include <bits/stdc++.h>
#define lli long long int 
using namespace std;
lli mod=1000003;
lli factorial[10000000];
inline lli scan( )
{
lli n = 0;
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
long long int InverseEuler(long long int a)
{
	lli m=mod;
	long long int x,y;
	ExtEuc(a,m,x,y);
	if(x<0)
		x+=m;
	return x;
}



void factorialinit(lli n)
{
	factorial[0]=1;
	for(lli i=1;i<n;i++)
	{
		factorial[i]=(factorial[i-1]*i)%mod;
	}
}
int main(int argc, char const *argv[])
{
	lli t,n,l,r,i,res,N1,M1,No,Mo;
	factorialinit(10000000);
	t=scan();
	while(t--)
	{
		n=scan();
		l=scan();
		r=scan();
		N1=r-l+n+1;
		M1=r-l+1;
		No=N1%mod;
		N1/=mod;
		Mo=M1%mod;
		M1/=mod;
		if(Mo>No)
			res=0;
		else
			res=(((((((factorial[No]%mod)*(InverseEuler(factorial[Mo])%mod))%mod)*((InverseEuler(factorial[No-Mo]))%mod))%mod)%mod)*((((((factorial[N1]%mod)*(InverseEuler(factorial[M1])%mod))%mod)*((InverseEuler(factorial[N1-M1]))%mod))%mod)%mod))%mod;

		cout<<((res+mod-1)%mod)<<endl;
	}
	return 0;
}