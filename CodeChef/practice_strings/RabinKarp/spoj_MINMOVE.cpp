#include <bits/stdc++.h>
using namespace std;
#define lli long long int
char text[100000],pattern[100000],ch;
lli idx,n,m,q,d,h,patternNum,textNum;
//d->size of alphabet space..if a-z then d=26
//q->set to some large prime
lli power(lli base,lli exponent,lli mod)
{
	if(exponent==0)
		return 1;
	lli x=power(base,exponent>>1,mod);
	if(exponent%2==0)
		return ((x%mod)*(x%mod))%mod;
	else
		return ((base%mod)*((((x%mod)*(x%mod))%mod)%mod))%mod;
}
void rabinKarp()
{
	q=1000000007,d=26;
	h=power(d,m-1,q);
	textNum=0;
	for(lli i=1;i<=m;i++)
		textNum=(d*textNum+text[i])%q;
	lli minn=textNum,minpos=1;
	for(lli shift=0;shift<=(n-m);shift++)
	{
		printf("shift=%lld textNum=%lld\n",shift,textNum);
		if(minn>textNum)
		{
			minn=textNum;
			minpos=shift;
		}
		if(shift<(n-m))
			textNum=(d*(textNum-h*text[shift+1])+text[shift+m+1])%q;
		if(textNum<0)
			textNum+=q;
	}

	printf("%lld\n",minpos+1);
}
int main(int argc, char const *argv[])
{
	idx=1;
	while((ch=getchar_unlocked())!='\n')
		text[idx++]=ch,pattern[idx-1]=ch-'a';
	n=idx-1;
	for(lli i=1;i<=n;i++)
	{
		text[i]-='a';
		text[i+n]=text[i];
	}
	m=n;
	n=(n<<1);
	text[n+1]='\0';
	for(lli i=1;i<=n;i++)
		printf("%c",text[i]+'a');
	printf("\n");
	rabinKarp();
	return 0;
}