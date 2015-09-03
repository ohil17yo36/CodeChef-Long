#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli n,f,b,fd,bd,t;
int main(int argc, char const *argv[])
{
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld %lld %lld %lld %lld",&f,&b,&t,&fd,&bd);
		lli netpos=0;
		if(f==b)
		{
			if(fd<=f)
				printf("%lld\n",fd*t );
			else
				printf("No Ditch\n");
		}
		else if(f>b)
		{
			int dir=1;
			lli ans=0;
			while(netpos<fd)
			{
				if(dir==1)
				{
					dir=2;
					netpos+=f;
					ans+=t*f;
				}
				else
				{
					dir=1;
					netpos-=b;
					ans+=t*b;
				}
			}
			netpos-=f;
			ans-=t*f;
		}
	}
	return 0;
}	