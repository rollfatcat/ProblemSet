// zkw式線段樹＋掃描線＋離散化(需要離散化兩個維度的座標) => 0.24s
/* 因為 PushUp() 只會向上更新可以用zkw式線段樹維護
 * Update() 時不管是不是『在區間內』都要 PushUp()，而在區間內時記得要更新 zkw_cvr[] 的值
 * 對於 PushUp() 要區分是不是葉節點而 zkw式的Update() 只要檢查『一開始』即可
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=30005;
int Posy[MAXN<<1];
int N, M, qB; // (unique)node_num=N, zkw_base=M
struct LINE{
  int x, d, u, t;
  LINE(int x=0,int d=0,int u=0,int t=0):x(x),d(d),u(u),t(t){}
  bool operator<(const LINE &rhs)const{ return x<rhs.x; }
}line[MAXN<<1];
int zkw_cvr[MAXN<<3], zkw_sum[MAXN<<3][11];

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
inline void PushUp(int pt){
  memset(zkw_sum[pt],0,sizeof(zkw_sum[pt]));
  for(int i=0;i<=qB;i++)
    zkw_sum[pt][ min(qB,i+zkw_cvr[pt]) ]+=zkw_sum[pt<<1][i]+zkw_sum[pt<<1|1][i];
}
void Query(int qL,int qR,int qD,int t){
  qL+=M-1,
  qR+=M+1;
  int sL=qL^1, sR=qR^1;
  if(~qL&1)
    zkw_cvr[sL]+=qD,
    memset(zkw_sum[sL],0,sizeof(zkw_sum[sL])),
    zkw_sum[sL][ min(qB,zkw_cvr[sL]) ]=Posy[sL-M]-Posy[sL-M-1];
  if(qR&1)
    zkw_cvr[sR]+=qD,
    memset(zkw_sum[sR],0,sizeof(zkw_sum[sR])),
    zkw_sum[sR][ min(qB,zkw_cvr[sR]) ]=Posy[sR-M]-Posy[sR-M-1];

  for(qL>>=1,qR>>=1; qL^qR^1; qL>>=1,qR>>=1){
    if(~qL&1) zkw_cvr[qL^1]+=qD, PushUp(qL^1);
    if( qR&1) zkw_cvr[qR^1]+=qD, PushUp(qR^1);
    PushUp(qL),
    PushUp(qR);
  }
  for(PushUp(qR);qL;qL>>=1)
    PushUp(qL);
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
    N=unique(Posy,Posy+tot)-Posy;

    // ---建表時注意如何將離散後的點轉成線段的長度---
    // 線段的右端點號碼代表該線段編號 => Ｎ個離散化後的點代表Ｎ-1個線段
    // ---BuildTree()---
    memset(zkw_cvr,0,sizeof(zkw_cvr));
    memset(zkw_sum,0,sizeof(zkw_sum));
    M=1<<(__lg(N-1)+1);
    for(int i=1;i<N;i++)
      zkw_sum[i+M][0]=Posy[i]-Posy[i-1];
    for(int i=M-1;i>0;i--)
      zkw_sum[i][0]=zkw_sum[i<<1][0]+zkw_sum[i<<1|1][0];
    // ---Main Function---
    long ans=0;
    Query(lower_bound(Posy,Posy+N,line[0].d)-Posy+1,
          lower_bound(Posy,Posy+N,line[0].u)-Posy,
          line[0].t,0);
    for(int i=1;i<tot;i++){
      ans+=(line[i].x-line[i-1].x)*(long)zkw_sum[1][qB];
      Query(lower_bound(Posy,Posy+N,line[i].d)-Posy+1,
            lower_bound(Posy,Posy+N,line[i].u)-Posy,
            line[i].t, i);
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
2 2 3 3
1 1 2 2
*/