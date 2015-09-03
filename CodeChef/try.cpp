    #include <bits/stdc++.h>
    using namespace std;
    unsigned long long int gcd(unsigned long long int a,unsigned long long int b)
    {
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
    }
    int main(int argc, char const *argv[])
    {
    unsigned long long int t;
    scanf("%llu",&t);
    while(t--)
    {
    unsigned long long int n,k,divisor,prodnum=1,proddenom=1,num,denom;
    scanf("%llu %llu",&n,&k);
    if(k>n)
    {
    cout<<0<<endl;
    continue;
    }	
    if(k>n/2)
    k=n-k;
    for(unsigned long long int i=0;i<k;i++)
    {
    num=(n-i);
    denom=(k-i);
    prodnum*=(num/(gcd(num,denom)));
    proddenom*=(denom/(gcd(num,denom)));
    }
    cout<<(prodnum/proddenom)<<endl;
    }
    return 0;
    } 