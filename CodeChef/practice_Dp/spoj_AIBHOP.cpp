#include <bits/stdc++.h>
using namespace std;
char str[6105],ch;
int len;
int mat[6105][6105];
int func()
{
	for(int i = 0; i < len+1; ++i)
		mat[i][i]=0;
	for(int chlen = 2; chlen <= len; ++chlen)
	{
		for (int i = 0; i < len-chlen+1; ++i)
		{
			int j=i+chlen-1;
			if(chlen==2)
			{
				if(str[i]==str[j])
					mat[i][j]=0;
				else
					mat[i][j]=1;
				continue;
			}
			if(str[i]==str[j])
				mat[i][j]=mat[i+1][j-1];
			else
				mat[i][j]=1+min(mat[i+1][j],mat[i][j-1]);
		}
	}
	return mat[0][len-1];
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	getchar_unlocked();
	while(t--)
	{
		int i=0;
		while((ch=getchar_unlocked())!='\n')
			str[i++]=ch;
		len=i;
		printf("%d\n",func());
	}
	return 0;
}