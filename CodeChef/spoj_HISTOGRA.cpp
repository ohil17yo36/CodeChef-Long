#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli n,i,h[100005],maxx=-1;
int main(int argc, char const *argv[])
{
	while(1)
	{
		maxx=-1;
		scanf("%lld",&n);
		if(n==0)
			return 0;
	for( i=0;i<n;i++)
		scanf("%lld",&h[i]);
	stack<lli> st;
	for( i=0;i<n;)
	{
		if(st.empty() || h[i]>=h[st.top()])
			st.push(i++);
		else
		{
			lli topidx=st.top();
			st.pop();
			lli area;
			if(st.empty())
				area=h[topidx]*(i);	
			else
				area=h[topidx]*(i-st.top()-1);

			maxx=max(maxx,area);
		}
	}
	while(st.empty()==false)
	{
		lli topidx=st.top();
		st.pop();
		lli area;
		if(st.empty())
			area=h[topidx]*(i);	
		else
			area=h[topidx]*(i-st.top()-1);

		maxx=max(maxx,area);
	}
	printf("%lld\n",maxx);
	}
	return 0;
}	