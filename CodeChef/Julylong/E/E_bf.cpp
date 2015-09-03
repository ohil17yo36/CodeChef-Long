#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define lli long long int
#define mod 1000000007
lli n,q,a[100005],x,y,v,chc,sum;
int main(int argc, char const *argv[])
{
	ifstream fin;
	ofstream fout;
	fin.open("inp.txt");
	fout.open("outbf.txt");
	// scanf("%lld %lld",&n,&q);
	fin>>n>>q;
	for(lli i=0;i<n;i++)
		fin>>a[i];// scanf("%lld",&a[i]);
	while(q--)
	{
		// scanf("%lld %lld %lld",&chc,&x,&y);
		fin>>chc>>x>>y;
		// x--,y--;
		if(chc!=4)
			fin>>v;// scanf("%lld",&v);
		if(chc==1)
		{
			for(lli i=x;i<=y;i++)
			{
				a[i]+=v;
				if(a[i]>=mod)
					a[i]=a[i]%mod;
			}
		}
		else if(chc==2)
		{
			for(lli i=x;i<=y;i++)
			{
				a[i]*=v;
				if(a[i]>=mod)
					a[i]=a[i]%mod;
			}
		}
		else if(chc==3)
		{
			for(lli i=x;i<=y;i++)
			{
				a[i]=v;
				if(a[i]>=mod)
					a[i]=a[i]%mod;
			}
		}
		else if(chc==4)
		{
			sum=0;
			for(lli i=x;i<=y;i++)
			{
				sum+=a[i];
				if(sum>=mod)
					sum=sum%mod;
			}
			fout<<sum<<endl;
		}
	}
	return 0;
}