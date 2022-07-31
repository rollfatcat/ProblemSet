/* 題目保證圓心只會落在Ｘ軸上，將圓的概念轉換成兩個落在Ｘ軸上的左右端點，重新定義問題要求
 * 枚舉每個圓並利用BIT統計其他圓和這個圓的關係
 * 假設有其他圓和目前這個圓的關係是『外離』：右端點小於目前圓的左端點 或者 左端點大於目前圓的右端點
 * 假設有其他圓和目前這個圓的關係是『內離』：左端點小於目前圓的左端點 且 右端點大於目前圓的右端點
 * (1) 將圓簡化成左右端點為一組的資料結構
 * (2) 輸入測資各自排序後離散化右端點的座標值
 * (3) 依據左端點數值由小到大排序的方式逐步更新，過程中利用BIT統計右端點的個數
 *     此時需要考慮到『萬一左端點都相同時的情況』:
 *     利用Queue紀錄此時圓的右端點，等到現在圓的左端點和紀錄中的左端點值不同時才一次更新
 *     因為這個關係需要額外一個 cntL 紀錄目前更新過的點數(注意不能是 i )
 * 因為更新順序確保越後面出現的圓左端點座標只會大於等於現在的圓左端點，對於內外離的處理可以再簡化：
 * 『外離』＝右端點小於目前圓的左端點，『內離』＝右端點大於目前圓的右端點
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=500002;
int BITR[MaxN]={};
int sR[MaxN], NumR;
struct CIRCLE{
  int sL, sR;
  CIRCLE(int a=0,int b=0):sL(a),sR(b){}
  bool operator<(const CIRCLE &rhs)const{ return sL<rhs.sL; }
}sC[MaxN];

inline void update(int st,int BIT[],int BITN){
  for(int pos=st; pos<BITN; pos+=lowbit(pos))
    BIT[pos]++;
}
inline int query(int st,int BIT[],int ret=0){
  for(int pos=st; 0<pos; pos-=lowbit(pos))
    ret+=BIT[pos];
  return ret;
}
inline void scanInt(int &x){
  char c=getchar();
  bool sign=c=='-';
  for(x=(sign)?0:(c-'0');(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
}
int main(){
  int N, O, R;
  scanInt(N);
  for(int i=1;i<=N;i++)
    scanInt(O),
    scanInt(R),
    sC[i]=CIRCLE(O-R,O+R),
    sR[i]=O+R;
  sort(sR+1,sR+N+1);
  sort(sC+1,sC+N+1);

  // 右端點離散化
  NumR=unique(sR+1,sR+N+1)-sR;

  // 枚舉每個點，針對內外離各自做判斷統計
  // 因為已經先將圓依據左端點排序過，越後面出現的圓左端點座標只會大於等於現在的圓左端點
  queue<int> Q;
  int nowL=sC[1].sL, cntL=0;
  long cnt=0;
  for(int tag,i=1;i<=N;i++){
    // 只有等到現在圓的左端點值不同於紀錄的左端點值時才把Queue裡的右端點值一次更新
    if(nowL!=sC[i].sL){
      cntL=i-1;
      nowL=sC[i].sL;
      while(Q.empty()==0)
        tag=lower_bound(sR+1,sR+NumR,Q.front())-sR,
        update(tag,BITR,NumR),
        Q.pop();
    }
    // 右端點小於目前圓的左端點
    tag=lower_bound(sR+1,sR+NumR,sC[i].sL)-sR;
    if(sC[i].sL<=sR[tag]) tag--;
    cnt+=query(tag,BITR);
    // 左端點小於目前圓的左端點 且 右端點大於目前圓的右端點
    tag=upper_bound(sR+1,sR+NumR,sC[i].sR)-sR-1;
    cnt+=cntL-query(tag,BITR);
    // 持續紀錄右端點值
    Q.push(sC[i].sR);
  }
  printf("%ld\n",cnt);
}