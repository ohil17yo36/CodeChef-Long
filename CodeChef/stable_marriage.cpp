#include <bits/stdc++.h>
using namespace std;
inline int scan( )
{
int n1 = 0;
char c;
for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
n1 = (n1 * 10) + (c & 0x0f);
return n1;
}
int main(int argc, char const *argv[])
{
	int tp,t,n;
	t=scan();
	while(t--)
	{
		n=scan();
		int men_choice[n][n];
		int women_choice[n][n];
		for (int i = 0; i < n; ++i)
		{
			tp=scan();
			for(int j=0;j<n;j++)
				women_choice[i][j]=scan(),women_choice[i][j]--;	
		}
		for (int i = 0; i < n; ++i)
		{
			tp=scan();
			for(int j=0;j<n;j++)
				men_choice[i][j]=scan(),men_choice[i][j]--;	
		}
		int womens_man[n];
		bool man_single[n];
		memset(womens_man,-1,sizeof(womens_man));
		memset(man_single,true,sizeof(man_single));
		int married_cnt=0;

		while(married_cnt<n)
		{
			int free_man;
			for(int i=0;i<n;i++)
				if(man_single[i])
				{
					free_man=i;
					break;
				}
			
			for(int i=0;i<n && man_single[free_man]==true;i++)
			{
				int woman=men_choice[free_man][i];
				if(womens_man[woman]==-1)
				{
					married_cnt++;
					man_single[free_man]=false;
					womens_man[woman]=free_man;
				}
				else
				{
					int curr_man=womens_man[woman];
					for(int j=0;j<n;j++)
					{
						if(women_choice[woman][j]==free_man)
						{
							womens_man[woman]=free_man;
							man_single[free_man]=false;
							man_single[curr_man]=true;
							break;
						}
						if(women_choice[woman][j]==curr_man)
							break;
					}
				}	
			}		
		}
		std::vector<pair<int ,int> > v;
		for(int i=0;i<n;i++)
			v.push_back(make_pair(womens_man[i]+1,i+1));
		sort(v.begin(),v.end());
		for (int i = 0; i < n; ++i)
			printf("%d %d\n",v[i].first,v[i].second);
	}
	return 0;
}	