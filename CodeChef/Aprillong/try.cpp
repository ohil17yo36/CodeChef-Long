    #include <bits/stdc++.h>
    #define lli long long int
    #define mod 1000003
    using namespace std;
    lli t,n,l,r,i,ans;
    inline lli scan( )
    {
    lli n = 0;
    char c;
    for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
    for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
    n = (n * 10) + (c & 0x0f);
    return n;
    }
    unsigned long long int gcd(unsigned long long int a,unsigned long long int b)
    {
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
    }
    lli nckfast(lli n,lli k)
    {
    lli divisor,ans=1;
    if(k>n)
    return 0;
    if(k>n-k)
    k=n-k;
    for(lli i=1;i<=k;i++)
    {
    divisor=gcd(ans,i);
    ans/=divisor;
    ans*=(n-i+1)/(i/divisor);
    }
    return ans;
    }
    lli lucas_nck(lli n,lli r)
    {
    lli nk,rk,prod=1;
    nk=n%mod;
    rk=r%mod;
    n/=mod;
    r/=mod;
    
    if(nk<rk)
    return 0;
    
    prod=((nckfast(n,r))*(nckfast(nk,rk)))%mod;
    
    return (prod);
    }
    int main(int argc, char const *argv[])
    {
    t=scan();
    while(t--)
    {
    n=scan();
    l=scan();
    r=scan();
    ans=(lucas_nck(r-l+n+1,r-l+1)-1);
    cout<<((ans+mod)%mod)<<endl;
    }
    return 0;
    } 