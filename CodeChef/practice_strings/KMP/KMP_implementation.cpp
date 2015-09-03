#include <bits/stdc++.h>
using namespace std;
#define lli long long int
char text[100000],pattern[100000],ch;
lli pi[100000],idx,n,m;
void computePrefix()
{
	lli k=0;
	pi[1]=0;
	for(lli i=2;i<=m;i++)
	{
		while(k>0 && pattern[k+1]!=pattern[i])
			k=pattern[k];
		if(pattern[k+1]==pattern[i])
			k++;
		pi[i]=k;
	}
}
void kmp()
{
	computePrefix();
	lli q=0;
	for(lli i=1;i<=n;i++)
	{
		while(q>0 && pattern[q+1]!=text[i])
			q=pi[q];
		if(pattern[q+1]==text[i])
			q++;
		if(q==m)
			printf("Pattern has been found at %lld\n",i-m+1);
	}
}
int main(int argc, char const *argv[])
{
	idx=1;
	while((ch=getchar_unlocked())!='\n')
		text[idx++]=ch;
	text[idx]='\0';
	n=idx-1;
	idx=1;
	while((ch=getchar_unlocked())!='\n')
		pattern[idx++]=ch;
	pattern[idx]='\0';
	m=idx-1;
	kmp();
	return 0;
}