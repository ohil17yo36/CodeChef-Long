#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define lli long long int
lli t=3,n,h=5,l,r;
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	ofstream fout;
	fout.open("input.txt");
	fout<<t<<endl;
	while(t--)
	{
		n=rand()%10000 + 1;
		fout<<n<<" "<<h<<endl;
		for(lli i=0;i<n;i++)
		{
			l=rand()%n;
			r=rand()%n;
			fout<<l<<" "<<r<<endl;
		}
	}
	return 0;
}