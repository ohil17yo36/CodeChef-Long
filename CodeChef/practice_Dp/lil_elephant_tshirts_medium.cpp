#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
std::vector<int> tshirt[5];
ll mask_limit;
ll dp[(1<<10)][103];
ll func(ll mask,ll shirt_id)
{
	if(shirt_id==5)
	{
		if(mask==mask_limit)
			return dp[mask][shirt_id]=1;
		else
			return dp[mask][shirt_id]=0;
	}
	if(dp[mask][shirt_id]!=-1)
		return dp[mask][shirt_id];
	ll ans=0;
	ans+=func(mask,shirt_id+1);
	if(ans>=mod)
		ans%=mod;
	for(ll i=0;i<(ll)tshirt[shirt_id].size();i++)
	{
		if(mask & (1<<(tshirt[shirt_id][i])))
			continue;
		else
			ans+=func(mask|(1<<(tshirt[shirt_id][i])),shirt_id+1);
		if(ans>=mod)
			ans%=mod;
	}
	return dp[mask][shirt_id]=ans;
}
int main(int argc, char const *argv[])
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		scanf("%d",&n);
		mask_limit=(1<<n)-1;
		getchar();
		for (int i = 0; i < 101; ++i)
			tshirt[i].clear();
		for (int i = 0; i <n; ++i)
		{
			int j=0,len;
			char ch,str[5000],num[30];
			while((ch=getchar())!='\n')
				str[j++]=ch;
			str[j++]=' ';
			str[j]='\0';
			len=j;
			int start=0,end,k,l;
			for(j=0;j<len;j++)
			{
				if(str[j]==' ')
				{
					end=j-1;
					for(k=start,l=0;k<=end;k++,l++)
						num[l]=str[k];
					num[l]='\0';
					int temp=atoi(num);
					// printf("%d\n",temp );
					tshirt[temp].push_back(i);
					start=j+1;
				}
			}	
		}
		// for(int i=0;i<101;i++)
		// 	sort(tshirt[i].begin(),tshirt[i].end());
		printf("%lld\n",func(0,1));
		for(ll i=0;i<(1<<n);i++)
		{
			for(ll j=1;j<6;j++)
				printf("%lld ",dp[i][j]);
			printf("\n");
		}
	}
	return 0;
}	