#include <bits/stdc++.h>
using namespace std;
int t,i;
char str[105],ch;
int main(int argc, char const *argv[])
{
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		int continueflag=0,chefcnt=0,othercnt=0;
		scanf("%s",str);
		int len=strlen(str);
		for(i=0;i<len;i++)
		{
			if(str[i]=='1')
				chefcnt++;
			else
				othercnt++;
			if(chefcnt==11 && othercnt<10)
			{
				printf("WIN\n");
				continueflag=1;
				break;
			}
			if(othercnt==11 && chefcnt<10)
			{
				printf("LOSE\n");
				continueflag=1;
				break;
			}
			if(chefcnt==10 && othercnt==10)
				break;		
		}
		if(continueflag)
			continue;
		for(int j=i+1;j<len;j++)
		{
			if(str[j]=='1')
				chefcnt++;
			else
				othercnt++;

			if((chefcnt-othercnt)==2)
			{
				printf("WIN\n");
				break;
			}
			if((othercnt-chefcnt)==2)
			{
				printf("LOSE\n");
				break;
			}
		}
	}
	return 0;
}