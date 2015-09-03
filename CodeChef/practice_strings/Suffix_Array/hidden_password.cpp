#include <bits/stdc++.h>
using namespace std;
#define MAXN 165536
#define MAXLG 200
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
		str[i+n]=str[i];
	str[2*n]='\0';
	for(lli i=0;i<2*n;i++)
		pos[0][i]=(str[i]-'a');
	// for(lli i=0;i<n;i++)
	// 	printf("%d ",pos[0][i]);
	// printf("\n");
	for(stp=1,cnt=1;(cnt>>1)<n;stp++,cnt=(cnt<<1))
	{
		for(lli i=0;i<n;i++)
		{
			L[i].nr[0]=pos[stp-1][i];
			L[i].nr[1]=(i+cnt<2*n)?pos[stp-1][i+cnt]:-1;
			L[i].p=i;
		}
		sort(L,L+n,compare);
		for(lli i=0;i<n;i++)
			pos[stp][L[i].p]=i>0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1]==L[i-1].nr[1]?pos[stp][L[i-1].p]:i;
		// for(lli i=0;i<n;i++)
		// 	printf("%d ",pos[stp][i]);
		// printf("\n");
	}
	stp--;
	lli minn=(1<<20),minIndex=-1;
	for(lli i=0;i<n;i++)
		suffixArray[pos[stp][i]]=i;
	for(lli i=0;i<n;i++)
		printf("%lld ",suffixArray[i]);
	printf("\n");
	printf("%lld\n",suffixArray[0]);				
	return 0;
}