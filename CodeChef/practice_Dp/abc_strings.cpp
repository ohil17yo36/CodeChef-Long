#include <bits/stdc++.h>
using namespace std;
#define lli long long int
char str[1000005],ch;
int main(int argc, char const *argv[])
{
	lli i=0,len;
	while((ch=getchar())!='\n')
		str[i++]=ch;
	len=i;
	lli a_cnt=0,b_cnt=0,c_cnt=0,ans=0;
	std::map<pair<int,int>, int> mp;
	mp[make_pair(0,0)]++;
	for(lli i=0;i<len;i++)
	{
		if(str[i]=='A')
			a_cnt++;
		else if(str[i]=='B')
			b_cnt++;
		else 
			c_cnt++;
		ans+=mp[make_pair(a_cnt-b_cnt,a_cnt-c_cnt)];
		// printf("pair %lld %lld %lld\n",a_cnt-b_cnt,a_cnt-c_cnt,ans);
		mp[make_pair(a_cnt-b_cnt,a_cnt-c_cnt)]++;
		
	}
	printf("%lld\n",ans);
	return 0;
}