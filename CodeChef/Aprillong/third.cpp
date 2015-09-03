#include <bits/stdc++.h>
#define lli long long int
using namespace std;
inline lli scan( )
{
lli n = 0;
char c;
for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
n = (n * 10) + (c & 0x0f);
return n;
}
lli t,n,keypos,shift,ans,final_keypos;
int main(int argc, char const *argv[])
{
	char ch;
	t=scan();
	while(t--)
	{
		shift=0,ans=0;
		while((ch=getchar_unlocked())!='\n')
		{
			if(ch=='T')
				shift+=2;
			else
				shift+=1;
		}
		n=scan();

		final_keypos=(12*n-shift);
			for(keypos=1;keypos<=final_keypos;keypos++)
				ans+=((final_keypos+shift-keypos)/shift);
			
		cout<<ans<<endl;
	}	
	return 0;
}