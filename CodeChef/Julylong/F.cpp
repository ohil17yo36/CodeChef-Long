#include <bits/stdc++.h>
using namespace std;
#define lli long double
long long int t,no,p,m,b,n;
lli r1,r2,r3,r4,k1,k2,k3,k4,temp1,temp2,ans,sum;
int main(int argc, char const *argv[])
{
	scanf("%lld",&t);
	scanf("%lld %lld %lld %lld",&no,&p,&m,&b);
	scanf("%Lf %Lf %Lf %Lf",&r1,&r2,&r3,&r4);
	n=no;
	k1=((-1)/r1),k2=(1/r2),k3=(1/r3),k4=(1/r4);
	temp1=(k4-k3);
	temp2=(k1+k2);
	sum=0;
	while(t--)
	{
		n=(((p%m)*(n%m))%m);
		n+=b;
		if(n<5)
		{
			if(n==1)
				sum+=r1;
			else if(n==2)
				sum+=r2;
			else if(n==3)
				sum+=r3;
			else
				sum+=r4;
		}
		else
		{
			ans=(k4 + (n-4)*(temp1 + (n-3)*(temp2)));
			ans=(1/ans);
			sum+=ans;
		}
	}
	printf("%Lf\n",sum);
	return 0;
}