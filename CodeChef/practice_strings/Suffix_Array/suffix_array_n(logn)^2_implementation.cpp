#include <bits/stdc++.h>
using namespace std;
#define MAXN 65536
#define MAXLG 17
#define lli long long int
char str[MAXN];
struct entry
{
	lli nr[2],p;
}L[MAXN];
lli pos[MAXLG][MAXN],stp,cnt,n,suffixArray[MAXN];

int compare(const struct entry &a,const struct entry &b)
{
	return (a.nr[0]==b.nr[0])?(a.nr[1]<b.nr[1]?1:0):(a.nr[0]<b.nr[0]?1:0);
}

int main(int argc, char const *argv[])
{
	scanf("%s",str);
	n=strlen(str);
	for(lli i=0;i<n;i++)
		pos[0][i]=(str[i]-'0');
	for(stp=1,cnt=1;(cnt>>1)<n;stp++,cnt=(cnt<<1))
	{
		for(lli i=0;i<n;i++)
		{
			L[i].nr[0]=pos[stp-1][i];
			L[i].nr[1]=(i+cnt<n)?pos[stp-1][i+cnt]:-1;
			L[i].p=i;
		}
		sort(L,L+n,compare);
		for(lli i=0;i<n;i++)
			pos[stp][L[i].p]=i>0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1]==L[i-1].nr[1]?pos[stp][L[i-1].p]:i;
	}
	stp--;
	for(lli i=0;i<n;i++)
		suffixArray[pos[stp][i]]=i;
	for(lli i=0;i<n;i++)
		printf("%lld\n",suffixArray[i]);
	return 0;
}