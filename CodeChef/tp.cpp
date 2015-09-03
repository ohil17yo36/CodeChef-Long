#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	char str[35];
	std::map<string, int> mp;
	scanf("%s",str);
	string str2(str);
	mp[str2]=5;
	string str3(str);
	printf("%d\n",mp[str3] );
	return 0;
}	