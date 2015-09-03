#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define lli long double
lli p[20][10020],numerator,denominator,ans,product;
int t,n,m;
int main(int argc, char const *argv[])
{
	ifstream fin;
	ofstream fout;
	fin.open("inp.txt");
	fout.open("Gbf.txt");
	// scanf("%d",&t);
	fin>>t;
	while(t--)
	{
		numerator=1,denominator=0;
		// scanf("%d %d",&n,&m);
		fin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			product=1;
			for(int j=1;j<=m;j++)
			{
				fin>>p[i][j];
				// scanf("%Lf",&p[i][j]);
				product*=p[i][j];
			}
			denominator+=product;
		}
		for(int j=1;j<=m;j++)
			numerator*=p[1][j];
		if(denominator==0)
		{
			fout<<0.000000<<endl;
			continue;
		}
		printf("%Lf\n",numerator/denominator);
		fout<<numerator/denominator<<endl;
	}
	return 0;
}