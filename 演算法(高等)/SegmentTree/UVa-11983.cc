// 標準的線段樹＋掃描線＋離散化(需要離散化兩個維度的座標) => 0.28s
/* 花很多時間在處理兩個Debug
 * (1) SegmentTree的 seg_add[] 和 seg_sum[] 空間需要8倍
       (因為實作時會把N個矩形拆成2N個線段，所以總數需要4x2倍，這個bug會以TLE顯示而非SE)
 * (2) PushUp時因為離散化的關係需要考慮更新的節點是不是葉節點
 * 根據更新的特性可以寫成 zkw式線段樹
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=30005;
int Posy[MAXN<<1];
int N, qB, qL, qR, qD;
struct LINE{
  int x, d, u, t;
  LINE(int x=0,int d=0,int u=0,int t=0):x(x),d(d),u(u),t(t){}
  bool operator<(const LINE &rhs)const{ return x<rhs.x; }
}line[MAXN<<1];
int seg_add[MAXN<<3], seg_sum[MAXN<<3][11];

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
void BuildTree(int nL,int nR,int pt){
  seg_add[pt]=0;
  memset(seg_sum[pt],0,sizeof(seg_sum[pt]));
  seg_sum[pt][0]=Posy[nR+1]-Posy[nL];
  if(nL==nR)  return;
  int nM=(nL+nR)>>1;
  BuildTree(  nL,nM,  pt<<1);
  BuildTree(nM+1,nR,pt<<1|1);
}
inline void PushUp(int nL,int nR,int pt){
  memset(seg_sum[pt],0,sizeof(seg_sum[pt]));
  if(nL==nR){
    seg_sum[pt][ min(qB,seg_add[pt]) ]=Posy[nR+1]-Posy[nL];
    return;
  }
  for(int i=0;i<=qB;i++)
    seg_sum[pt][ min(qB,i+seg_add[pt]) ]+=seg_sum[pt<<1][i]+seg_sum[pt<<1|1][i];
}
void Update(int nL,int nR,int pt){
  if(qL<=nL and nR<=qR){
    seg_add[pt]+=qD;
    PushUp(nL,nR,pt);
    return;
  }
  int nM=(nL+nR)>>1;
  if(qL<=nM) Update(  nL,nM,  pt<<1);
  if(qR>nM)  Update(nM+1,nR,pt<<1|1);
  PushUp(nL,nR,pt);
}
int main(){
  int T;
  scanInt(T);
  for(int caseN=1;caseN<=T;caseN++){
    scanInt(N);
    scanInt(qB);
    // ---讀取輸入---
    int x1, x2, y1, y2;
    for(int i=0;i<N;i++){
      scanInt(x1),
      scanInt(y1),
      scanInt(x2),
      scanInt(y2);
      x2++, y2++;
      Posy[ i ]=y1,
      Posy[i+N]=y2;
      line[ i ]=LINE(x1,y1,y2, 1),
      line[i+N]=LINE(x2,y1,y2,-1);
    }
    // ---Sort and Discretization---
    int tot=N<<1;
    sort(line,line+tot);
    sort(Posy,Posy+tot);
    int nN=unique(Posy,Posy+tot)-Posy;
    // ---建表時注意如何將離散後的點轉成線段的長度---
    // 線段的右端點號碼代表該線段編號 => Ｎ個離散化後的點代表Ｎ-1個線段
    BuildTree(0,nN-2,1);

    // ---Main Function---
    long ans=0;
    qL=lower_bound(Posy,Posy+nN,line[0].d)-Posy;
    qR=lower_bound(Posy,Posy+nN,line[0].u)-Posy-1;
    qD=line[0].t;
    Update(0,nN-2,1);
    for(int i=1;i<tot;i++){
      ans+=(line[i].x-line[i-1].x)*(long)seg_sum[1][qB];
      printf("%d\n",seg_sum[1][qB]);
      qL=lower_bound(Posy,Posy+nN,line[i].d)-Posy;
      qR=lower_bound(Posy,Posy+nN,line[i].u)-Posy-1;
      qD=line[i].t;
      Update(0,nN-2,1);
    }
    printf("Case %d: %ld\n",caseN,ans);
  }
}
/*
2
3 1
0 0 4 4
1 1 2 5
0 1 2 4

3 1
0 0 1 1
1 1 2 2
2 2 3 3
*/