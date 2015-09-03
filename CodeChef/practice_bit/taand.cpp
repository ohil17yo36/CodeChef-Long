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
long long int func(long long int *a,bool *used,int n,int hbit)
{
	if(hbit<0)
		return 0;
	int count=0;
	for(long long int i=0;i<n;i++)
	{
		// cout<<"The hbit  is"<<hbit<<endl;
		if(used[i]==true)
		{
			if((a[i])&(1<<hbit))
			{
				count++;
			}
		}
	}
	long long int res=0;
	if(count>1)
	{
		//cout<<"The hbit here is"<<hbit<<endl;
		for(long long int i=0;i<n;i++)
		{
			if((a[i]&(1<<hbit))==0)
			{
				used[i]=false;
			}
		}	
		res=(1<<hbit);	
	}
	return  res+func(a,used,n,hbit-1);
}
int main(int argc, char const *argv[])
{
	int n;
	n=scan();
	long long int a[n];
	bool used[n];
	for(long long int i=0;i<n;i++)
	{
		a[i]=scan();
		used[i]=true;
	}
	cout<<func(a,used,n,30)<<endl;
	return 0;
}