#include <bits/stdc++.h>
using namespace std;
inline long long int scan( )
{
long long int n = 0;
char c;
for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
n = (n * 10) + (c & 0x0f);
return n;
}
vector<int>vec(26,0);
int main(int argc, char const *argv[])
{
	int t;
	t=scan();
	while(t--)
	{
		for (int i = 0; i < 26; ++i)
			{
				vec[i]=0;
			}	
		char ch;
		int i=0,len,f=0,spf=0;
		while((ch=getchar_unlocked())!='\n')
		{
			if(ch==32)
				spf=1;
			if(65<=ch && ch<=90)
			{
				vec[ch-65]=1;
			}
			if(97<=ch && ch<=122)
			{
				vec[ch-97]=1;
			}
		}
		for (int i = 0; i < 26; ++i)
		{
			if(vec[i]==0)
			{
				f=1;
				char ch=(i+65);
				cout<<ch<<endl;
				break;
			}
		}
		if(f==1)
			continue;
		else
		{
				char ch='~';
				cout<<ch<<endl;		
		}
	}
	return 0;
}