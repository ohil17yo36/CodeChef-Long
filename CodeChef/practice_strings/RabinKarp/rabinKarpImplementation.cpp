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
	q=101,d=26;
	h=power(d,m-1,q);
	patternNum=0;
	textNum=0;
	for(lli i=1;i<=m;i++)
	{
		patternNum=(d*patternNum+pattern[i])%q;
		textNum=(d*textNum+text[i])%q;
	}
	for(lli shift=0;shift<=(n-m);shift++)
	{
		if(patternNum==textNum)
		{
			lli flag=0;
			for(lli i=1;i<=m;i++)
			{
				if(pattern[i]!=text[shift+i])
				{
					flag=1;
					break;
				}
			}
			if(!flag)
				printf("Pattern has been found at %lld\n",shift+1);
		}
		if(shift<(n-m))
			textNum=(d*(textNum-h*text[shift+1])+text[shift+m+1])%q;
	}
}
int main(int argc, char const *argv[])
{
	idx=1;
	while((ch=getchar_unlocked())!='\n')
		text[idx++]=ch-'a';
	text[idx]='\0';
	n=idx-1;
	
	idx=1;
	while((ch=getchar_unlocked())!='\n')
		pattern[idx++]=ch-'a';
	pattern[idx]='\0';
	m=idx-1;

	rabinKarp();
	return 0;
}