#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
lli n,k,t,num;
int main(int argc, char const *argv[])
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&k);
		lli cnt=0,tmp;
		for(lli i=0;i<n;i++)
		{	scanf("%lld",&num);
			if(num<k)
				cnt+=(k-num);
			else
			{
				tmp=num%k;
				cnt+=min(tmp,k-tmp);
			}
		}
		printf("%lld\n",cnt );
	}
	return 0;
}