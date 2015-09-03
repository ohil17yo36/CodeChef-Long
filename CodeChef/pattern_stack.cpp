#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli k,len;
char str[100005];
int check()
{
	if(len%2!=0)
		return false;
	stack<lli> st;
	// st.clear();
	for(lli i=0;i<len;i++)
	{
		if(str[i]=='(')
			st.push(i);
		else
		{
			if(st.empty())
				return false;
			else
			{
				st.pop();
			}
		}	
	}
	if(!st.empty())
		return 0;
	else
		return 1;

}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		scanf("%s",str);
		scanf("%lld",&k);
		len=strlen(str);
		if(!check())
		{
			if(k==1)
				printf("%s\n",str );
			else
				printf("-1\n");
		}
		else
		{
			// printf("HEllo\n");
			int streakcnt=1;
			std::vector<lli> streak;
			streak.clear();
			streak.push_back(1);
			for(lli i=1;i<len;i++)
			{
				if(str[i]!=str[i-1])
					streak.push_back(1),streakcnt++;
				else
				{
					streak[streakcnt-1]++;
				}		
			}
			if(k>streakcnt)
				printf("-1\n");
			else
			{
				if(k<=streakcnt/2)
				{
					streak[2*k-1]--;
				}
				else
				{
					k-=streakcnt/2;
					streak[streakcnt-2*k]--;
				}
				for(lli i=0;i<streakcnt;i++)
				{
					for(lli j=0;j<streak[i];j++)
					{
						if(i%2!=0)
							printf(")");
						else
							printf("(");
					}
				}
				printf("\n");
			}
		}
	}
	return 0;
}