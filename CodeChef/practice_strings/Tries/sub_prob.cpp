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
char ch,str[100005],str2[5000];

struct trie_node
{
	lli substr_cnt;
	struct trie_node *child[26];
}*root;

struct trie_node *newNode()
{
	struct trie_node *temp;
	temp=(struct trie_node *)malloc(sizeof(struct trie_node));
	temp->substr_cnt=1;
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
	scanf("%s",&str);
		
	return 0;
}