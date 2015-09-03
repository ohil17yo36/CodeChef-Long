//Giving TLE...dont trust this
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
lli t,pos[MAXLG][MAXN],stp,cnt,n,suffixArray[MAXN],LCP[MAXN-1],sArrForLcp[MAXN];

int compare(const struct entry &a,const struct entry &b)
{
	return (a.nr[0]==b.nr[0])?(a.nr[1]<b.nr[1]?1:0):(a.nr[0]<b.nr[0]?1:0);
}
lli lcp(lli x,lli y)
{
	if(x==y)
		return n-x;
	lli answer=0;
	for(lli k=stp;k>=0 && x<n && y<n;k--)
		if(pos[k][x]==pos[k][y])
			answer+=(1<<k),x+=(1<<k),y+=(1<<k);
	return answer;	
}
int main(int argc, char const *argv[])
{
	char ch;
	scanf("%lld",&t);
	getchar_unlocked();
	while(t--)
	{
		lli idx=0;
		while((ch=getchar_unlocked())!='\n')
			str[idx++]=ch;
		str[idx]='\0';
	n=idx;
	// memset(pos,0,sizeof(pos));
	// memset(suffixArray,0,sizeof(suffixArray));
	// memset(sArrForLcp,0,sizeof(sArrForLcp));
	for(lli i=0;i<n;i++)
		pos[0][i]=(str[i]-'A');
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
		suffixArray[i]=pos[stp][i];

	for(lli i=0;i<n;i++)
		sArrForLcp[pos[stp][i]]=i;


	for(lli i=0;i<n-1;i++)
		LCP[i]=lcp(sArrForLcp[i],sArrForLcp[i+1]);
	lli ans=n-suffixArray[0];
	for(lli i=0;i<n-1;i++)
		ans+=((n-suffixArray[i+1])-LCP[i]);
	printf("%lld\n",ans);
	}
	return 0;
}