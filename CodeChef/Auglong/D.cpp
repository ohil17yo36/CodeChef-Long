#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli t,n,ans,fn,fn_1,sum,temp;
int main(int argc, char const *argv[])
{
	scanf("%llu",&t);
	while(t--)
	{
		scanf("%lld",&n);
		fn_1=0;
		fn=1;
		ans=0;
		sum=0;
		while(sum<n)
		{
			sum+=fn;
			temp=fn_1;
			fn_1=fn;
			fn=fn+temp;
			ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}