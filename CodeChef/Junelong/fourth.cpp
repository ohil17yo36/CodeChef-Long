#include <bits/stdc++.h>
using namespace std;
#define lli long double
lli t1,t2,T1,T2,ans;
long long int t;
int main(int argc, char const *argv[])
{	
	scanf("%lld",&t);
	while(t--)
	{
	
		scanf("%Lf %Lf %Lf %Lf",&T1,&T2,&t1,&t2);
		if(T1>T2)
		{
			swap(T1,T2);
			swap(t1,t2);
		}	
			if(t1<T2)
			{
				if(t2<T1)
				{
					if((T1+t1)>=T2)
						ans=( ((T1*T2) - (((T1-t2)*(T1-t2))/2) - (((T2-t1)*(T2-t1))/2) )/(T1*T2) );
					else
						ans=( (((T1+t1)*(T1)) - (((T1-t2)*(T1-t2))/2) - ((T1*T1)/2) )/(T1*T2) );
				}
				else
				{
					if((T1+t1)>=T2)
						ans=( ((T1*T2) - (((T2-t1)*(T2-t1))/2) )/(T1*T2) );
					else
						ans=((((T1+t1)*(T1)) - ((T1*T1)/2))/(T1*T2));
				}
			}
			else
			{
				if(t2<T1)
					ans=(((T1*T2) - (((T1-t2)*(T1-t2))/2) )/(T1*T2));
				else
					ans=1;
			}
		
		printf("%.12Lf\n",ans);	
	}
	return 0;
}	