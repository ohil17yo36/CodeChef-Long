#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define lli unsigned long long int
#define mod 1000000007
//using namespace std;
lli arr[10000007];
lli mat[10000007][2],qu1[10000007];

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
{   lli L1,La,Lc,Lm,D1,Da,Dc,Dm,L,R,sum=0,minimum,N,K,Q,a,b,c,d,e,f,r,s,t,m,indexl,indexr,prod;
    int flag=0;
    N=scan(),K=scan(),Q=scan(),a=scan(),b=scan(),c=scan(),d=scan(),e=scan(),f=scan(),r=scan(),s=scan(),t=scan(),m=scan(),arr[1]=scan(); 
    L1=scan(),La=scan(),Lc=scan(),Lm=scan(),D1=scan(),Da=scan(),Dc=scan(),Dm=scan();
    prod=t%s;
    lli i;
    for( i=2;i<=N;i++)
    {
        prod=((prod)*(t%s))%s;
        if(prod<=r)
            arr[i]=((((a%m)*(((arr[i-1]%m)*(arr[i-1]%m))%m))%m)+(((b%m)*(arr[i-1]%m))%m)+(c%m))%m;
        else
            arr[i]=((((d%m)*(((arr[i-1]%m)*(arr[i-1]%m))%m))%m)+(((e%m)*(arr[i-1]%m))%m)+(f%m))%m;      
    }   
    
    for (i = 1; i <= K; ++i)
    {

        while((indexl!=indexr) && arr[i] <= arr[qu1[indexr-1]])
            {indexr--;  
            }
        qu1[indexr++]=i;
    }
    for ( ; i <= N; ++i)
    {

        mat[i-K][flag]=arr[qu1[indexl]];
        
        while ( ((indexl!=indexr)) && (qu1[indexl]<=(i - K)))
            {indexl++;  
            } 
        
        while ( ((indexl!=indexr)) && arr[i] <= arr[qu1[indexr-1]])
            {indexr--;
            }
         
        qu1[indexr++]=i;
    }
    mat[i-K][flag]=arr[qu1[indexl]];


    indexl=0;
    indexr=0;
    if((2*K)<=N)
    {flag++,K=2*K;
    
    for (i = 1; i <= K; ++i)
    {

        while (!(indexl==indexr) &&  arr[i]<=arr[qu1[indexr-1]])
            indexr--;  
 
        qu1[indexr++]=i;
    }
    for ( ; i <= N; ++i)
    {

        mat[i-K][flag]=arr[qu1[indexl]];
        
        while ( (!(indexl==indexr)) && qu1[indexl] <= (i - K))
            indexl++;  
 
        
        while ( (!(indexl==indexr)) && arr[i] <= arr[qu1[indexr-1]])
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
        L1=((((La%Lm)*(L1%Lm))%Lm)+(Lc%Lm))%Lm;
        D1=((((Da%Dm)*(D1%Dm))%Dm)+(Dc%Dm))%Dm;
        L=L1+1;
        //R=min(L+K-1+D1,N);
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
    printf("%llu %llu\n",sum,prod);
    return 0;
}