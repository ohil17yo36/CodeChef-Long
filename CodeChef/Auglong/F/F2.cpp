#include <bits/stdc++.h>
using namespace std;
#define lli long long int 
lli a[100001],n,k,mxidx,mxEl,stp,fullarray[100001],j,ans;
inline lli scan( )
{
	lli n1 = 0;
	char ch;
	for( ch = getchar_unlocked(); ch==' ' || ch=='\n' || ch == '\t'; ch = getchar_unlocked());
	for( ; ch > 0x2f && ch < 0x3a; ch = getchar_unlocked())
	n1 = (n1 * 10) + (ch & 0x0f);
	return n1;
}
int main(int argc, char const *argv[])
{
	n=scan(),k=scan();
	for(lli i=1;i<=n;i++)
		a[i]=scan();
	for(lli i=1;i<=n;i++)
	{
		if(a[i]>k)
		{
			j=0,mxidx=0;
			for(j=0;j<=mxEl;j+=a[i])
				mxidx=max(mxidx,fullarray[j]);
			if(mxidx)
			{
				if(mxidx<stp)
					ans+=(i-stp);
				else
				{
					ans+=(i-mxidx);
					stp=mxidx;
				}
			}
			else
			{
				ans+=i-stp;
			}
			fullarray[a[i]-k]=i;
		}
		else if(a[i]==k)
		{
			fullarray[0]=i;
			ans+=i-stp;
		}
		else
		{
			ans+=i-stp;
		}
		mxEl=max(mxEl,a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}