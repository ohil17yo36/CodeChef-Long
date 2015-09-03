#include <bits/stdc++.h>
using namespace std;
#define lli long long int
inline lli scan( )
{
	lli n1 = 0;
	char c;
	for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
	for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
	n1 = (n1 * 10) + (c & 0x0f);
	return n1;
}
struct dish
{
	lli rank;
	lli parent;
}a[10005];
lli t,q,n,x,y;
lli find(lli num)
{
	if(a[num].parent!=num)
		a[num].parent=find(a[num].parent);
	return a[num].parent;
}
void Union(lli num1,lli num2)
{
	lli num1root=find(num1);
	lli num2root=find(num2);
	if(a[num1root].rank<a[num2root].rank)
		a[num1root].parent=num2root;
	else if(a[num1root].rank>a[num2root].rank)
		a[num2root].parent=num1root;
	return;
}
int main(int argc, char const *argv[])
{
	t=scan();
	while(t--)
	{
		n=scan();
		for(lli i=1;i<=n;i++)
			a[i].rank=scan(),a[i].parent=i;
		q=scan();
		while(q--)
		{
			int chc;
			chc=scan();
			if(chc)
			{
				x=scan();
				printf("%lld\n",find(x));
			}
			else
			{
				x=scan(),y=scan();
				if(find(x)==find(y))
					printf("Invalid query!\n");
				else
					Union(x,y);
			}
		}
	}
	return 0;
}