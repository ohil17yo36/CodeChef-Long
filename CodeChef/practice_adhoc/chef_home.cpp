#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main(int argc, char const *argv[])
{
	lli t,n,x,y;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		lli x_arr[n],y_arr[n];
		for(lli i=0;i<n;i++)
			scanf("%lld %lld",&x_arr[i],&y_arr[i]);
		if(n%2!=0)
			printf("1\n");
		else
		{
			sort(x_arr,x_arr+n);
			sort(y_arr,y_arr+n);
			printf("%lld\n",(x_arr[n/2]-x_arr[n/2-1]+1)*(y_arr[n/2]-y_arr[n/2-1]+1));
		}
	}
	return 0;
}