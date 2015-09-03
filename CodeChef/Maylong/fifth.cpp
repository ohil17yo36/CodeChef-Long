#include <cstdio>
#include <cstdlib>
#define lli unsigned long long int
#define mod 1000000007
using namespace std;
lli arr[10000007];
lli mat[10000002][2],qu1[20000004];

inline lli scan( )
{
	lli n = 0;
	char ch;
	for( ch = getchar_unlocked(); ch==' ' || ch=='\n' || ch == '\t'; ch = getchar_unlocked());
	for( ; ch > 0x2f && ch < 0x3a; ch = getchar_unlocked())
	n = (n * 10) + (ch & 0x0f);
	return n;
}

int main(int argc, char const *argv[])
{
	register lli indexl=0,indexr=0,K,N,i,prod,sum=0,stuff,temp1,temp2,temp3,temp4;
	lli L1,La,Lc,Lm,D1,Da,Dc,Dm,L,R,minimum,Q,a,b,c,d,e,f,r,s,t,m;
	register int flag=0;
	N=scan(),K=scan(),Q=scan(),a=scan(),b=scan(),c=scan(),d=scan(),e=scan(),f=scan(),r=scan(),s=scan(),t=scan(),m=scan(),arr[1]=scan();	
	L1=scan(),La=scan(),Lc=scan(),Lm=scan(),D1=scan(),Da=scan(),Dc=scan(),Dm=scan();
	prod=t%s;
	stuff=prod;
	for(lli i=2;i<=N;i++)
	{
		prod=((prod)*(stuff))%s;
		if(prod<=r)
			arr[i]=((((a%m)*((arr[i-1]*arr[i-1])%m))%m)+((b*arr[i-1])%m)+(c%m))%m;
		else
			arr[i]=((((d%m)*((arr[i-1]*arr[i-1])%m))%m)+((e*arr[i-1])%m)+(f%m))%m;		
		
	}
	flag=0;
    for (i = 1; i <= K; ++i)
    {

        while ( (indexl!=indexr) && arr[i] <= arr[qu1[indexr-1]])
            indexr--;  
        
        qu1[indexr++]=i;
    }
 
    for ( ; i <= N; ++i)
    {
    	mat[i-K][flag]=arr[qu1[indexl]];
         
        while ( (indexl!=indexr) && qu1[indexl] <= i - K)
                indexl++; 
 
        
        while ( (indexl!=indexr) && arr[i] <= arr[qu1[indexr-1]])
                indexr--;
 
       
        qu1[indexr++]=i;  
    }
    
 	mat[i-K][flag]=arr[qu1[indexl]];

	indexl=0;
	indexr=0;
	flag++;
	if((2*K)<=N)
	{
		K=2*K;
		lli i;
    	for (i = 1; i <= K; ++i)
    	{
        	while ( (indexl!=indexr) && arr[i] <= arr[qu1[indexr-1]])
            	indexr--;  
        
        	qu1[indexr++]=i;
    	}
 
    	for ( ; i <= N; ++i)
    	{
    		mat[i-K][flag]=arr[qu1[indexl]];
       
       		while ( (indexl!=indexr) && qu1[indexl] <= i - K)
       	        	indexl++; 
         
        	while ( (indexl!=indexr) && arr[i] <= arr[qu1[indexr-1]])
            	    indexr--;  
        	qu1[indexr++]=i;  
   		}
    
 		mat[i-K][flag]=arr[qu1[indexl]];
		K/=2;
	}	
	prod=1;
	sum=0;
	for( i=1;i<=Q;i++)
	{
		if(L1>=Lm)
			L1=L1%Lm;
		if(D1>=Dm)
			D1=D1%Dm;
		temp1=La*L1;
		temp2=Da*D1;
		if(temp1>=Lm)
			temp1=temp1%Lm;
		if(temp2>=Dm)
			temp2=temp2%Dm;
		temp3=(temp1+Lc);
		temp4=(temp2+Dc);
		if(temp3>=Lm)
			temp3=temp3%Lm;
		if(temp4>=Dm)
			temp4=temp4%Dm;
		L1=temp3;
		D1=temp4;
		L=L1+1;
		
		if((L+K-1+D1)<=N)
			R=(L+K-1+D1);
		else
			R=N;
		if((R-L+1)==K)
		{
			minimum=mat[L][0];
		}
		else if((R-L+1)==2*(K))
		{
			minimum=mat[L][1];
		}
		else
		{
			
			if(mat[L][0]<=mat[R-K+1][0])
				minimum=mat[L][0];
			else
				minimum=mat[R-K+1][0];
		}
		sum+=minimum;
		prod=(prod*(minimum%mod))%mod;
	}
	printf("%lld %lld\n",sum,prod);
	return 0;
}