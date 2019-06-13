// 這是不剪枝的版本(0.2s) 剪枝版本(19ms) 狀態壓縮版本(11ms)
#include<iostream>
#include<algorithm>
using namespace std;
#define MaxN 20

int stick[MaxN], m, edgeLen;
bool use[MaxN], HasAns;

bool compare(int a,int b){ return a>b; }
/* finish：已經完成的正方形邊數
 * nowLen：目前正在組的長度
 * start：下一次開始挑的棒子位置
 */
void DFS(int finish, int nowLen, int start){
  // 只要能組好其中三邊, 第4邊就是拿剩餘的組出來, 前面有過篩所以一定成功
  if(finish==3){ HasAns=true; return; }
  // 現在組的這個邊長等於組成正方形邊長時換下一邊開始
  if(nowLen==edgeLen){
    for(int i=0;i<m;i++)
      if(use[i]==0 and stick[i]<=edgeLen){
        use[i]=1;
        DFS(finish+1,stick[i],i+1);
        use[i]=0;
      }
  } else { // 不到正方形邊長繼續挑加一根棒子來組
    for(int i=start;i<m;i++)
      if(use[i]==0 and nowLen+stick[i]<=edgeLen){
        use[i]=1;
        DFS(finish,nowLen+stick[i],i+1);
        use[i]=0;
      }
  }
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int T, maxLen, total;

  cin>>T;
  while(T--){
    cin>>m;
    maxLen=total=0;
    for(int i=0;i<m;i++){
      cin>>stick[i];
      total+=stick[i];
      if(maxLen<stick[i])
        maxLen=stick[i];
    }
    edgeLen=total/4;
    // 題目要求用給的全部棒子組成正方形
    // (1) 加總的邊長不是4的倍數時
    // (2) 最長的棒子大於能夠組出正方形的邊長
    if(total%4 or maxLen>edgeLen) cout<<"no\n";
    else{
      sort(stick,stick+m,compare);
      fill(use,use+m,0);
      HasAns=false;
      DFS(0,0,0);
      if(HasAns)  cout<<"yes\n";
      else cout<<"no\n";
    }
  }
}