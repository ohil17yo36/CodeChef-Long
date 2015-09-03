#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli n,k,num;
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&k);
		lli sum=0;
		for(lli i=0;i<n;i++)
			scanf("%lld",&num),sum+=num;
		if(k==1)
		{
			if(sum%2==0)
				printf("odd\n");
			else
				printf("even\n");
		}
		else
			printf("even\n");
	}
	return 0;
}