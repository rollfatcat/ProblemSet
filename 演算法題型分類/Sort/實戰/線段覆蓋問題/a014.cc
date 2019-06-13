// 紀錄的方式類似BIT＋掃描線作法，作法類似『莫隊』算法
// 單看一下會以為需要什麼演算法，沒有就直接模擬夾子移動(枚舉每一格的情況)
// 將娃娃視為兩個端點分別紀錄在nL和nR兩個陣列，而不是一個線段來檢測覆蓋情況
#include<iostream>
#include<cstring>
using namespace std;

int nL[100001]={}, nR[100001]={};
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  for(int N,L; scanInt(N) and scanInt(L);){
    memset(nL,0,sizeof(nL));
    memset(nR,0,sizeof(nR));
    int maxR=0; // 紀錄右邊界的上限
    for(int i=0,x,y;i<N;i++){
      scanInt(x),
      scanInt(y);
      if(y-x>L)//娃娃的寬度大於夾子(無法夾起就不紀錄)
        continue;
      nL[x]++,
      nR[y]++;
      maxR=max(maxR,y);
    }
    int cnt_inL=0, cnt_max=0, ans_num=0;
    // 當夾子的左端點在位置0的時候，
    // 直接統計落在夾子右端點內所有的娃娃(娃娃右端點也落在夾子右端點)
    for(int i=1;i<=L;i++)
      cnt_inL+=nR[i];
    // 題目定義：夾子的範圍涵蓋娃娃大小=夾起，夾子的範圍(ed-L,ed)有(L+1)個整數
    // 枚舉每個位置移動(線性搜索)
    for(int ed=L+1;ed<=maxR;ed++){
      cnt_inL+=nR[ed];
      if(cnt_max<cnt_inL) // 更新最佳的夾取地點上限，且此時個數＝1
        cnt_max=cnt_inL,
        ans_num=1;
      else if(cnt_max==cnt_inL) // 目前可夾取的數量等於最佳的夾取地點，且此時個數+1
        ans_num++;
      cnt_inL-=nL[ed-L];
    }
    // 夾子可以繼續往右邊移動(娃娃機的右邊界是無限的)不過 nR[x]都是0，所以就不計算只扣除nL[x]
    for(int st=maxR+1-L;st<=maxR and cnt_inL==cnt_max; st++)
      ans_num++,
      cnt_inL-=nL[st];
    printf("%d %d\n",ans_num,cnt_max);
  }
}