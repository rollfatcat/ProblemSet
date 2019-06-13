// 很有趣的難題，不知道為何不能用set來寫會 RE(SIGSEGV)
// 01背包問題，但是注意 overflow 導致的更新方式會完全不同
// 解法出處：https://www.ptt.cc/bbs/C_and_CPP/M.1536758808.A.996.html
#include<iostream>
using namespace std;
#define MaxL 700000

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int w, cnt, i, j;
  char DP[MaxL+1]={0}; // 記錄這個位置是在第i次時被更新的

  for(cin>>cnt, i=1; i<=cnt; i++)
    for(cin>>w, j=1; j<=MaxL; j++){ //順向更新，確保overflow時也可以更新
      if(DP[j] and DP[j]!=i){
        int updatePos=(j+w-1)%MaxL+1;
        if(!DP[updatePos])
          DP[updatePos]=i;
      }else if(j==w)
        DP[j]=i;
    }
  for(i=MaxL;!DP[i];i--);
  cout<<i<<endl;
}
/*
3
699999 2 699999
-----------------
700000
*/