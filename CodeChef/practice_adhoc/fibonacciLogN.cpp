#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define lli long long int
lli K=2;
vector<vector<lli> >mult(vector<vector<lli> > A,vector<vector<lli> > B)
{
	vector<vector<lli> > ans(K+1,vector<lli>(K+1));
	for(lli i=1;i<=K;i++)
	{
		for(lli j=1;j<=K;j++)
		{
			for(lli k=1;k<=K;k++)
			{
				ans[i][j]=(ans[i][j]+A[i][k]*B[k][j])%mod;
			}
		}
	}
	return ans;
}
vector<vector<lli> > findTransform(vector<vector<lli> > T,lli n)
{
	if(n==1)
		return T;
	if(n%2)
		return mult(T,findTransform(T,n-1));
	else
	{
		vector<vector<lli> > X=findTransform(T,n/2);
		return mult(X,X);
	}	
}
int main()
{
	lli n;
	scanf("%lld",&n);
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	else
	{
		vector<lli> F1(K+1);
		F1[1]=0;
		F1[2]=1;
		vector<vector<lli> > T(K+1,vector<lli>(K+1));
		T[1][1]=0;
		T[1][2]=1;
		T[2][1]=1;
		T[2][2]=1;
		T=findTransform(T,n-1);
		lli ans=0;
		for(lli i=1;i<=K;i++)
		{
			ans=(ans+T[1][i]*F1[i])%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}