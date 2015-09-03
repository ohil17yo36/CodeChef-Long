#include <bits/stdc++.h>
using namespace std;
inline int scan( )
{
	int n = 0;
	char c;
	for( c = getchar_unlocked(); c==' ' || c=='\n' || c == '\t'; c = getchar_unlocked());
	for( ; c > 0x2f && c < 0x3a; c = getchar_unlocked())
	n = (n * 10) + (c & 0x0f);
	return n;
}
std::vector<int> vec[105];
bool isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
 
        // Recur for all the vertices adjacent to this vertex
        std::vector<int>::iterator i;
        for(i = vec[v].begin(); i != vec[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
 
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}
 
// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in http://www.geeksforgeeks.org/archives/18212
bool isCyclic(int V)
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V+1];
    bool *recStack = new bool[V+1];
    for(int i = 1; i <= V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 1; i <= V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}
int main(int argc, char const *argv[])
{
	char stat[10];
	while(1)
	{
		int V,u,v;
		V=scan();
		if(V==0)
			break;
		for(int i = 1; i <=V; ++i)
		{
			u=scan();
			scanf("%s",stat);
			// printf("%s\n",stat );
			if(!strcmp(stat,"true"))
			{
				vec[i].push_back(u);
			}
			else
			{
				vec[u].push_back(i);
			}
		}
		if(!isCyclic(V))
			printf("PARADOX\n");
		else
			printf("NOT PARADOX\n");
		getchar_unlocked();
	}
	return 0;
}