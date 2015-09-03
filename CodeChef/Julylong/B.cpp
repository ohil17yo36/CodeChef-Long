#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli num,n,temp,lastDigit,trzcnt,arr[21];
int main(int argc, char const *argv[])
{
	arr[0]=1;
	arr[1]=10;
	scanf("%lld",&n);
	for(lli i=2;i<=18;i++)
		arr[i]=(10*arr[i-1]);
	while(n--)
	{
		trzcnt=0;
		scanf("%lld",&num);
		while(1)
		{
			temp=num/arr[trzcnt];
			while(temp%10==0)
				temp/=10,trzcnt++;
			lastDigit=temp%10;
			if(lastDigit!=5)
				break;
			num*=4;
		}
		printf("%lld\n",num);
	}
	return 0;
}