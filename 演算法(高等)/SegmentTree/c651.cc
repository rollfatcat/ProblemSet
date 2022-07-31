/*
 */

#include<bits/stdc++.h>
using namespace std;

int qL, qR, status;
int map_data[1000002], segtr[4000008];
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
void BuildTree(int nL,int nR,int pt){ //建樹，同時把最底層端點的位置映射回map_data便於單點修改時查表
  if(nL==nR){ segtr[pt]=map_data[nL], map_data[nL]=pt; return; }
  int mid=(nL+nR)>>1, Lson=pt<<1;
  BuildTree(   nL,mid,  Lson);
  BuildTree(mid+1, nR,Lson+1);
  segtr[pt]=segtr[Lson]^segtr[Lson+1];
}
void Query(int nL,int nR,int pt){ // 區間查詢
  if(qL<=nL and nR<=qR){ status^=segtr[pt]; return; }
  int mid=(nL+nR)>>1, Lson=pt<<1;
  if(qL<=mid) Query(   nL,mid,  Lson);
  if(qR>mid ) Query(mid+1, nR,Lson+1);
}
void Modify(int nL,int nR,int pt){// 單點修改+lazy
  segtr[pt]^=qR;
  if(nL==nR) return;
  int mid=(nL+nR)>>1, Lson=pt<<1;
  if(qL<=mid) Modify(   nL,mid,  Lson);
  else        Modify(mid+1, nR,Lson+1);
}
int main(){
  int N, Q, act;
  scanInt(N),
  scanInt(Q);
  for(int i=1;i<=N;i++)
    scanInt(map_data[i]);
  BuildTree(1,N,1);
  while(Q--){
    scanInt(act),
    scanInt(qL),
    scanInt(qR);
    // 單點修改：先查詢原位置的數值(根據映射表存的位置)和要修改成的值作XOR，
    // 之後根據拜訪過的區間作XOR的值修改
    if(act)
      qR^=segtr[ map_data[qL] ],
      Modify(1,N,1);
    else // 區間查詢：將落在(qL,qR)內的各個片段作XOR後輸出 <- TLE的原因
      status=0,
      Query(1,N,1),
      printf("%d\n",status);
  }
}