#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli n,k,p,flag[100005],l,r,num;
int main(int argc, char const *argv[])
{
	scanf("%lld %lld %lld",&n,&k,&p);
	vector< pair< lli,lli > >pr;
	for(lli i=0;i<n;i++)
	{
		scanf("%lld",&num);
		pr.push_back(make_pair(num,i));
	}
	sort(pr.begin(),pr.end());
	lli cnt=1;
	for(lli i=n-1;i>0;i--)
	{
		if((pr[i].first - pr[i-1].first)<=k)
			flag[pr[i].second]=cnt;
		else
		{
			flag[pr[i].second]=cnt;
			cnt++;
		}
	}
	flag[pr[0].second]=cnt;
	// for(lli i=0;i<n;i++)
	// 	printf("%lld ",flag[i]);
	// printf("\n");
	while(p--)
	{
		scanf("%lld %lld",&l,&r);
		l--,r--;
		if(flag[l]==flag[r])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}	