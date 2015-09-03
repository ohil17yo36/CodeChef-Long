#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long int t,n,k;
inline long long int scan( )
{
long long int n = 0;
char c;
for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
n = (n * 10) + (c & 0x0f);
return n;
}
long long int power(long long int base,long long int exp)
{
    //cout<<"HEllo"<<endl;
    if(exp==1)
        return base;
    else
    {
        long long int x=power(base,(long long int)floor(exp/2));
        if(exp%2==0)
            return (((x%mod)*(x%mod))%mod);
        else
            return (((base%mod)*(((x%mod)*(x%mod))%mod))%mod)%mod;
    }
}
long long int func1(long long int n)
{
    return (power(2,(n+3)/2) - (2%mod) + mod)%mod;
}
long long int func2(long long int n)
{
    return ((((3%mod)*power(2,n/2))%mod)-(2%mod)+mod)%mod;
}
int main(int argc, char const *argv[])
{
    t=scan();
    while(t--)
    {
        n=scan();
        if(n==1)
        {
            cout<<2<<endl;
            continue;
        }
        if(n%2==1)
        {
            cout<<func1(n)<<endl;
        }
        else
        {
            cout<<func2(n)<<endl;
        }
    }
    return 0;
}