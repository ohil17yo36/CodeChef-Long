#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli a[100005],n,k,i,j,ans;
int main(int argc, char const *argv[])
{
	ofstream fout;
	ifstream fin;
	fin.open("inp.txt");
	fout.open("outbf.txt");
	fin>>n>>k;
	// scanf("%lld %lld",&n,&k);
	for(lli i=0;i<n;i++)
		fin>>a[i];// scanf("%lld",&a[i]);
	for(lli i=0;i<n;i++)
	{
		for(lli j=i;j<n;j++)
		{
			int f=0;
			for(lli K=i;K<j;K++)
			{
				for(lli l=K+1;l<=j;l++)
				{
					if(a[K]%a[l]==k)
					{
						f=1;
						break;
					}
				}
				if(f)
					break;
			}
			if(!f)
				/*printf("%lld %lld\n",i,j),*/ans++;
		}
	}
	fout<<ans<<endl;
	// printf("%lld\n",ans);
	return 0;
}