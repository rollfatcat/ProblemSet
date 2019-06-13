/* 觀察輸入可以發現線段個數是40,000個但端點的範圍落在10,000,000之間 => 離散化
 * 關鍵：離散化導致的問題(同ZJ-b526)，參考第二筆測資
 * 目標：在相鄰两個數間距大於1時添加一個數
 * 作法：紀錄離散化的線段兩端點之外＋左端點往左一個單位和右端點往右一個單位
 * 原問題要求需要處理『顏色在同一區間重複覆蓋』問題，會使用到 lazy-update + set 紀錄更新覆蓋的顏色
 * 反向思考：改變覆蓋順序，讓同一個區段『只能被塗色一次』，若有其他顏色覆蓋時則直接 Return
 * 塗色後往回遞迴時需要做 Push-Up 維護區間內上色情況的正確性。
 * 修改一般 update() 的函數，會回傳現在的區間是否有更新成功(若有則計數+1)
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 40000

int qL, qR;
int srt[MAXN<<2]; // 點數最多四倍，兩端點＋其後各多一個
struct LINE{
  int st, ed;
} line[MAXN];
bool color[MAXN<<2];
void NewSeg(int nL,int nR,int pt){
  color[pt]=0;
  if(nL==nR) return;
  int nM=nL+nR>>1;
  NewSeg(nL,nM,pt<<1);
  NewSeg(nM+1,nR,pt<<1|1);
}
bool update(int nL,int nR,int pt){
  if(color[pt])// 這個區間已經被著色時就代表無法被覆蓋上新的顏色
    return false;
  if(qL<=nL and nR<=qR and color[pt]==0){ // 更新的部分落在區間內且該區間並未被塗色
    color[pt]=1;
    return true;
  }
  bool success=false; // 預設值
  int nM=nL+nR>>1;
  if(qL<=nM) success|=update(nL,nM,pt<<1);
  if(qR>nM ) success|=update(nM+1,nR,pt<<1|1);
  // 記得要做 Push-Up
  color[pt]=color[pt<<1]&color[pt<<1|1];
  return success;
}
int main(){
  int caseT, N, uN;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d",&N);
    uN=0;
    for(int i=0;i<N;i++)
      scanf("%d%d",&line[i].st,&line[i].ed),
      srt[uN++]=line[i].st-1,
      srt[uN++]=line[i].st,
      srt[uN++]=line[i].ed,
      srt[uN++]=line[i].ed+1;
    // 離散化
    sort(srt,srt+uN);
    uN=unique(srt,srt+uN)-srt;

    NewSeg(0,uN-1,1);
    int color_cnt=0;
    for(int i=N-1;i>=0;i--){
      qL=lower_bound(srt,srt+uN,line[i].st)-srt,
      qR=lower_bound(srt,srt+uN,line[i].ed)-srt;
      if(update(0,uN-1,1)) color_cnt++;
    }
    printf("%d\n",color_cnt);
  }
}
/*
2
5
1 4
2 6
8 10
3 4
7 10
6
1 3
4 6
6 7
8 10
1 2
3 4
*/