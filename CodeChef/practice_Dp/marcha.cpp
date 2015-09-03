#include <bits/stdc++.h>
using namespace std;
int arr[1003][1003];
int a[22];	
int func(int i,int m,int n)
{
	if(arr[i][m]==0)
	{if(m==0)
		arr[i][m]=1;
	else if(m<0||i>=n)
		return 0;
	else
		arr[i][m]=func(i+1,m,n)||func(i+1,m-a[i],n);
	}
	return arr[i][m];

}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		
		for (int i = 0; i < n; ++i)
			scanf("%d",&a[i]);
		
		for (int i = 0; i < 1003; ++i)
			for(int j=0;j<1003;j++)
				arr[i][j]=0;
		if(func(0,m,n))
			printf("Yes\n");
		else
			printf("No\n");		
	}
	return 0;
}	