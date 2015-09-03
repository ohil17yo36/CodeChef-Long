#include <bits/stdc++.h>
using namespace std;
#define lli long long int
std::vector<lli> prime_factors[1000006];
lli a[1000005],dp[1000005],last_dividing_index[1000006];
inline lli scan( )
{
	lli n = 0;
	char c;
	for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
	for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
		n = (n * 10) + (c & 0x0f);
	return n;
}
int main(int argc, char const *argv[])
{
	for (lli i = 2; i < 1000006; ++i)
	{
		if(prime_factors[i].size()==0)
		{
			for(lli j=i;j<1000006;j+=i)
				prime_factors[j].push_back(i);
		}	
	}
	lli t,n,maxx=-1;
	t=scan();
	while(t--)
	{	
		maxx=-1;
		n=scan();
		for(lli i=0;i<1000006;i++)
			last_dividing_index[i]=dp[i]=-1;
		for(lli i=0;i<n;i++)
		{	
			a[i]=scan();
			lli last_div=-1;
			for (lli j=0;j<prime_factors[a[i]].size();j++)
			{
				if(last_dividing_index[prime_factors[a[i]][j]]!=-1)
					last_div=max(last_div,last_dividing_index[prime_factors[a[i]][j]]);
				last_dividing_index[prime_factors[a[i]][j]]=i;
			}

			if(i>0)
			{
				dp[i]=max(dp[i-1],last_div);
				maxx=max(maxx,i-dp[i]);
			}
		}
		if(maxx==1)
			printf("-1\n");
		else
			printf("%lld\n",maxx);
	}
	return 0;
}