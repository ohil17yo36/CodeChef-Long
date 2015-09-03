#include <bits/stdc++.h>
#include <fstream>
#define m 1000000007;
#define pb push_back
#define mp make_pair
#define f first
#define s second
     
using namespace std;
long long arr[100005];
long long tree[400005];
     
vector < pair <long long,long long> > lazy[400005];
     
     
void build_tree(int node, int a, int b)
{
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
void update_tree(long node,long long a,long long b,long i,long j,int type,long long value)
{
    long p;
    if(!lazy[node].empty())
    {
        for(p=0;p<lazy[node].size();p++)
            if(lazy[node][p].s==1)
            {
                tree[node]+=((b-a+1)*lazy[node][p].f)%m;
                tree[node]%=m;
            }
            else if(lazy[node][p].s==2)
            {
                tree[node]*=(lazy[node][p].f)%m;
                tree[node]%=m;
            }
            else
            {
                tree[node]=((b-a+1)*lazy[node][p].f)%m;
            }
    
        if(a != b)
        {
            for(p=0;p<lazy[node].size();p++)
            {
                if(lazy[node][p].s==3)
                {
                    lazy[node*2].clear();
                    lazy[node*2+1].clear();
                }
                lazy[node*2].pb(lazy[node][p]);
                lazy[node*2+1].pb(lazy[node][p]);
            }
        }
        lazy[node].clear();
    }
    if(a > b || a > j || b < i) // Current segment is not within range [i, j]
        return;
    if(a >= i && b <= j)
    {
        if(type==1)
        {
            tree[node]+=((b-a+1)*value)%m;
            tree[node]%=m;
            if(a != b)
            {
                lazy[node*2].pb(mp(value,type));
                lazy[node*2+1].pb(mp(value,type));
            }
        }
        else if(type==2)
        {
            tree[node]*=(value)%m;
            tree[node]%=m;
            if(a != b)
            {
                lazy[node*2].pb(mp(value,type));
                lazy[node*2+1].pb(mp(value,type));
            }
        }
        else
        {
            tree[node]=((b-a+1)*value)%m;
            if(a != b)
            {
                lazy[node*2].clear();
                lazy[node*2+1].clear();
                lazy[node*2].pb(mp(value,type));
                lazy[node*2+1].pb(mp(value,type));
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
    long p;
    if(!lazy[node].empty())
    {
        for(p=0;p<lazy[node].size();p++)
            if(lazy[node][p].s==1)
            {
                tree[node]+=((b-a+1)*lazy[node][p].f)%m;
                tree[node]%=m;
            }
            else if(lazy[node][p].s==2)
            {
                tree[node]*=(lazy[node][p].f)%m;
                tree[node]%=m;
            }
            else
            {
            tree[node]=((b-a+1)*lazy[node][p].f)%m;
            }

        if(a != b)
        {
            for(p=0;p<lazy[node].size();p++)
            {
                if(lazy[node][p].s==3)
                {
                    lazy[node*2].clear();
                    lazy[node*2+1].clear();
                }
            lazy[node*2].pb(lazy[node][p]);
            lazy[node*2+1].pb(lazy[node][p]);
            }
        }
        lazy[node].clear();
    }
    if(a >= i && b <= j) // Current segment is totally within range [i, j]
    {
        return tree[node];
    }
    long long q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
    long long q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child
    long long res =(q1+q2)%m; // Return final result
    return res;
}
int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("inp.txt");
    fout.open("Ediff.txt");
    long long n,q,v,ans,i;
    long x,y;
    int type;
    // scanf("%lld%lld",&n,&q);
    fin>>n>>q;
    for(i=0;i<n;i++)
        fin>>arr[i];// scanf("%lld",arr+i);
    build_tree(1,0,n-1);
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
            x++;y++;
        update_tree(1,0,n-1,x-1,y-1,type,v);
        }
    }
        return 0;
}