#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define lli long long int
lli range[1000006],n,l,r,h;
int main(int argc, char const *argv[])
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("outbf.txt");
	int t;
	fin>>t;
	// scanf("%d",&t);
	while(t--)
	{	

		fin>>n>>h;
		
		// scanf("%lld %lld",&n,&h);
		for(lli i=0;i<n;i++)
		{
			fin>>l>>r;
			// scanf("%lld %lld",&l,&r);
			for(lli j=0;j<l;j++)
				range[j]++;
			for(lli j=r+1;j<n;j++)
				range[j]++;
		}
		
		// printf("Hello\n");
		// for(lli i=0;i<n;i++)
		// 	fout<<range[i]<<endl,range[i]=0;// printf("%lld\n",range[i]);
	}
	return 0;
}