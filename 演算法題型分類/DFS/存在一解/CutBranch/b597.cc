/* (難度極高)剪枝練習：
 * (1) 測試長度必定是總長度的因數，且測試長度必定大於等於最長的片段
 * (2) 假設目前的測試長度可以成功，則nowLen=0時選取的那個片段
 *     往下遞迴嘗試時若失敗則表示假設錯誤
 *     (假設成功的話則該片段必定屬於某個集合 => 往下遞迴必定會成功)
 * (3) 在同一層DFS時避免選取到同個長度的片段
 * 2ms版本是錯誤的 => 測資：15 34 38 10 44 45 7 13 30 44 43 47 43 27 38 5
 * 實際AC版本是1.2s
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=50;
int prime_num=15;
int prime[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int stickNum, maxLen;
int edgeLen, edgeNum;
int stick[MAXN];
bool use[MAXN];

vector<int> base, power, posLen;

bool compare(int a,int b){ return a>b; }
void Find_Factor(int mul, int now){
  if(now==base.size())  return;
  Find_Factor(mul,now+1);
  for(int i=1;i<=power[now];i++){
    mul*=base[now];
    if(mul>=maxLen)
      posLen.push_back(mul);
    Find_Factor(mul,now+1);
  }
}
bool DFS(int nowLen, int start,int finish){
  if(finish==edgeNum-1) return true;
  // 只有當nowLen=0時挑選未選取區的第一個片段往下遞迴若失敗就回傳
  // 往下遞迴嘗試時若失敗則表示假設錯誤(反證法)
  // (假設成功的話則該片段必定屬於某個集合 => 往下遞迴必定會成功)
  if(nowLen==edgeLen){
    int idx=0; // 從頭開始找到下一個未被選取的片段
    while(use[idx] and idx<stickNum) idx++;
    use[idx]=1; // 強迫選取屬於未使用過的集合中第一個片段，狀態標記
    if( DFS(stick[idx],idx+1,finish+1) )
      return true;
    use[idx]=0;
    return false;
  }
  int preLen=0; // 避免(在同一層DFS)嘗試時重複選取『長度相等』的片段
  for(int i=start;i<stickNum;i++)
    if(use[i]==0 and preLen!=stick[i] and nowLen+stick[i]<=edgeLen){
      preLen=stick[i];
      use[i]=1;
      if(DFS(nowLen+stick[i],i+1,finish))
        return true;
      use[i]=0;
    }
  return false;
}

int main(){
  while(scanf("%d",&stickNum) and stickNum){
    int totLen=0;
    for(int i=0;i<stickNum;i++)
      scanf("%d",&stick[i]),
      totLen+=stick[i];
    sort(stick,stick+stickNum,compare);
    maxLen=stick[0];

    // 質因數分解，找出所有可能的邊長(因數)，可能邊長至少會大於等於最大邊長
    base.clear(),
    power.clear();
    int number=totLen;
    for(int p,i=0;i<prime_num and number>1;i++){
      for(p=0;number%prime[i]==0;number/=prime[i],p++);
      if(p) base.push_back(prime[i]), power.push_back(p);
    }
    if(number>1) base.push_back(number), power.push_back(1);
    posLen.clear();
    Find_Factor(1,0);
    // 如果可能邊長只有一個則直接輸出
    if(posLen.size()==1){ printf("%d\n",posLen[0]); continue; }
    // 由大到小排序片段(加速選取)
    sort(posLen.begin(),posLen.end());
    memset(use,0,sizeof(use));
    for(int x:posLen){
      edgeLen=x,
      edgeNum=totLen/x;
      // 強迫選取第一個(如果可以完整合成，則該片段必定屬於某一個集合)
      use[0]=1;
      if(DFS(stick[0],1,0)){
        printf("%d\n",edgeLen);
        break;
      }
    }
  }
}
// 15 34 38 10 44 45 7 13 30 44 43 47 43 27 38 5
// 47 45 44 44 43 43 38 38 34 30 27 13 10 7 5
// (47,45,13,7,5)+(44,43,30)+[44,43,38,38,34,27,10]