#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mod 1000000007
lli t,n,k,l,a[19],b[20],ans;
void generate(lli pos,lli cnt)
{
	if(pos==n)
	{
		
	}
	if(cnt<k)
	{
		b[pos]=cnt++;
		if(pos<n)
			generate(pos+1,0);
		generate(pos,cnt);
	}
}	
int main(int argc, char const *argv[])
{
	scanf("%lld",&t);
	while(t--)
	{
		ans=0;
		scanf("%lld %lld %lld",&n,&k,&l);
		for(lli i=0;i<n;i++)
			scanf("%lld",&a[i]);
		generate(0,0);
	}
	return 0;
}