#include <cstdio>
#include <cstdlib>
#include <vector>
#define lli long long int
#define mod 1000000007
using namespace std;
inline lli scan( )
{
	register lli n1 = 0;
	char c;
	for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
	for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
	n1 = (n1 * 10) + (c & 0x0f);
	return n1;
}

lli t,n,q,idx,k,count[5005],ans[5005],nckdp[5005][5005];
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


int main(int argc, char const *argv[])
{
	for(lli i=0;i<5002;i++)
		nckdp[i][i]=1,nckdp[i][0]=1;
	for(lli i=2;i<5002;i++)
	{
		for(lli j=1;j<=(i/2);j++)
		{
			nckdp[i][j]=(nckdp[i-1][j-1]+nckdp[i-1][j]);
			if(nckdp[i][j]>=mod)
				nckdp[i][j]-=mod;
			nckdp[i][i-j]=nckdp[i][j];
		}
	}
	t=scan();
	while(t--)
	{

		n=scan(),q=scan(),idx=0;
		while((ch=getchar_unlocked())!='\n')
			str[idx++]=ch;
		str[idx]='\0';
		for(lli i=0;i<=n;i++)
			count[i]=0;
		root=newNode();
		root->substr_cnt=0;
		for(lli i=0;i<n;i++)
			insertWord(i);
		traverse(root);
		// for(lli i=1;i<=n;i++)
		// printf("%lld ",count[i]);
		// printf("\n");	

		// for(int i=n-1; i>0; i--)
  //   	{
  //   		count[i]=count[i]+count[i+1];
  //   		//printf("%lld %d %lld\n",ans[i],i,ans[i+1]);
  //   	}
    	// for(int i=0;i<n;i++)
    	// 	printf("frequency %d:-%lld ",i,count[i]);
    	// printf("\n");
		for(lli i=1;i<=n;i++)
		{
			ans[i]=0;
			for(lli j=i;j<=n;j++)
				if(count[j]>0)
				{
					ans[i]=(ans[i]+(count[j]*nckdp[j][i]));
					if(ans[i]>=mod)
						ans[i]=ans[i]%mod;
				}
		}

		while(q--)
		{
			k=scan();
			if(k>n || k<1)
				printf("0\n");
			else
				printf("%lld\n",ans[k]);
		}
		free(root);
	}	
	return 0;
}