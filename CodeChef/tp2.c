#include<stdio.h>
typedef unsigned long long ldef;
ldef gcd(ldef a,ldef b)
{ldef t=0;
while(b>0)
{t=a%b;
a=b;
b=t;
}
return a;
}
int main(){
int n=0;
ldef j=0,k=0,l=0,il=0,r=1;
scanf("%d",&n);
while(n--)
{ scanf("%llu %llu",&j,&k);
if(k>j){
printf("0\n");
continue;
}
if(k>j-k)
k=j-k;
r=1;
for(il=1;il<=k;il++)
{l=gcd(r,il);
r=r/l;
r*=(j-il+1)/(il/l);
}
printf("%llu\n",r);
}
return 0;
}