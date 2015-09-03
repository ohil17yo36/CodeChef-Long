#include <bits/stdc++.h>
using namespace std;
#define lli unsigned long long int
lli n,m,a[1000006],k,lrange,rrange,cumSum[1000006],ans,idxx,len;
char ch1,ch2;
stack<lli> st;
vector<pair<lli,lli> >v3;
vector<pair<lli,lli> >v1;//v1-value,numberofsubarrays
vector<lli>v2;//v2-value,idxx
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
	n=scan();
	m=scan();
	for(lli i=0;i<n;i++)
		a[i]=scan();
	lli i;
	for(i=0;i<n;)
	{
		if(st.empty() || a[st.top()]>=a[i])
			st.push(i++);
		else
		{
			lli topidx=st.top();
			st.pop();
			if(st.empty())
			{
				lrange=topidx;
				rrange=i-topidx-1;
				v3.push_back(make_pair(a[topidx],(lrange+rrange+1 + lrange*rrange)));
			}
			else
			{
				lrange=topidx-1-st.top();
			    rrange=i-topidx-1;
			    v3.push_back(make_pair(a[topidx],(lrange+rrange+1 + lrange*rrange)));
			}
		}
	}

	while(st.empty()==false)
	{
		lli topidx=st.top();
		st.pop();
		if(st.empty())
		{
			lrange=topidx;
			rrange=i-topidx-1;
			v3.push_back(make_pair(a[topidx],(lrange+rrange+1 + lrange*rrange)));
		}
		else
		{
			lrange=topidx-st.top()-1;
			rrange=i-topidx-1;
			v3.push_back(make_pair(a[topidx],(lrange+rrange+1 + lrange*rrange)));
		}	
	}
	sort(v3.begin(),v3.end());
	v2.push_back(v3[0].first);
	v1.push_back(make_pair(v3[0].first,v3[0].second));
	for(vector<pair<lli,lli> >::iterator it=v3.begin()+1;it!=v3.end();it++)
	{
		if(it->first==(it-1)->first)
		{
			v1[v1.size()-1].second+=it->second;
		}
		else
		{
			v1.push_back(make_pair(it->first,it->second));
			v2.push_back(it->first);
		}
	}
	len=(lli)v2.size();
	cumSum[0]=v1[0].second;
	for(lli i=1;i<len;i++)
		cumSum[i]=cumSum[i-1]+v1[i].second;
	while(m--)
	{
		ans=0;
		ch1=getchar();
		k=scan();
		ch2=getchar();
		getchar();
		if(ch1=='>')
		{
			vector<lli>::iterator it=upper_bound(v2.begin(),v2.end(),k);
			if(it==v2.end())
				ans=0;
			else
			{
				idxx=(lli)(it-v2.begin());
				ans=cumSum[len-1]-cumSum[idxx]+v1[idxx].second;
			}
		}
		else if(ch1=='=')
		{
			vector<lli>::iterator it=lower_bound(v2.begin(),v2.end(),k);
			if(it==v2.end() || *it!=k)
				ans=0;
			else
			{
				idxx=(lli)(it-v2.begin());
				ans=v1[idxx].second;
			}
		}
		else
		{
			vector<lli>::iterator it=lower_bound(v2.begin(),v2.end(),k);
			if(it==v2.begin())
				ans=0;
			if(it==v2.end())
				ans=cumSum[len-1];
			else
			{
				idxx=(lli)(it-1-v2.begin());
				ans=cumSum[idxx];
			}
		}
		if(ch2=='D')
		{
			if(ans&1)
				putchar('D');
			else
				putchar('C');
		}
		else
		{
			if(ans&1)
				putchar('C');
			else
				putchar('D');
		}
	}
	return 0;
}	