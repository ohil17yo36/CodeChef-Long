#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define lli long long int
lli n,k,a[100005],divisor,srt,div1,div2,ans,idxx,storeidxx;
vector<lli> v[100005];
stack<lli> st;
int main(int argc, char const *argv[])
{
	ofstream fout;
	ifstream fin;
	fin.open("inp.txt");
	fout.open("out.txt");
	scanf("%lld %lld",&n,&k);
	// fin>>n>>k;
	for(lli i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		// fin>>a[i];
		v[a[i]].push_back(i);
	}	
	for(lli i=0;i<n;i++)
	{
		if(a[i]>k)
		{
			divisor=a[i]-k;
			srt=(lli)sqrt(divisor);
			for(lli j=1;j<=srt;j++)
			{
				if(divisor%j==0)
				{
					div1=j;
					div2=divisor/j;
					if(div1>k && v[div1].size()>0)
					{
						vector<lli>::iterator it=upper_bound(v[div1].begin(),v[div1].end(),i);
						if(it!=v[div1].end())
						{
							ans+=(n-*it);
						}
					}
					if(div2>k && v[div2].size()>0 && div2!=div1)
					{
						std::vector<lli>::iterator it=upper_bound(v[div2].begin(),v[div2].end(),i);
						
						if(it!=v[div2].end())
						{
							ans+=(n-*it);
						}

					}
				}
			}
		}
		else if(a[i]==k)
		{
			
		}
		else
		{
			ans+=(n-i);
		}
	}
	fout<<ans<<endl;
	// printf("%lld\n",ans);
	return 0;
}	