    #include <cstdio>
    #include <cstdlib>
    #include <vector>
    using namespace std;
    #define lli long long int
    #define mod 1000000007
    inline lli scan( )
    {
    lli n1 = 0;
    char c;
    for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
    for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
    n1 = (n1 * 10) + (c & 0x0f);
    return n1;
    }
     
    lli t,n,q,idx,k,count[5005],ans[5005];
    lli factorial[5005];
    char ch,str[5005];
     
    struct trie_node
    {
    lli substr_cnt;
    std::vector<int> child_index;
    struct trie_node *child[26];
    }*root;
     
    struct trie_node *newNode()
    {
    struct trie_node *temp;
    temp=(struct trie_node *)malloc(sizeof(struct trie_node));
    temp->substr_cnt=1;
    temp->child_index.clear();
    for(int i=0;i<26;i++)
    temp->child[i]=NULL;
    return temp;
    }
     
    
     
    void insertWord(lli start)
    {
    struct trie_node *temp=root;
    for(lli i=start;i<n;i++)
    {
    if(temp->child[str[i]-'a']==NULL)
    {
        temp->child[str[i]-'a']=newNode();
        temp->child_index.push_back(str[i]-'a');
    }
    else
    temp->child[str[i]-'a']->substr_cnt++;
    temp=temp->child[str[i]-'a'];
    }
    }
     
    void traverse(struct trie_node *temp)
    {
        for (std::vector<int>::iterator i = temp->child_index.begin(); i != temp->child_index.end(); ++i)
        {
            count[temp->child[*i]->substr_cnt]++;
            traverse(temp->child[*i]);
        }    
    }
     
    void factorialinit(lli N)
    {
    factorial[0]=1;
    for(lli i=1;i<N;i++)
    {
    factorial[i]=(factorial[i-1]*i);
    if(factorial[i]>=mod)
    factorial[i]=factorial[i]%mod;
    }
    }
    void ExtEuc(long long int a,long long int b,long long int& x,long long int& y)
    {
    if(a%b==0)
    {
    x=0;
    y=1;
    return;
    }
    ExtEuc(b,a%b,x,y);
    long long int temp=x;
    x=y;
    y=(temp-y*(a/b));
    }
    long long int InverseEuler(long long int a)
    {
    lli m=mod;
    long long int x,y;
    ExtEuc(a,m,x,y);
    if(x<0)
    x+=m;
    return x;
    }
    lli nck_fast(lli N1,lli M1)
    {
    if(M1==0 || M1==N1)
    return 1;
    if(M1==1 || M1==(N1-1))
    return N1%mod;
    lli res;
    lli No=N1%mod;
    N1/=mod;
    lli Mo=M1%mod;
    M1/=mod;
    if(Mo>No)
    res=0;
    else	
    res=(((((((factorial[No])*(InverseEuler(factorial[Mo])))%mod)*((InverseEuler(factorial[No-Mo]))))%mod)%mod)*((((((factorial[N1])*(InverseEuler(factorial[M1])))%mod)*((InverseEuler(factorial[N1-M1]))))%mod)%mod))%mod;
      return res;
    }
   
     
    int main(int argc, char const *argv[])
    {
    factorialinit(5005);
    t=scan();
    while(t--)
    {
    n=scan(),q=scan(),idx=0;
    while((ch=getchar_unlocked())!='\n')
    str[idx++]=ch;
    str[idx]='\0';
    
    root=newNode();
    root->substr_cnt=0;
    for(lli i=0;i<n;i++)
    insertWord(i),count[i]=0;
    count[n]=0;
    traverse(root);
    for(lli i=1;i<=n;i++)
    {
    ans[i]=0;
    for(lli j=i;j<=n;j++)
    if(count[j]>0)
    {
    ans[i]=(ans[i]+((count[j])*nck_fast(j,i)));
    if(ans[i]>=mod)
    ans[i]=ans[i]%mod;
    }
    }
    
    while(q--)
    {
    scanf("%lld",&k);
    if(k>n || k<1)
    printf("0\n");
    else
    printf("%lld\n",ans[k]);
    }
    }	
    return 0;
    } 