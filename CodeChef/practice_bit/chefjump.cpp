#include <bits/stdc++.h>
using namespace std;
inline unsigned long long int scan( )
{
unsigned long long int n = 0;
char c;
for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
n = (n * 10) + (c & 0x0f);
return n;
}
int main(int argc, char const *argv[])
{
	unsigned long long int a;
	a=scan();
	if(a==0||a==1)
	{
		cout<<"yes"<<endl;
		return 0;
	}
	else
	{
		if(a%3==0)
		{
			cout<<"yes"<<endl;
		}
		else
		{
			if(a%3==1)
			{
				a/=3;
				if(a%2==0)
				{
					cout<<"yes"<<endl;
				}
				else
					cout<<"no"<<endl;
			}
			else
			{
				cout<<"no"<<endl;
			}
		}
	}
	return 0;
}	