#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define lli long double
int t,n,m,zerorow[20];
lli p[20][10020],ans,x[20],denomLogSum,numerLogSum;
int main(int argc, char const *argv[])
{
	// ifstream fin;
	// ofstream fout;
	// fin.open("inp.txt");
	// fout.open("G.txt");
	scanf("%d",&t);
	// fin>>t;
	while(t--)
	{
		denomLogSum=0,numerLogSum=0;
		scanf("%d %d",&n,&m);
		// fin>>n>>m;

		for(int i=1;i<=n;i++)
		{
			zerorow[i]=0;
			for(int j=1;j<=m;j++)
			{
				// fin>>p[i][j];

				scanf("%Lf",&p[i][j]);
				p[i][j]*=10000;
				if(p[i][j]==0)
					zerorow[i]=1;
			}
		}
		if(zerorow[1]==1)
		{
			// fout<<0.000000<<endl;
			printf("0.000000\n");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(zerorow[i]==1)
				continue;
			x[i]=0;
			for(int j=1;j<=m;j++)
			{
				x[i]+=log10(p[i][j]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(zerorow[i]==1)
				continue;
			denomLogSum+=pow(10,x[i]);
		}
		denomLogSum=log10(denomLogSum);
		for(int j=1;j<=m;j++)
			numerLogSum+=log10(p[1][j]);
		ans=numerLogSum-denomLogSum;
		printf("%.6Lf\n",pow(10,ans));
		// fout<<pow(10,ans)<<endl;
	}
	return 0;
}