#include <bits/stdc++.h>
#define lli long long int 
using namespace std;
lli T[32]={1,0,3,0},F[32]={0,1,0,4};
int main(int argc, char const *argv[])
{
	
	for(lli i=4;i<32;i++)
	{
		T[i]=3*T[i-2]+2*F[i-3];
		F[i]=T[i-1]+F[i-2];
	}
	while(1)
	{
		lli n;
		scanf("%lld",&n);
		if(n==-1)
			break;
		else
			printf("%lld\n",T[n]);
	}
	return 0;
}