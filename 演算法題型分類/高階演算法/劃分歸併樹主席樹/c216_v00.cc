/* 正解：區間和＝前綴和+要增加的高度x區間個數-(區間個數-沒爆料)x1e5
 * 以下解法是『離線』『線段樹解法』，離線意味著需要將所有的查詢預先存起來做排序。
 * 記憶體消耗較大，一般比賽時這樣的做法可能會 TLE 或 MLE。
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000

int N, Q, tot=0, qL, qR;
int seg[MAXN<<2];
long sumh[MAXN+1];
long ans[5*MAXN];

struct QUERY{
  bool type;
  int L,R,H,ID;
  QUERY(int qL=0,int qR=0,int qH=0,int ID=0,bool t=0):L(qL),R(qR),H(qH),ID(ID),type(t){}
  bool operator<(const QUERY &rhs)const{ return (H==rhs.H)? (type<rhs.type): (H<rhs.H); }
}query[6*MAXN];
void update(int nL,int nR,int pt){ // 更新葉節點
  if(nL==nR and nL==qL){ seg[pt]++; return; }
  int nM=nL+nR>>1;
  (qL<=nM)? update(nL,nM,pt<<1): update(nM+1,nR,pt<<1|1);
  seg[pt]=seg[pt<<1]+seg[pt<<1|1];
}
int querySeg(int nL,int nR,int pt){
  if(qL<=nL and nR<=qR)
    return seg[pt];
  int nM=nL+nR>>1, ret=0;
  if(qL<=nM)  ret+=querySeg(nL,nM,pt<<1);
  if(qR>nM )  ret+=querySeg(nM+1,nR,pt<<1|1);
  return ret;
}
inline void scanInt(int &x){
  char c;
  while((c=getchar())==' ' or c=='\n');
  for(x=c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
}
int main(){
  int x;
  scanInt(N),
  scanInt(Q);
  for(int i=1;i<=N;i++)
    scanInt(x),
    query[tot++]=QUERY(i,i,x),
    sumh[i]=sumh[i-1]+x;

  int opt;
  int nowH=MAXN, ansNum=0;
  for(int i=0;i<Q;i++){
    scanInt(opt);
    if(opt==2){
      scanInt(qL),
      scanInt(qR);
      query[tot++]=QUERY(qL,qR,nowH,ansNum,1), ansNum++;
    }
    else{
      scanInt(qL),
      nowH-=(qL%MAXN);
      if(nowH<0)
        nowH+=MAXN;
    }
  }

  sort(query,query+tot);
  long cnt;
  for(int i=0;i<tot;i++)
    if(query[i].type)
      qL=query[i].L,
      qR=query[i].R,
      cnt=qR-qL+1,
      ans[ query[i].ID ]=sumh[qR]-sumh[qL-1]+(MAXN-query[i].H)*cnt-(cnt-querySeg(1,N,1))*MAXN;
    else
      qL=query[i].L,
      update(1,N,1);

  // 依照查詢順序輸出答案
  for(int i=0;i<ansNum;i++)
    printf("%ld\n",ans[i]);
}
/*
5 6
1 2 3 4 5
1 99995
2 1 4
1 2
2 2 5
1 2
2 1 5
===
99998 99999 100000 1 2
*/