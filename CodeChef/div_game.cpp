#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int f(lli n)
{
	if(n==2)
		return 1;
	if(n==17)
		return 1;
	if(n==16)
		return 0;
	if(n==34)
		return 0;
	if(n==289)
		return 0;
	if(n%2==0)
		return 1;
	for(lli i=3;(i*i)<n;i+=2)
	{
		if(n%i==0)
			return 1;
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	lli t,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(f(n)==1)
			printf("Mike\n");
		else
			printf("Tom\n");
	}
	return 0;
}