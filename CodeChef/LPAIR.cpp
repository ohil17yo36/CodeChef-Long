#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli m[100005],f[100005],arr[100005],temp[100005],n,cnt=1;
std::vector<pair<lli,pair<lli,lli> > > male,female;
map<lli,lli> mp;
lli Merger(lli left,lli mid,lli right)
{
	lli i=left,j=mid,k=left,res=0;
	while((i<=mid -1)&&(j<=right))
	{
		if(arr[i]<=arr[j])
		{
			temp[k++]=arr[i++];
		}
		else
		{
			temp[k++]=arr[j++];
			res+=(mid-i);
		}
	}
	while(i<=mid-1)
		temp[k++]=arr[i++];
	while(j<=right)
		temp[k++]=arr[j++];
	for(i=left;i<=right;i++)
		arr[i]=temp[i];
	return res;
}
lli invcnt(lli left,lli right)
{
	lli mid,incnt=0;
	if(right>left)
	{
		mid=(left+right)/2;
		incnt=invcnt(left,mid);
		incnt+=invcnt(mid+1,right);
		incnt+=Merger(left,mid+1,right);
	}
	return incnt;
}

int main(int argc, char const *argv[])
{
	scanf("%lld",&n);
	for(lli i=0;i<n;i++)
	{
		scanf("%lld %lld",&m[i],&f[i]);
		male.push_back(make_pair(m[i],make_pair(i,0)));
		female.push_back(make_pair(f[i],make_pair(i,0)));
	}
	sort(male.begin(),male.end());
	sort(female.begin(),female.end());
	for (std::vector<pair<lli,pair<lli,lli> > >::size_type i = 0; i < male.size(); ++i)
	{
		mp[male[i].second.first]=cnt++;
	}
	for(std::vector<pair<lli,pair<lli,lli> > >::size_type i=0;i<female.size();i++)
	{
		arr[(lli)i]=mp[female[i].second.first];
	}
	printf("%lld\n",invcnt(0,n-1));
	return 0;
}