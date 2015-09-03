#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli n,x,num;
std::vector<lli> v;
int main(int argc, char const *argv[])
{
	scanf("%lld",&n);
	v.clear();
	for(lli i=0;i<n;i++)
	{
		scanf("%lld",&num);
		v.push_back(num);
	}
	scanf("%lld",&x);
	sort(v.begin(),v.end());
	for(lli i=0;i<n;i++)
	{
		for(lli j=i+1;j<n;j++)
		{
			if(v[i]+v[j]<x)
			{
				if(binary_search(v.begin()+j+1,v.end(),x-v[i]-v[j]))
				{	
					printf("True");
					return 0;
				}
			}
		}
	}
	printf("False");
	return 0;
}