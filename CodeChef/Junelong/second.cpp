#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli x[100005],y[100005],t,n,m;
long double area;
std::vector<pair <long double,lli> > v;
std::vector<pair <lli,lli> > v2;
int main(int argc, char const *argv[])
{
	scanf("%lld",&t);
	while(t--)
	{
		v.clear(),v2.clear();
		scanf("%lld",&n);
		for(lli i=0;i<n;i++)
		{
			scanf("%lld",&m);
			area=0;
			for(lli j=1;j<=m;j++)
				scanf("%lld %lld",&x[j],&y[j]);
			for(lli j=1;j<m;j++)
				area+=(x[j]*y[j+1] - y[j]*x[j+1]);
			area+=(x[m]*y[1] - y[m]*x[1]);
			area=abs(area/2);
			v.push_back(make_pair(area,i));
		}
		sort(v.rbegin(),v.rend());
		for(lli i=0;i<n;i++)
			v2.push_back(make_pair(v[i].second,n-i-1));
		sort(v2.begin(),v2.end());
		for(lli i=0;i<n;i++)
			printf("%lld ",v2[i].second);
		printf("\n");
	}
	return 0;
}