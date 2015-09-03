#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli t;
int cube[7];
char str[10];
int main(int argc, char const *argv[])
{
	scanf("%lld",&t);
	getchar();
	std::map<string, int> mp;
	mp["black"]=1;
	mp["blue"]=2;
	mp["red"]=3;
	mp["green"]=4;
	mp["yellow"]=5;
	mp["orange"]=6;
	while(t--)
	{
		int f=0;
		for(int i=1;i<=6;i++)
		{
			scanf("%s",str);
			string s(str);
			cube[i]=mp[s];
		}
		if(cube[1]==cube[3])
		{
			if(cube[1]==cube[5])
			{
				printf("YES\n");
				continue;
			}
			else if(cube[1]==cube[6])
			{
				printf("YES\n");
				continue;	
			}
		}
		else if(cube[1]==cube[4])
		{
			if(cube[1]==cube[5])
			{
				printf("YES\n");
				continue;
			}
			else if(cube[1]==cube[6])
			{
				printf("YES\n");
				continue;	
			}	
		}
		if(cube[2]==cube[3])
		{
			if(cube[2]==cube[5])
			{
				printf("YES\n");
				continue;
			}
			else if(cube[2]==cube[6])
			{
				printf("YES\n");
				continue;
			}
		}
		else if(cube[2]==cube[4])
		{
			if(cube[2]==cube[5])
			{
				printf("YES\n");
				continue;
			}
			else if(cube[2]==cube[6])
			{
				printf("YES\n");
				continue;
			}	
		}
		printf("NO\n");
	}
	return 0;
}