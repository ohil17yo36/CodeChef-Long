#include <bits/stdc++.h>
#define lli long long int
using namespace std;
char str[5005],ch;
int len;
lli func(void)
{
	lli noi[5005];
	noi[0]=1;
	noi[1]=1;
	for(int i=1;i<len;i++)
	{
		noi[i+1]=noi[i];
		if((str[i]-'0')==0)
		{
			noi[i+1]=noi[i-1];
			noi[i]=noi[i-1];
			continue;
		}
		if((10*(str[i-1]-'0')+(str[i]-'0'))<=26 && (str[i-1]-'0')!=0)
			noi[i+1]+=noi[i-1];
	}
	// for(int i=0;i<=len;i++)
	// 	printf("%lld\n",noi[i]);
	return noi[len];
}
int main(int argc, char const *argv[])
{
	while(1)
	{
		int i=0;
		while((ch=getchar_unlocked())!='\n')
			str[i++]=ch;
		len=i;
		if(len==1 && str[len-1]=='0')
			break;
		// func();
		printf("%lld\n",func());
	}
	return 0;
}