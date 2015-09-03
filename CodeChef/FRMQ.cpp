#include <cstdio>
#include <cmath>
#define lli long int
inline lli scan( )
{
	register lli n1 = 0;
	char c;
	for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
	for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
	n1 = (n1 * 10) + (c & 0x0f);
	return n1;
}
lli a[100005],n,m,Max[100005][25],x,y,l,r,logarr[100005],antilog[25];
int main(int argc, char const *argv[])
{
	for(lli i=1;i<=100005;i++)
		logarr[i]=log2(i);
	for(lli i=0;i<=20;i++)
		antilog[i]=(1<<i);
	n=scan();
	for(lli i=0;i<n;i++)
		a[i]=scan(),Max[i][0]=a[i];
	m=scan(),x=scan(),y=scan();
	for(lli j=1;(1<<j)<=n;j++)
	{
		for(lli i=0;i+(1<<(j-1))<n;i++)
		{

			if(Max[i][j-1]>Max[i+(1<<(j-1))][j-1])
				Max[i][j]=Max[i][j-1];
			else
				Max[i][j]=Max[i+(1<<(j-1))][j-1];

		}
	}

	lli sum=0;
	while(m--)
	{
		if(x<y)
			l=x,r=y;
		else
			r=x,l=y;

		lli k=logarr[r-l+1];
		lli K=antilog[k];
		sum+=(Max[l][k]>Max[r-K+1][k])?Max[l][k]:Max[r-K+1][k];
		x=(x+7);
		y=(y+11);
		while(x>=n-1)
			x-=(n-1);
		while(y>=n)
			y-=n;
		
	}
	printf("%d\n",sum );
	return 0;
}