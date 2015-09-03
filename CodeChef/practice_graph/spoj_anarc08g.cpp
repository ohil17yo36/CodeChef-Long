#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main(int argc, char const *argv[])
{
	int n,sum1,sum2,tt=0;
	scanf("%d",&n);
	while(n!=0)
	{
		tt++;
		sum1=0,sum2=0;
		for(int i=0;i<n;i++ )
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]),sum1+=a[i][j];
		for(int i=0;i<n;i++)
		{
			int insum=0;
			int outsum=0;
			for(int j=0;j<n;j++)
				outsum+=a[i][j];
			for(int j=0;j<n;j++)
				insum+=a[j][i];
			if(outsum>=insum)
				sum2+=outsum-insum;
		}	
		printf("%d. %d %d\n",tt,sum1,sum2 );
		scanf("%d",&n);	
	}
	return 0;
}