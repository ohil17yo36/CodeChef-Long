#include <bits/stdc++.h>
#define lli long long int 
using namespace std;
lli t,n,k,q,i,j,K,l,r,ansl[100002],lowestindex[100002],num,zcount,onecount,startwindow,res,keyval;
char str[100002],ch;
inline lli scan( )
{
lli n = 0;
char c;
for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
n = (n * 10) + (c & 0x0f);
return n;
}
lli binsearch(lli *lowestindex,lli l,lli r,lli key)
{
	lli m=l+((r-l)/2);
	if(l==r)
		return m;
	if(key<=lowestindex[m])
		return binsearch(lowestindex,l,m,key);
	else
		return binsearch(lowestindex,m+1,r,key);  
}
// lli binsearch(lli *lowestindex,lli l,lli r,lli key)
// {
// 	lli m;
// 	while(r-l>1)
// 	{//cout<<"Hello"<<endl;
// 		m=l+((r-l)/2);
// 		if(lowestindex[m]<=key)
// 			l=m;
// 		else
// 			r=m;
// 	}
// 	if(lowestindex[l]==key)
// 		return l;
// 	else
// 		return -1;  
// }
int main(int argc, char const *argv[])
{
	t=scan();
	while(t--)
	{
		n=scan();
		k=scan();
		q=scan();
		i=0;
		while((ch=getchar_unlocked())!='\n')
			str[i++]=ch;
		//puts(str);
		ansl[1]=1;
		lowestindex[1]=1;
		onecount=0;
		zcount=0;
		if(str[0]=='1')
			onecount++;
		else
			zcount++;
		startwindow=1;
		for(i=2;i<=n;i++)
		{
			if(str[i-1]=='1')
			onecount++;
			else
			zcount++;
			if(onecount>k||zcount>k)
			{
				if(str[startwindow-1]=='0')
					zcount--;
				else
					onecount--;

				if(str[i-1]=='1')
					onecount--;
				else
					zcount--;

				startwindow++;
				i--;
				continue;
			}
			ansl[i]=ansl[i-1]+onecount+zcount;
			num=ansl[i]-ansl[i-1]-1;
			lowestindex[i]=i-num;
		}
		// for(i=1;i<=n;i++)
		// cout<<ansl[i]<<"        "<<lowestindex[i]<<endl;	
		while(q--)
		{
			l=scan();
			r=scan();

			if(lowestindex[r]<l)
			{
				res=(((r-l+1)*(r-l+2))/2);
				cout<<res<<endl;
				continue;	
			}
			i=binsearch(lowestindex,l,r,l);
			res=ansl[r]-ansl[i-1]+(((i-l)*(i-l+1))/2);
			cout<<res<<endl;
		}
		// memset(ansl,0,sizeof(ansl));
		// memset(lowestindex,0,sizeof(lowestindex));		
	}
	return 0;
}