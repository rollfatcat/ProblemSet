// 枚舉每個筷子在現階段要不要選入(4ms)
#include<bits/stdc++.h>
using namespace std;
#define MAXN 20

int edgeLen, stickNum;
int stick[MAXN];
int use[MAXN];

bool compare(int a,int b){ return a>b; }
/* finish：已經完成的正方形邊數
 * nowLen：目前正在組的長度
 * start：下一次開始挑的棒子位置
 */
bool DFS(int nowLen,int start,int finish){
  // 只要能組好其中三邊, 第4邊就是拿剩餘的組出來, 前面有過篩所以一定成功
  if(finish==3) return true;
  // 現在組的這個邊長等於組成正方形邊長時換下一邊開始
  if(nowLen==edgeLen){
    int idx=0;
    while(use[idx] and idx<stickNum) idx++;
    use[idx]=finish+1; // 強迫選取屬於未使用過的集合中第一個片段，狀態標記
    if( DFS(stick[idx],idx+1,finish+1) )
      return true;
    use[idx]=0;
    return false;
  }
  // 不到正方形邊長繼續挑加一根棒子來組
  for(int i=start;i<stickNum;i++)
    if(use[i]==0 and nowLen+stick[i]<=edgeLen){
      use[i]=finish;
      if(DFS(nowLen+stick[i],i+1,finish))
        return true;
      use[i]=0;
    }
  return false;
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int caseT;
  cin>>caseT;
  while(caseT--){
    cin>>stickNum;
    int maxLen=0, totLen=0;
    for(int i=0;i<stickNum;i++)
      cin>>stick[i],
      totLen+=stick[i],
      maxLen=max(maxLen,stick[i]);

    edgeLen=totLen>>2;
    // 題目要求用給的全部棒子組成正方形
    // (1) 加總的邊長不是4的倍數時
    // (2) 最長的棒子大於能夠組出正方形的邊長
    if((totLen&3) or maxLen>edgeLen){ cout<<"no\n"; continue; }
    sort(stick,stick+stickNum,compare);
    memset(use,0,sizeof(use));
    use[0]=1;
    cout<<( (DFS(stick[0],1,0))?"yes":"no" )<<endl;
  }
}