// 題解：http://cthbstalpha.blogspot.com/2017/01/hdu-4417-super-mario.html
/* 離散線段樹解法(比賽時通常會吃TLE)
 * 可以先將所有詢問的區間與每次查詢的H存下來，將每個 H 由小到大排序，
 * 每次要查詢的時候就查詢數列中小於等於 H 的這些項目，只查詢小於等於 H 這個操作可以用線段樹來維護
 * ，用線段樹維護一個數列，數列一開始全部都是 0 ，如果這一格在原本的數列中的值小於等於 H，
 * 就設成為 1 ，這個操作也可以用 BIT 來維護，要求區間有幾個數字就是將區間的 1 全部加起來。
 * 時間 O( (n+Q)log(n+Q) + Q log(n) ) 空間 O(n)
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001

struct QUERY{
  bool type;
  int L,R,H,ID;
  QUERY(int qL=0,int qR=0,int qH=0,int ID=0,bool t=0):L(qL),R(qR),H(qH),ID(ID),type(t){}
  bool operator<(const QUERY &rhs)const{ return (H==rhs.H)? (type<rhs.type): (H<rhs.H); }
}query[MAXN<<1];

int N, Q, tot, qL, qR;
int seg[MAXN<<2];
int ans[MAXN];

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

int main(){
  int caseT, qH;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d%d",&N,&Q);
    memset(seg,0,sizeof(seg));
    tot=0;
    // 讀取測資
    for(int i=0;i<N;i++)
      scanf("%d",&qH),
      query[tot++]=QUERY(i,i,qH);
    for(int i=0;i<Q;i++)
      scanf("%d%d%d",&qL,&qR,&qH),
      query[tot++]=QUERY(qL,qR,qH,i,1);
    sort(query,query+tot);

    for(int i=0;i<tot;i++)
      if(query[i].type)
        qL=query[i].L,
        qR=query[i].R,
        ans[ query[i].ID ]=querySeg(0,N-1,1);
      else
        qL=query[i].L,
        update(0,N-1,1);
    // 依照查詢順序輸出答案
    for(int i=0;i<Q;i++)
      printf("%d\n",ans[i]);
  }
}
/*
1
10 10
0 5 2 7 5 4 3 8 7 7
2 8 6
3 5 0
1 3 1
1 9 4
0 1 0
3 5 5
5 5 1
4 6 3
1 5 7
5 7 3
*/