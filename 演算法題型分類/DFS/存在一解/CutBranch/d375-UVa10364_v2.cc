// 本來是枚舉每個筷子選或不選，這個版本是枚舉每個區段：11ms
// 剪枝：避免回朔時有區段閒置
#include<bits/stdc++.h>
using namespace std;
#define MAXN 20

int edgeLen, stickNum;
int stick[MAXN];
int buff[MAXN];

bool compare(int a,int b){ return a>b; }
bool DFS(int remEdge,int remStick,int nowS){
  // 只要能組好其中三邊, 第4邊就是拿剩餘的組出來, 前面有過篩所以一定成功
  if(remEdge==1) return true;
  // 如果剩餘的筷子數小於剩餘需要組裝的邊數時必定會失敗
  if(remEdge>remStick) return false;
  // 將現在棒子枚舉放入某一組區段內
  for(int i=0;i<4;i++){
    if(buff[i]+stick[nowS]>edgeLen) continue;
    buff[i]+=stick[nowS];
    if(DFS(remEdge-(buff[i]==edgeLen),remStick-1,nowS+1))
      return true;
    buff[i]-=stick[nowS];
    if(buff[i]==0) break; //<- 填區段的時候不能導致區段空置
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
    memset(buff,0,sizeof(buff));
    cout<<( (DFS(4,stickNum,0))?"yes\n":"no\n" );
  }
}