#include <bits/stdc++.h>
#define lld long long int 
using namespace std;
lld arr[1000002];
lld tree[4000008];
lld lazy[4000008];
lld n,m,c;
lld u,v,k,p;
char ch;
inline int scan( );
void build_tree(lld node,lld a,lld b)
{
  if(a>b)
  return;
  if(a==b)
  {
    tree[node]=arr[a];
    return ;
  }
  build_tree(2*node,a,a+((b-a)/2));
  build_tree(2*node+1,1+a+((b-a)/2),b);
  tree[node]=(tree[2*node]+tree[2*node+1]);
}
void update_tree(lld node,lld a,lld b,lld i,lld j,lld value)
{
  if(lazy[node]!=0)
  {
    tree[node]+=lazy[node];
    if(a!=b)
    {
      lazy[2*node]+=lazy[node]; 
      lazy[2*node+1]+=lazy[node];
    }
    lazy[node]=0;
  }
  if(a>b||b<i||j<a)
    return ;
  if(a>=i && b<=j)
  {
    tree[node]+=value;
    if(a!=b)
    {
      lazy[2*node]+=value;
      lazy[2*node+1]+=value;
    }
    return ;
  }
  update_tree(2*node,a,a+((b-a)/2),i,j,value);
  update_tree(2*node+1,1+a+((b-a)/2),b,i,j,value);
  tree[node]=tree[2*node]+tree[2*node+1];
}
lld query_tree(lld node,lld a,lld b,lld i,lld j)
{
  if(a>b||b<i||j<a)
    return 0;
  if(lazy[node]!=0)
  {
    tree[node]+=lazy[node];
    if(a!=b)
    {
      lazy[2*node]+=lazy[node]; 
      lazy[2*node+1]+=lazy[node];
    }
    lazy[node]=0;
  }
  if(a==i && b==j)
  {
    return tree[node];
  }
  lld qleft=query_tree(2*node,a,a+((b-a)/2),i,j);
  lld qright=query_tree(2*node+1,1+a+((b-a)/2),b,i,j);
  return (qleft+qright);
}
int main(int argc, char const *argv[])
{
    n=scan();
    m=scan();
    c=scan();
    for (lld i = 0; i < n; ++i)
    {
      arr[i]=c;
    }
    build_tree(1,0,n-1);
    while(m--)
    {
      scanf(" %c",&ch);
      if(ch=='S')
      {
        u=scan();
        v=scan();
        k=scan();
        update_tree(1,0,n-1,u-1,v-1,k);
      }
      else
      {
        p=scan();
        cout<<query_tree(1,0,n-1,p-1,p-1)<<endl;
      }
    }
  return 0;
}
inline int scan( )
{
int n = 0;
char c;
for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
n = (n * 10) + (c & 0x0f);
return n;
} 