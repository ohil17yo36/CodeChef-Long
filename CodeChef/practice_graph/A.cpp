#include <bits/stdc++.h>
using namespace std;
char a[50],b[50];
int t,len;
int main(int argc, char const *argv[])
{
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		scanf("%s",a);
		scanf("%s",b);
		len=strlen(a);
		int ok=0;
		for(int i=0;i<len;i++)
		{
			if(a[i]!=b[i] && a[i]!='?' && b[i]!='?')
			{
				ok=1;
				break;
			}
		}
		if(ok)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}