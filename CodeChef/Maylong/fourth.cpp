#include <bits/stdc++.h>
#define lli long long int
using namespace std;
char str[100005],str1[100005],str2[100005],ch;
inline lli scan( )
{
	lli n = 0;
	char c;
	for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
	for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
	n = (n * 10) + (c & 0x0f);
	return n;
}
void neg(lli *streak_flag)
{
	if(*streak_flag)
		*streak_flag=0;
	else
		*streak_flag=1;
	return;
}
void flip(lli i)
{
	// printf("%lld %c ",i,str[i]);
	if((str[i]-'0')==0)
		str[i]='1';
	else if((str[i]-'0')==1)
		str[i]='0';
	// printf("%c\n",str[i] );
	return;
}
int main(int argc, char const *argv[])
{
	lli t,n,k,len;
	t=scan();
	while(t--)
	{
		lli index=0,streak_flag,flip_count1=0,flip_count2=0;
		n=scan();
		k=scan();
		while((ch=getchar_unlocked())!='\n')
		{
			if(index%2==0)
			{
				str1[index]='0';
				str2[index]='1';
			}
			else
			{
				str1[index]='1';
				str2[index]='0';
			}
			str[index]=ch;
			if(str[index]!=str1[index])
				flip_count1++;
			else if(str[index]!=str2[index])
					flip_count2++;	
			index++;
		}
		len=index;
		str[len]='\0';
		str1[len]='\0';
		str2[len]='\0';
		lli streak_count=1,streak_start=0,streak_end,num_of_segments;
		lli flip_count=0,j;
		if(k==1)
		{
			if(flip_count1<flip_count2)
			{
				printf("%lld\n",flip_count1);
				index=0;
				while(str1[index++]!='\0')
					printf("%c",str1[index-1]);
				printf("\n");					
			}
			else
			{
				printf("%lld\n",flip_count2);
				index=0;
				while(str2[index++]!='\0')
					printf("%c",str2[index-1]);
				printf("\n");						
			}
			continue;
		}
		if((str[0]-'0')==0)
			streak_flag=0;
		else
			streak_flag=1;
	
		for(lli i=1;i<=len;i++)
		{
			if((str[i]-'0')==streak_flag)
				streak_count++;
			else
			{
				streak_end=i-1;
				j=streak_start;
				while((j+2*k)<=streak_end)
				{
					flip_count++;
					flip(j+k);
					j+=(k+1);
				}
				if((streak_end - j +1 )>=k+1)
				{
					// printf("Hello %lld %lld\n",j,streak_end);
					flip_count++;
					flip((j+streak_end)/2);
				}
				streak_start=i;
				streak_count=1;
				neg(&streak_flag);
			}
		}
		index=0;
		printf("%lld\n",flip_count);
		while(str[index++]!='\0')
			printf("%c",str[index-1]);
		printf("\n");
	}
	return 0;
}