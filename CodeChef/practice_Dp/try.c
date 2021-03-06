    #include <iostream>
    #include <cstdio>
  //  using namespace std;
     
    //Looks like Python (without psyco) is not fast enough for this one. :(
    char chars[1001][1001];
    int board[1001][1001];
     
    int max(int x, int y){
    if(x>y) return x;
    else return y;
    }
     
    int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;++t){	
    int N;
    scanf("%d\n",&N);
    for(int i=0;i<N;i++) gets(chars[i]);
    bool knightFound = false;
    for(int c=N-1;c>=0;--c){
    for(int r=0;r<N;++r){
    int best = 0, curVal = (chars[r][c]=='P'?1:0);
    if (r-2>=0 && c+1<N) best = max(best, board[r-2][c+1]);
    if (r-1>=0 && c+2<N) best = max(best, board[r-1][c+2]);
    if (r+1<N && c+2<N) best = max(best, board[r+1][c+2]);
    if (r+2<N && c+1<N) best = max(best, board[r+2][c+1]);
    board[r][c] = curVal + best;
     
    if (chars[r][c]=='K'){
    printf("%d\n",board[r][c]);
    knightFound = true;
    break;
    }
    }
    if (knightFound) break;
    }
    }
    return 0;
    } 