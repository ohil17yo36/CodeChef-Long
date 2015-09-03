#include <bits/stdc++.h>
using namespace std;
#define lli long long int

char a[20],b[20],A[20],B[20],cntA[26],cntB[26];
int main(int argc, char const *argv[])
{
	lli t;
	scanf("%lld",&t);
	while(t--)
	{
		lli len;
		scanf("%lld",&len);
		getchar();
		scanf("%s",a);
		scanf("%s",b);
		lli limit=(1<<len);
		lli minn=(1<<20);
		for(lli i=0;i<limit;i++)
		{
			// printf("HEllo\n");
			for(lli j=0;j<len;j++)
			{
				A[j]=a[j];
				B[j]=b[j];
			}
			for(lli j=0;j<len;j++)
			{
				if(i & (1<<j))
				{
					swap(A[j],B[j]);
				}
			}
			lli cnt1=0,cnt2=0;
			for(lli j=0;j<len;j++)
			{
				if(cntA[A[j]-'a']==0)
				{
					cntA[A[j]-'a']=1;
					cnt1++;
				}
				if(cntB[B[j]-'a']==0)
				{
					cntB[B[j]-'a']=1;
					cnt2++;
				}
			}
			minn=min(minn,max(cnt1,cnt2));
			for(lli j=0;j<26;j++)
			{
				cntA[j]=0;
				cntB[j]=0;
			}
		}
		printf("%lld\n",minn );
	}
	return 0;
}