#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli t,n,f,ht;
std::vector<lli> h;
std::pair<std::vector<lli>::iterator,std::vector<lli>::iterator> bounds;
int main(int argc, char const *argv[])
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&f);
		h.clear();
		for(lli i=0;i<n;i++)
		{
			scanf("%lld",&ht);
			h.push_back(ht);
		}
		lli cnt=0;
		sort(h.begin(),h.end());
		for(std::vector<lli>::size_type i=0;i<h.size();i++)
		{
			lli num=h[i];
			while(num)
			{
				bounds=std::equal_range (h.begin(), h.end(), num);
				cnt+=bounds.second - bounds.first;
				num/=f;
			}
		}
		printf("%lld\n",cnt );
	}
	return 0;
}