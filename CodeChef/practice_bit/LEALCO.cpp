#include <bits/stdc++.h>
using namespace std;
#define lli long long int
bool arrest(int *R,int m,int n,int k)
{
	
	for(int i=0;i<=n-k;i++)
	{	
		int maxx=-1,maxxcnt=0;
		for(int j=i;j<i+k;j++)
			maxx=max(maxx,R[j]);
		for(int j=i;j<i+k;j++)
			if(R[j]==maxx)
				maxxcnt++;
		if(maxxcnt>=m)
			return true;
	}
	return false;
}
int main(int argc, char const *argv[])
{
	int t,n,m,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&k,&m);
		int r[n],R[n],ans=50;
		for (int i = 0; i < n; ++i)
			scanf("%d",&r[i]);
		for(lli mask=0;mask<((1<<n)-1);mask++)
		{
			int bit_set_cnt=0;
			for(int i=0;i<n;i++)
			{
				R[i]=r[i];
				if(mask & (1<<i))
					R[i]++,bit_set_cnt++;
			}
			if(!arrest(R,m,n,k))
				ans=min(ans,bit_set_cnt);
		}
		if(ans==50)
			ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}