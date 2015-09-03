#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli n,sd,len;
std::vector<pair<lli,lli> > v;
template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second < b.second;
    }
};
int main(int argc, char const *argv[])
{
	scanf("%lld",&n);
	for(lli i=0;i<n;i++)
	{
		scanf("%lld %lld",&sd,&len);
		v.push_back(make_pair(sd,sd+len-1));
	}
	sort(v.begin(),v.end(),less_second<lli,lli>());
	pair<lli,lli> temp=v[0];
	lli cnt=1;
	for(lli i=1;i<n;i++)
	{
		if((v[i].first-temp.second)>=2)
		{
			temp=v[i];
			cnt++;
		}	
	}
	printf("%lld\n",cnt);
	return 0;
}