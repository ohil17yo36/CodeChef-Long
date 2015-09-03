#include <bits/stdc++.h>
#include <fstream>
#define m 1000000007;

using namespace std;
 
long long arr[100005];
long long tree[400020];
long long lazy[400020];
int bit[400020];


void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b)
	{
    	tree[node] = arr[a]; // Init value
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	tree[node] =(tree[node*2]+tree[node*2+1])%m; // Init root value
}
 
 
void update_tree(long node,long long a,long long b,long i,long j,int type,long long value) {
  
  		if(lazy[node] || bit[node])
   		{
   			if(bit[node])
   			{
				tree[node]=((b-a+1)*lazy[node])%m;
				
				//printf("%lldq\n",tree[node]);
				
				if(a != b) {
						
					lazy[node*2]=lazy[node];
					bit[node*2]=1;
    				lazy[node*2+1]=lazy[node];
					bit[node*2+1]=1;
				}				
				
				lazy[node]=0;
				bit[node]=0;  
   			}
   			else
   			{
   				tree[node]+=((b-a+1)*lazy[node])%m;
   				tree[node]%=m;
   				
   				if(a != b)
				{
   					lazy[node*2]=(lazy[node*2]+lazy[node])%m;
					lazy[node*2+1]=(lazy[node*2+1]+lazy[node])%m;
				}				
				
				lazy[node]=0;  
   			}
   		}
  	
  
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a >= i && b <= j)
  	{
  		if(type==3)
  		{
    		tree[node]=((b-a+1)*value)%m;
    		
    		if(a != b)
			{		
				lazy[node*2]=value;
   				lazy[node*2+1]=value;
   				bit[node*2]=1;
   				bit[node*2+1]=1;
			}		
    	}
    	else if(type==1)
    	{
    		tree[node]+=((b-a+1)*value)%m;
    		tree[node]%=m;
    		
    		if(a != b)
			{
   				lazy[node*2]=(lazy[node*2]+value)%m;
				lazy[node*2+1]=(lazy[node*2+1]+value)%m;
			}
    	}
    		return;
	}
 
	update_tree(node*2, a, (a+b)/2, i, j,type, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j,type, value); // Updating right child
 
	tree[node]=(tree[node*2]+tree[node*2+1])%m;
}
 

long long query_tree(long node,long long a,long long b,long i,long j) {
	
	if(a > b || a > j || b < i) return 0; // Out of range
 
  	if(lazy[node] || bit[node])
  		{
  			if(bit[node])
   			{
				tree[node]=((b-a+1)*lazy[node])%m;
				
				if(a != b) {
						
					lazy[node*2]=lazy[node];
					bit[node*2]=1;
    				lazy[node*2+1]=lazy[node];
					bit[node*2+1]=1;
				}				
				
				lazy[node]=0;
				bit[node]=0;  
   			}
   			else
   			{
   				tree[node]+=((b-a+1)*lazy[node])%m;
   				tree[node]%=m;
   				
   				if(a != b)
				{
   					lazy[node*2]=(lazy[node*2]+lazy[node])%m;
					lazy[node*2+1]=(lazy[node*2+1]+lazy[node])%m;
				}				
				
				lazy[node]=0;  
   			}
   		}
 
	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];
 
	long long q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	long long q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child
 
	long long res =(q1+q2)%m; // Return final result
	
	//tree[node] =(tree[node*2]+tree[node*2+1])%m;
	
	return res;
}
 
int main()
{
	long long n,q,v,ans,i;
	long x,y;
	int type;
	ofstream fout;
	ifstream fin;
	fout.open("Vishout.txt");
	fin.open("inp.txt");
	// scanf("%lld%lld",&n,&q);
	fin>>n>>q;
	for(i=0;i<n;i++)
		fin>>arr[i];// scanf("%lld",arr+i);
 
	build_tree(1,0,n-1);
 
	memset(lazy,0,sizeof lazy);
	memset(bit,0,sizeof bit);
	
	while(q--)
	{
		// scanf("%d",&type);
		fin>>type;
		if(type==4)
		{
			// scanf("%ld%ld",&x,&y);
			fin>>x>>y;
			x++,y++;
			ans=query_tree(1,0,n-1,x-1,y-1);
			while(ans<0)
				ans+=m;
			// printf("%lld\n",ans);
			fout<<ans<<endl;
		}
		else
		{
			// scanf("%ld%ld%lld",&x,&y,&v);
			fin>>x>>y>>v;
			x++,y++;
			update_tree(1,0,n-1,x-1,y-1,type,v);
		}
	}
 	return 0;
}
