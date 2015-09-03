#include <bits/stdc++.h>
using namespace std;
char str1[105],str2[105];
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		scanf("%s",str1);
		scanf("%s",str2);
		int len=strlen(str1),diffcnt=0,samecnt=0;
		for(int i=0;i<len;i++)
		{
			if((str1[i]!=str2[i]) && (str1[i]!='?') && (str2[i]!='?'))
				diffcnt++;
			else if((str1[i]==str2[i]) && (str1[i]!='?') && (str2[i]!='?'))
				samecnt++;
		}
		printf("%d %d\n",diffcnt,len-samecnt);
	}
	return 0;
}