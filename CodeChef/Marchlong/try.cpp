#include <bits/stdc++.h>
using namespace std;
inline int scan( )
{
int n = 0;
char c;
for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
n = (n * 10) + (c & 0x0f);
return n;
}
long long int res;
int main(int argc, char const *argv[])
{
	int t,s,c,k;
	t=scan();
	while(t--)
	{
		s=scan();
		c=scan();
		k=scan();
		if(k>max(s,c))
		{
			cout<<0<<endl;
			continue;
		}
		if(c==0)
		{
			cout<<(((long long int)(pow(2,s-k+1)))+1)<<endl;
			continue;
		}
		if(s==0)
		{
			if(k==1)
			{
				cout<<(((long long int)(pow(2,c+1)))-2)<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
			continue;
		}
		if(k==1)
		{
			res=(long long int)pow(2,s-k+1)+1;
			if(s<=c)
			{
				res+=(((long long int)pow(2,c+1) -(long long int)pow(2,s)));
			}
			cout<<res<<endl;
		}
		else
		{
			if(k>s)
				cout<<0<<endl;
			else
			{
				if(k>s-c)
				{
					cout<<(((long long int)(pow(2,s-k+2)))+1)<<endl;
				}
				else
				{
					cout<<(((long long int)(pow(2,s-k+1)))+1)<<endl;
				}
			}
		}

	}
	return 0;
}