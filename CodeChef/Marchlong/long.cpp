#include <bits/stdc++.h>
using namespace std;
long long int i,t,x,y,k,n,p[100002],c[100002];
int main(int argc, char const *argv[])
{
	cin>>t;
	while(t--)
	{
		cin>>x>>y>>k>>n;
		int f=0;
		for(i=0;i<n;i++)
		{
			cin>>p[i]>>c[i];
		}
		for(i=0;i<n;i++)
		{
			if(c[i]<=k && p[i]>=x-y)
			{
				f=1;
				cout<<"LuckyChef"<<endl;
				break;				
			}
		}
		if(f==0)
			cout<<"UnluckyChef"<<endl;

	}
	return 0;
}