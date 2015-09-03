#include <bits/stdc++.h>
using namespace std;
unsigned long long int gcd(unsigned long long int a,unsigned long long int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main(int argc, char const *argv[])
{
	unsigned long long int t;
	scanf("%llu",&t);
	while(t--)
	{
		unsigned long long int n,k,divisor,ans=1;
		scanf("%llu %llu",&n,&k);
		if(k>n)
		{
			cout<<0<<endl;
			continue;
		}	
		if(k>n-k)
			k=n-k;
		for(unsigned long long int i=1;i<=k;i++)
		{
			divisor=gcd(ans,i);
			ans/=divisor;
			ans*=(n-i+1)/(i/divisor);
		}
		cout<<ans<<endl;
	}
	return 0;
}