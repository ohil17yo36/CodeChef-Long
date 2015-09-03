#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct trienode
{
	int keynumber;
	struct trienode *child[26];
};
struct trienodeinit
{
	struct trienode *root;
	int keycount;
};
struct trienode * newNode()
{
	int i;
	struct trienode *temp;
	temp=(struct trienode *)malloc(sizeof(struct trienode));
	temp->keynumber=0;
	for ( i = 0; i < 26; ++i)
	{
		temp->child[i]=NULL;
	}
	return temp;
}
void initialise(struct trienodeinit *trie)
{
	trie->keycount=0;
	trie->root=newNode();
}
void insert(struct trienodeinit *trie,char *key)
{
	int length=strlen(key);
	int i=0;
	trie->keycount++;
	struct trienode *temp=trie->root;
	for(i=0;i<length;i++)
	{
		if(temp->child[key[i]-'a']==NULL)
		{
			temp->child[key[i]-'a']=newNode();
		}
		temp=temp->child[key[i]-'a'];
	}
	temp->keynumber=trie->keycount;
}
void search(struct trienodeinit *trie,char *searchkey)
{
	int length=strlen(searchkey);
	int i=0;
	struct trienode *temp=trie->root;
	for(i=0;i<length;i++)
	{
		if(temp->child[searchkey[i]-'a']==NULL)
		{
			printf("Search key does not exist\n");
			return ;
		}
		temp=temp->child[searchkey[i]-'a'];
	}
	if(temp->keynumber!=0)
	printf("The Search key exists\n");
	else
	printf("Search key does not exist\n");
}
int main(int argc, char const *argv[])
{
	struct trienodeinit trie;
	char key[100]={'a','b','c'};
	char searchkey[100]={'a','b'};
	initialise(&trie);
	insert(&trie,key);
	search(&trie,searchkey);
	return 0;
}