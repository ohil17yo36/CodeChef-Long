#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main(int argc, char const *argv[])
{
	lli t,n,k;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&k);
		lli a[n+1];
		for(lli i=0;i<n;i++)
			scanf("%lld",&a[i]);
		// a[n]=k;
		sort(a,a+n);
		for(lli i=0;i<(n)/2;i++)
			swap(a[i],a[n-i-1]);
		lli bit=1;
		while(bit<=a[0])
			bit=bit<<1;
		bit=bit>>1;
		lli t=0;
		for(;bit>=1;bit=(bit>>1))
		{
			lli i=t;
			while(i<(n) && (a[i]&bit)==0)
				i++;
			if(i>=n)
				continue;
			swap(a[i],a[t]);
			for(lli j=0;j<n;j++)
				if((a[j]&bit)!=0 && j!=t)
					a[j]^=a[t];
			t++;
		}
		lli res=k;
		for(lli i=0;i<n;i++)
			res=max(res,res^a[i]);
		printf("%lld\n",res );
	}
	return 0;
}