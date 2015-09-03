#include <bits/stdc++.h>
using namespace std;
char str[100005];
int counti[10];
int num[20]={INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN};
int adjmat[21][21];
int minindex(int *dist,bool *visited)
{
	int min = INT_MAX,min_index;
 
   for (int v = 0; v < 20; v++)
     if (visited[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}
int dijsktra(int src,int dest)
{
	bool visited[20]={false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
	int dist[20]={INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
	// visited[src]=true;
	dist[src]=0;
	for(int i=0;i<20;i++)
	{
		int min_index=minindex(dist,visited);
		visited[min_index]=true;
		for(int j=0;j<20;j++)
		{
			if(visited[j]==false && adjmat[j][min_index]>0 && dist[min_index]!=INT_MAX && dist[min_index]+adjmat[min_index][j]<dist[j])
				dist[j]=dist[min_index]+adjmat[min_index][j];	
		}
	}
	return dist[dest];
}
int main(int argc, char const *argv[])
{
	int i=0,len;
	char ch;
	while((ch=getchar_unlocked())!='\n')
	{
		str[i]=ch;
		num[str[i]-'0']=min(num[str[i]-'0'],i);
		counti[str[i]-'0']++;
		if(counti[str[i]-'0']>=2)
		{
			
			num[str[i]-'0'+10]=max(num[str[i]-'0'+10],i);
		}
		i++;
	}
	str[i]='\0';	
	len=i;
	adjmat[str[0]-'0'][str[1]-'0']=1;
	adjmat[str[1]-'0'][str[0]-'0']=1;
	adjmat[str[len-1]-'0'][str[len-2]-'0']=1;
	adjmat[str[len-2]-'0'][str[len-1]-'0']=1;
	for(i=1;i<len-1;i++)
	{
		adjmat[str[i]-'0'][str[i-1]-'0']=1;
		adjmat[str[i-1]-'0'][str[i]-'0']=1;
		adjmat[str[i]-'0'][str[i+1]-'0']=1;
		adjmat[str[i+1]-'0'][str[i]-'0']=1;
	}
	int res;
	if(counti[str[len-1]-'0']>=2)
	 	{

	 	res=dijsktra(str[0]-'0',str[len-1]-'0'+10);
	 	}
	 else
	 	res=dijsktra(str[0]-'0',str[len-1]-'0');

	printf("%d\n",res);
	return 0;
}