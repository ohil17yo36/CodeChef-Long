#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define lli long long int
lli n,k,num;
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	ofstream fout;
	n=rand()%100 + 1;
	k=rand()%100001;
	fout.open("inp.txt");
	fout<<n<<" "<<k<<endl;
	for(lli i=0;i<n;i++)
		fout<<rand()%100000 +1<<" ";
	fout<<endl;
	return 0;
}