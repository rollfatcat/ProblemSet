// 題解:https://www.kancloud.cn/digest/acarthur/166633
// 題目需支援區間查詢/區間設定(0.7s)
/* 有3種區間操作：(1)將某個區間全部變成1 (2)將某個區間全部變成0 (3)區間內的狀態反轉
 * 思路：前兩個操作就是最基本的區間更新， 用到懶惰標記，
 *       然而狀態反轉是這題的核心：向下子節點傳遞標記時造成的重叠和碰撞
 *       關鍵就是解決標記重疊問題， 使得每個節點每個時候最多只有一個標記。
 *       請參考 TransStatus 這個函數，狀態值取XOR運算後即是翻轉後的結果
 * setv=0，整個區間的各個值都是0
 * setv=1，整個區間的各個值都是1
 * setv=2，初始狀態
 * setv=3，翻轉一次
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1024000;
const int MAXS=(1<<(__lg(MAXN)+1)|1)<<1;
int N, ansv, qL, qR, qV;
bool org[MAXN];
struct SegmentTree{
  int sumv,setv;
  SegmentTree(int a=0,int b=-1):sumv(a),setv(b){}
}seg[MAXS];

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
void BuildTree(int nL,int nR,int pt){
  seg[pt].setv=2;
  if(nL==nR){ seg[pt].sumv=org[nL]; return; }
  int nM=(nL+nR)>>1, Lson=pt<<1, Rson=Lson|1;
  BuildTree(  nL,nM,Lson),
  BuildTree(nM+1,nR,Rson);
  seg[pt].sumv=seg[Lson].sumv+seg[Rson].sumv;
}
void TransStatus(int nL,int nR,int pt,int cmd){
  if(cmd==1)     seg[pt].setv=1, seg[pt].sumv=nR-nL+1;
  else if(cmd==0)seg[pt].setv=0, seg[pt].sumv=0;
  else           seg[pt].setv^=1,seg[pt].sumv=nR-nL+1-seg[pt].sumv;
}
void Update_part(int nL,int nR,int pt){
  if(qL<=nL and nR<=qR){  TransStatus(nL,nR,pt,qV);  return; }
  int nM=(nL+nR)>>1, Lson=pt<<1, Rson=Lson|1;
  // ---PushDown---
  if(seg[pt].setv!=2)
    TransStatus(  nL,nM,Lson,seg[pt].setv),
    TransStatus(nM+1,nR,Rson,seg[pt].setv),
    seg[pt].setv=2;
  if(qL<=nM) Update_part(  nL,nM,Lson);
  if(qR>nM)  Update_part(nM+1,nR,Rson);
  // ---PushUp---
  seg[pt].sumv=seg[Lson].sumv+seg[Rson].sumv;
}
void Query_part(int nL,int nR,int pt){
  if(qL<=nL and nR<=qR){ ansv+=seg[pt].sumv; return; }
  int nM=(nL+nR)>>1, Lson=pt<<1, Rson=Lson|1;
  // ---PushDown---
  if(seg[pt].setv!=2)
    TransStatus(  nL,nM,Lson,seg[pt].setv),
    TransStatus(nM+1,nR,Rson,seg[pt].setv),
    seg[pt].setv=2;
  if(qL<=nM) Query_part(  nL,nM,Lson);
  if(qR>nM)  Query_part(nM+1,nR,Rson);
  // ---PushUp---
  seg[pt].sumv=seg[Lson].sumv+seg[Rson].sumv;
}

int main(){
  int T, pairN, repeat, sslen;
  char ss[52];
  scanInt(T);
  for(int caseN=1;caseN<=T;caseN++){
    printf("Case %d:\n",caseN);
    // ---讀取測資---
    scanInt(pairN);
    for(N=0;pairN--;){
      scanInt(repeat);
      for(sslen=0;(ss[sslen]=getchar())!='\n';sslen++);
      for(int i=0;i<repeat;i++)
        for(int j=0;j<sslen;j++)
          org[N++]=(ss[j]=='1');
    }
    BuildTree(0,N-1,1);
    // ---根據指令操作---
    int Q, Q_no=1;
    for(scanInt(Q);Q--;){
      char cmd=getchar(); getchar();
      scanInt(qL);
      scanInt(qR);
      if(cmd=='S'){
        ansv=0,
        Query_part(0,N-1,1),
        printf("Q%d: %d\n",Q_no++,ansv);
      }else{
        if(cmd=='F') qV=1;
        else if(cmd=='E') qV=0;
        else qV=-1;
        Update_part(0,N-1,1);
      }
    }
  }
}
/*
2
2
5
10
2
1000
5
F 0 17
I 0 5
S 1 10
E 4 9
S 2 10
3
3
1
4
0
2
0
2
I 0 2
S 0 8
*/