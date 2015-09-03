#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli pa[1000000];
lli pb[1000000];
lli a,b;
int main(int argc, char const *argv[])
{
	lli ttnum=0;
	while(1)
	{
		ttnum++;
		memset(pa,0,sizeof(pa));
		memset(pb,0,sizeof(pb));
		scanf("%lld %lld",&a,&b);
		if(a==0 && b==0)
			return 0;
		lli temp=a;
		while(temp%2==0)
		{
			pa[2]++;
			temp/=2;
		}
		for(lli i=3;i<=sqrt(temp);i++)
		{
			while(temp%i==0)
			{
				pa[i]++;
				temp/=i;
			}
		}
		if(temp>2)
			pa[temp]++;
		temp=b;
		while(temp%2==0)
		{
			pb[2]++;
			temp/=2;
		}
		for(lli i=3;i<=sqrt(temp);i++)
		{
			while(temp%i==0)
			{
				pb[i]++;
				temp/=i;
			}
		}
		if(temp>2)
			pb[temp]++;
		lli cnt=0;
		for(lli i=0;i<a;i++)
			if(pa[i]>0)
				cnt++;
		lli sum=0;
		for(lli i=0;i<max(a,b);i++)
			if(pa[i]>0 || pb[i]>0)
				cnt++,sum+=((lli)abs(pa[i]-pb[i]));
		printf("%lld. %lld:%lld\n",ttnum,cnt,sum);	
	}

	return 0;
}