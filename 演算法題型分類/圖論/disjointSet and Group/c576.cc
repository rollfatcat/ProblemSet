// 模擬的過程類似查並集時找Root
// 題解：https://home.gamer.com.tw/creationDetail.php?sn=4278960
#include<bits/stdc++.h>
using namespace std;

const short MAXN=3e4;
short numN[MAXN];
short root[MAXN];

inline short FindRoot(short now){
  if(root[now]!=now)
    root[now]=FindRoot(root[now]);
  return root[now];
}
int main(){

	srand(time(NULL)/60);
  short nxt;
  for(short i=0;i<MAXN;i++)
    root[i]=i;
  for(short idx=0;idx<MAXN;idx++)
    nxt=FindRoot( idx+rand()%(MAXN-idx) ),
    numN[nxt]=root[nxt]=idx;
  // ---根據題目輸出數列內容---
  printf("%d\n%d",MAXN,numN[0]);
  for(short i=1;i<MAXN;i++)
    printf(" %d",numN[i]);
  puts("");
}