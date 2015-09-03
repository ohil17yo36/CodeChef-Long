#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	char str[] ="3 5";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ");
  }

	return 0;
}