#include <bits/stdc++.h>
using namespace std;
#define lli long long int
inline lli scan( )
{
	register lli n = 0;
	register char c;
	for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
	for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
		n = (n * 10) + (c & 0x0f);
	return n;
}
std::vector<pair<lli,lli> > vec1;
std::vector<pair<lli,lli> > vec2;
lli res[300500];
int main(int argc, char const *argv[])
{
	lli N=scan(),weight,cost,sum=0;
	for(lli i=0;i<N;i++)
	{
		weight=scan();
		cost=scan();
		sum+=weight;
		if(weight==1)
			vec1.push_back(make_pair(weight,cost));
		else
			vec2.push_back(make_pair(weight,cost));
	}
	sort(vec1.begin(),vec1.end());
	sort(vec2.begin(),vec2.end());
	std::vector<pair<lli,lli> > temp1(vec1.begin(),vec1.end());
	std::vector<pair<lli,lli> > temp2(vec2.begin(),vec2.end());
	
		lli ans=0;
		for(lli i=2;i<=sum;i+=2)
		{
			lli cost_1=0,cost_2=0;
			if(vec2.size()>0)
				cost_1=vec2.back().second;
			int f=0;
			if(vec1.size()>1)
			{
				cost_2=vec1.back().second;
				cost_2+=vec1[vec1.size()-2].second;
			}
			else if(vec1.size()==1)
			{
				f=1;
				cost_2=vec1.back().second;
			}
			if(cost_1>cost_2)
			{
				ans+=vec2.back().second;				
				vec2.pop_back();
			}
			else
			{
				ans+=cost_2;
				if(f==0)
				{
					vec1.pop_back();
					vec1.pop_back();
				}
				else
				{
					vec1.pop_back();
				}
			}
		res[i]=ans;
		}
		
		ans=0;
		if(temp1.size()>0)
		{
			ans=temp1.back().second;
			temp1.pop_back();
		}
		res[1]=ans;
		for(lli i=3;i<=sum;i+=2)
		{
				lli cost_1=0,cost_2=0;
				if(temp2.size()>0)
					cost_1=temp2.back().second;
				int f=0;
				if(temp1.size()>1)
				{
					cost_2=temp1.back().second;
					cost_2+=temp1[temp1.size()-2].second;
				}
				else if(temp1.size()==1)
				{
					f=1;
					cost_2=temp1.back().second;
				}
				if(cost_1>cost_2)
				{	
					ans+=temp2.back().second;				
					temp2.pop_back();
				}
				else
				{
					ans+=cost_2;
					if(f==0)
					{
						temp1.pop_back();
						temp1.pop_back();
					}
					else
					{
						temp1.pop_back();
					}
				}
				res[i]=ans;
		}
				
		
	for(lli i=1;i<=sum;i++)
		printf("%lld ",res[i]);
	printf("\n");	
	
	return 0;
}	