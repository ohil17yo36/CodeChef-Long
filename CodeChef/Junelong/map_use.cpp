#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	std::map<pair<int,int>,int> mp;
	mp[make_pair(2,3)]=4;
	mp[make_pair(5,6)]=7;
	for(map<pair<int,int>,int>::iterator it=mp.begin();it!=mp.end();it++)
	{
		printf("%d\n",(*it).second );
	}
	return 0;
}