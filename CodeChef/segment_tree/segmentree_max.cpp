#include <bits/stdc++.h>
using namespace std;

#define lli long long int 
// #define N 20
// #define MAX (1+(1<<6)) // Why? :D
#define inf 0x7fffffff
lli N=15,m,L,R; 
lli arr[50050];
lli tree[200200];
 
/**
* Build and init tree
*/
void build_tree(lli node, lli a, lli b) {
if(a > b) return; // Out of range
if(a == b) { // Leaf node
tree[node] = arr[a]; // Init value
return;
}
build_tree(node*2, a, (a+b)/2); // Init left child
build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
tree[node] = max(tree[node*2], tree[node*2+1]); // Init root value
}
 
/**
* Increment elements within range [i, j] with value value
*/
void update_tree(lli node, lli a, lli b, lli i, lli j, lli value) {
if(a > b || a > j || b < i) // Current segment is not within range [i, j]
return;
if(a == b) { // Leaf node
tree[node] += value;
return;
}
 
update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
 
tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
}
 
/**
* Query tree to get max element value within range [i, j]
*/
lli query_tree(lli node, lli a, lli b, lli i, lli j) {
if(a > b || a > j || b < i) return -inf; // Out of range
 
if(a >= i && b <= j) // Current segment is totally within range [i, j]
return tree[node];
 
lli q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
lli q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child
 
lli res = max(q1, q2); // Return final result
return res;
}
 
int main() {
for(lli i = 0; i < N; i++) arr[i] = 1;
 
build_tree(1, 0, N-1);
 
update_tree(1, 0, N-1, 0, 6, 5); // Increment range [0, 6] by 5
update_tree(1, 0, N-1, 7, 10, 12); // Incremenet range [7, 10] by 12
update_tree(1, 0, N-1, 10, N-1, 100); // Increment range [10, N-1] by 100
 
cout << query_tree(1, 0, N-1, 0, N-1) << endl; // Get max element in range [0, N-1]
	// scanf("%lld",&N);
	// for(lli i=0;i<N;i++)
	// 	scanf("%lld",&arr[i]);
	// build_tree(1,0,N-1);
	// scanf("%lld",&m);
	// getchar();
	// while(m--)
	// {
	// 	scanf("%lld %lld",&L,&R);
	// 	getchar();
	// 	printf("%lld\n",query_tree(1,0,N-1,L-1,R-1));
	// }
return 0;
} 		