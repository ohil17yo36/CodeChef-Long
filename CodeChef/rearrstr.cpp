#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli t,cnt,len,a[26];
char str[100005],ch;
std::vector<pair<lli,char> > v;
int main(int argc, char const *argv[])
{
	scanf("%lld",&t);
		getchar();	
	while(t--)
	{

		memset(a,0,sizeof(a));
		scanf("%s",str);
		// printf("printing %s\n",str );	
		len=strlen(str);
		v.clear();
		for(lli i=0;i<len;i++)
			a[str[i]-'a']++;
		for(lli i=0;i<26;i++)
			v.push_back(make_pair(a[i],i+'a'));
		sort(v.begin(),v.end());
		for(lli i=0;i<13;i++)
			swap(v[i],v[26-i-1]);
		lli pos=0;
		for(lli i=0;i<v.size();i++)
		{
			lli times=v[i].first;
			while(times>0)
			{
				str[pos]=v[i].second;
				pos+=2;
				times--;
				if(pos>=len)
					pos=1;
			}
		}
		str[len]='\0';
		bool ok=true;
		for(lli i=1;i<len;i++)
		{
			if(str[i]==str[i-1])
				ok=false;
		}
		if(ok)
			printf("%s\n",str );
		else
			printf("-1\n");
	}
	return 0;
}