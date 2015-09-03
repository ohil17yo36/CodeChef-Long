#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli t,len;
char a[2][200005];
int main(int argc, char const *argv[])
{
	scanf("%lld",&t);
	getchar();
	while(t--)
	{
		scanf("%s",a[0]);
		scanf("%s",a[1]);
		len=strlen(a[0]);
		a[0][len]='\0';
		a[1][len]='\0';
		lli cnt=0,j=0,i,minn=(1<<25),initi;
		if(a[0][0]=='.')
			i=0;
		else if(a[1][0]=='.')
			i=1;
		else
		{
			printf("No\n");
			continue;
		}

		initi=i;
		while(j<len)
		{
			if(a[i][j+1]=='.')
				j++;
			else 
			{
				if(a[(i+1)%2][j+1]=='.')
					j++,i=(i+1)%2,cnt++;
				else
				{
					break;
				}
			}
			
		}
		if(j==len-1)
			minn=min(minn,cnt);
		i=(initi+1)%2;
		j=0;
		if(a[i][j]=='#')
		{
			if(minn==(1<<25))
				printf("No\n");
			else
				printf("Yes\n%lld\n",minn);
			continue;
		}
		cnt=0;
		while(j<len)
		{
			if(a[i][j+1]=='.')
				j++;
			else if(a[(i+1)%2][j+1]=='.')
				j++,i=(i+1)%2,cnt++;
			else
				break;
		}
		if(j==len-1)
			minn=min(minn,cnt);
		if(minn==(1<<25))
			printf("No\n");
		else
			printf("Yes\n%lld\n",minn);
	}
	return 0;
}