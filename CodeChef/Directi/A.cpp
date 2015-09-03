#include <bits/stdc++.h>
using namespace std;
#define lli long long int
inline lli scan( )
{
	lli n1 = 0;
	char ch;
	for( ch = getchar_unlocked(); ch==' ' || ch=='\n' || ch == '\t'; ch = getchar_unlocked());
	for( ; ch > 0x2f && ch < 0x3a; ch = getchar_unlocked())
	n1 = (n1 * 10) + (ch & 0x0f);
	return n1;
}
lli t,a[100005],n;
int main(int argc, char const *argv[])
{
	t=scan();
	while(t--)
	{
		lli cnt1=0,cnt2=0;
		n=scan();
		for(lli i=1;i<=n;i++)
			a[i]=scan();
		for(lli i=1;i<=n;i++)
		{
			lli j=i-1;	
			while(j>0)
			{
				cnt1++;
				if(a[j-1]>a[j])
				{
					swap(a[j],a[j-1]);
					j--;
					cnt2++;
				}
				else
				{
					break;
				}
			}
		}
		printf("%lld\n",cnt1-cnt2);
	}
	return 0;
}