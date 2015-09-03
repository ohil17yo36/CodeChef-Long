#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli t,num;
int main(int argc, char const *argv[])
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&num);
		if(num==1)
			printf("2\n");
		else
		{
			if((num&(num+1))==0)
				printf("%lld\n",(lli)(1<<(lli)((log(num+1)/log(2))-1))-1);
			else
				printf("-1\n");
		}
	}
	return 0;
}