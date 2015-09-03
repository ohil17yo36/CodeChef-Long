#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
 
int MIN(int a,int b)
{
    if(a<b)
    return a;
    else return b;
}
struct Node{
int index;
int cost;
Node (int in,int c)
{
    index=in;
    cost = c;
}
 
};
class compareN {
 public:
 bool operator()(Node& n1,
                 Node& n2){
 return (n1.cost > n2.cost);
 }
 };
 
int d1[10010];
int d2[10010];
vector<int> v1[10010];
vector<int> v2[10010];
 int main()
{
    int test;
    scanf("%d",&test);
 
    while(test-->0)
    {
        int n,m,k,s,t;
        scanf("%d %d %d %d %d",&n,&m,&k,&s,&t);
        for (int i=0;i<n;i++){
        v1[i].clear();
        v2[i].clear();
        }
 
        for (int i=0;i<m;i++)
        {
            int x,y,c;
            scanf("%d %d %d",&x,&y,&c);
            v1[x].push_back(y);
            v1[x].push_back(c);
            v2[y].push_back(x);
            v2[y].push_back(c);
        }
        priority_queue<Node,vector<Node>,compareN> q1;
        priority_queue<Node,vector<Node>,compareN> q2;
 
        q1.push(Node(s,0));
        q2.push(Node(t,0));
        for(int i=0;i<=n;i++)
            d1[i]=d2[i]=100000000;
        d1[s]=0;
        d2[t]=0;
        while(!q1.empty())
        {
            Node node = q1.top();
            q1.pop();
            for(int i=0;i<(int)v1[node.index].size();i+=2)
            {
                int x = v1[node.index][i];
                int y = v1[node.index][i+1];
                if(d1[x]>d1[node.index]+y){
                d1[x] = d1[node.index]+y;
                q1.push(Node(x,d1[x]));
                }
            }
        }
        while(!q2.empty())
        {
            Node node = q2.top();
            q2.pop();
            for(int i=0;i<(int)v2[node.index].size();i+=2)
            {
                int x = v2[node.index][i];
                int y = v2[node.index][i+1];
                if(d2[x]>d2[node.index]+y)
                {d2[x] = d2[node.index]+y;
                 q2.push(Node(x,d2[x]));
                }
            }
        }
        int min = d1[t];
 
        while(k-->0)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
 
            if(d1[x]<d1[y])
            {
                min = MIN(min,d1[x]+fabs(d1[y]-d1[t])+z);
            }
            else {
                min = MIN(min,d1[y]+fabs(d1[x]-d1[t])+z);
            }
        }
        if(min==100000000)
            printf("-1\n");
        else printf("%d\n",min);
 
 
    }
    return 0;
}