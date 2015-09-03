#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define lli long long int
#define mod 1000000007
lli n=2,m=10001,sum,t=1;
long double a[20][100005];
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	ofstream fout;
	fout.open("inp.txt");
	fout<<t<<endl;
	while(t--)
	{
		// n=rand()%5+1;
		// m=rand()%5+1;
		fout<<n<<" "<<m<<endl;
		for(int i=1;i<=n;i++)
		{
			if(i==1)
			{
				for(int j=1;j<=m-1;j++)
				{
					a[i][j]=0.0001;
				}
				a[i][m]=1.0000;
			}
			else
			{
				for(int j=1;j<=m;j++)
				{
					a[i][j]=0.9999;
				}
				a[i][m]=0.00000;
			}	
		}
		// for(int j=1;j<=m;j++)
		// {
		// 	sum=0;
		// 	for(int i=1;i<=n;i++)
		// 	{
		// 		sum+=a[i][j];
		// 	}
		// 	if(sum==0)
		// 	{
		// 		j--;
		// 		continue;
		// 	}
		// 	for(int i=1;i<=n;i++)
		// 	{
		// 		a[i][j]/=sum;
		// 	}
		// }
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				fout<<a[i][j]<<" ";
			}
			fout<<endl;
		}
	}	
	return 0;
}