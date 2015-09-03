#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
inline long long int scan( )
{
long long int n = 0;
char c;
for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
n = (n * 10) + (c & 0x0f);
return n;
}
long long int counti,length;
vector<long long int>v[100005];
vector<bool>visited;
void dfs(long long int u)
{
    visited[u]=true;
    length++;
    for (std::vector<long long int>::iterator i = v[u].begin(); i != v[u].end(); ++i)
    {
        if(visited[*i]==false)
        dfs(*i);    
    }
}
int main(int argc, char const *argv[])
{
    long long int t,n,m,i,j,res;
    t=scan();
    while(t--)
    {
        counti=0,res=1;
        n=scan(),m=scan();
        visited.clear();
        for ( i = 0; i < n; ++i)
        {
           v[i].clear();
           visited.push_back(false);
        }
        while(m--)
        {
            i=scan();
            j=scan();
            i--;
            j--;
            v[i].push_back(j);
            v[j].push_back(i);
        }
     
        for ( i = 0; i < n; ++i)
        {
            if(visited[i]==false)
            {
                counti++;
                length=0;
                dfs(i);
                res*=length;
                res%=mod;

            }
        }
        
        cout<<counti<<" "<<res<<endl; 
    }
    return 0;
}