#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli m,n,h[4005],j,maxx=-1;
char str[4005];
int main(int argc, char const *argv[])
{
	// while(1)
	// {
		maxx=-1;
		scanf("%lld %lld",&n,&m);
		// if(m==0 && n==0)
		// 	return 0;
		// scanf("%lld",&f);
		getchar();
		for(j=0;j<m;j++)
			h[j]=0;
		for(lli i=0;i<n;i++)
		{
			scanf("%s",str);
			// printf("%s\n",str);
			for( j=0;j<m;j++)
			{
				if(str[j]=='O')
					h[j]=0;
				else
					h[j]++;
			}
			stack<lli> st;
			for( j=0;j<m;)
			{
				if(st.empty() || h[j]>=h[st.top()])
					st.push(j++);
				else
				{
					lli topidx=st.top();
					st.pop();
					lli area;
					if(st.empty())
							area=h[topidx]*j;
					else
						area=h[topidx]*(j-st.top()-1);
					maxx=max(maxx,area);
				}
			}
			while(st.empty()==false)
			{
				lli topidx=st.top();
				st.pop();
				lli area;
				if(st.empty())
					area=h[topidx]*j;
				else
					area=h[topidx]*(j-st.top()-1);
				maxx=max(maxx,area);
			}
		}
		printf("%lld\n",maxx);
	// }	
	return 0;
}