#include <bits/stdc++.h>
using namespace std;
long long int i,n,t,Bcount,Gcount,btap,gtap,num1,num2,res,res1,res2,Btapinstance[100005],Gtapinstance[100005];
char str[100005],str1[100005],str2[100005];
inline long long int scan( )
{
long long int n = 0;
char c;
for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
n = (n * 10) + (c & 0x0f);
return n;
}
int main(int argc, char const *argv[])
{
	char ch;
	t=scan();
	while(t--)
	{
		Bcount=0;
		Gcount=0;
		btap=0;
		gtap=0;
		int type;
		type=scan();
		i=0,num1=0,num2=0,res=0,res1=0,res2=0;
		while((ch=getchar_unlocked())!='\n')
		{
			str[i]=ch;
			if(ch=='B')
				Bcount++;
			else
			{
				if(ch=='G')
				{
					Gcount++;
				}
			}
			if(i%2==0)
			{
				str1[i]='B';
				str2[i]='G';
			}
			else
			{
				str1[i]='G';
				str2[i]='B';
			}
			i++;	
		}
		//puts(str1);
		//puts(str2);
		n=i;
		//cout<<n<<endl;
		if(abs(Gcount-Bcount)>1)
		{
			cout<<-1<<endl;
			continue;
		}
		if(type==0)
		{
			if(Bcount==Gcount)
			{
				for(i=0;i<n;i++)
				{
					if(str[i]!=str1[i])
						num1++;
					if(str[i]!=str2[i])
						num2++;
				}
				cout<<(min(num1,num2))/2<<endl;				
				continue;
			}
			else
			{
				if(Bcount>Gcount)
				{
					for(i=0;i<n;i++)
					{
						if(str[i]!=str1[i])
							num1++;
					}
					cout<<num1/2<<endl;	
				}
				else
				{
					for(i=0;i<n;i++)
					{
						if(str[i]!=str2[i])
							num2++;
					}
					cout<<num2/2<<endl;
				}
			}
		}

		else
		{
			if(Bcount==Gcount)
			{
				for(i=0;i<n;i++)
				{
					if(str[i]!=str1[i])
					{
						if(str[i]=='B')
						{
							Btapinstance[btap++]=i;
						}
						else
						{
							Gtapinstance[gtap++]=i;
						}
					}
				}
				//n=btap;
				for(i=0;i<btap;i++)
				{
					res1+=(long long int)abs(Btapinstance[i]-Gtapinstance[i]);
				}
				btap=0;
				gtap=0;
				for(i=0;i<n;i++)
				{
					if(str[i]!=str2[i])
					{
						if(str[i]=='B')
						{
							Btapinstance[btap++]=i;
						}
						else
						{
							Gtapinstance[gtap++]=i;
						}
					}
				}
				//n=btap;
				for(i=0;i<btap;i++)
				{
					res2+=(long long int)abs(Btapinstance[i]-Gtapinstance[i]);
				}
				cout<<min(res1,res2)<<endl;
				continue;	
			}
			if(Bcount>Gcount)
			{
				for(i=0;i<n;i++)
				{
					if(str[i]!=str1[i])
					{
						if(str[i]=='B')
						{
							Btapinstance[btap++]=i;
						}
						else
						{
							Gtapinstance[gtap++]=i;
						}
					}
				}
				// cout<<"Btap :"<<btap<<endl;
				// cout<<"Gtap :"<<gtap<<endl;
				//n=btap;
				for(i=0;i<btap;i++)
				{
					res+=(long long int)abs(Btapinstance[i]-Gtapinstance[i]);
				}
				cout<<res<<endl;
			}
			else
			{
				for(i=0;i<n;i++)
				{
					if(str[i]!=str2[i])
					{
						if(str[i]=='B')
						{
							Btapinstance[btap++]=i;
						}
						else
						{
							Gtapinstance[gtap++]=i;
						}
					}
				}
				// cout<<"Btap: "<<btap<<endl;
				// cout<<"Gtap: "<<gtap<<endl;
				//n=btap;

				for(i=0;i<btap;i++)
				{
					res+=(long long int)abs(Btapinstance[i]-Gtapinstance[i]);
				}
				cout<<res<<endl;	
			}
		}
	}
	return 0;
}