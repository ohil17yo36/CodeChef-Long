#include <bits/stdc++.h>
using namespace std;
#define lli long long int
inline lli scan( )
{
	lli n1 = 0;
	char ch;
	for( ch = getchar_unlocked(); ch==' ' || ch=='\n' || ch == '\t'; ch = getchar_unlocked());
	for( ; ch > 0x2f && ch < 0x3a; ch = getchar_unlocked())
	n1 = (n1 * 10) + (ch & 0x0f);
	return n1;
}
lli t;
int main(int argc, char const *argv[])
{
	
	return 0;
}