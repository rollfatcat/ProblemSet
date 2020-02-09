/* 正解：區間和＝前綴和+要增加的高度x區間個數-(區間個數-沒爆料)x1e5
 * 以下解法是『離線』『樹狀樹組解法』，離線意味著需要將所有的查詢預先存起來做排序。
 * 記憶體耗量比較：離線作法需要儲存所有的查詢並且需要排序的時間成本O( (N+Q)㏒(N+Q) )。
 * 主席樹則是根據持久化的概念儲存所有路徑的節點，節點數量和輸入的個數(離散化後)有關
 * 時間成本在建樹的過程要消耗N㏒N，需要根據查詢的次數決定使用離線還是在線查詢。
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define MAXH 100000
#define lowbit(x) (x&-x)

int N, Q, tot=0;
int BIT[MAXN<<2];
long sumh[MAXN];
long ans[5*MAXN];

struct QUERY{
  bool type;
  int L,R,H,ID;
  QUERY(int qL=0,int qR=0,int qH=0,int ID=0,bool t=0):L(qL),R(qR),H(qH),ID(ID),type(t){}
  bool operator<(const QUERY &rhs)const{ return (H==rhs.H)? (type<rhs.type): (H<rhs.H); }
}query[6*MAXN];
inline void update(int pos){ // 更新葉節點
  for(; pos<=N; pos+=lowbit(pos))
    BIT[pos]++;
}
inline int queryBIT(int pos,int ret=0){
  for(; pos; pos-=lowbit(pos))
    ret+=BIT[pos];
  return ret;
}
inline void scanInt(int &x){
  char c;
  while((c=getchar())==' ' or c=='\n');
  for(x=c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
}
int main(){
  int x, qL, qR;
  scanInt(N),
  scanInt(Q);
  for(int i=1;i<=N;i++)
    scanInt(x),
    query[tot++]=QUERY(i,i,x),
    sumh[i]=sumh[i-1]+x;

  int opt, nowH=MAXH, ansNum=0;
  for(int i=0;i<Q;i++){
    scanInt(opt);
    if(opt==2){
      scanInt(qL),
      scanInt(qR);
      query[tot++]=QUERY(qL,qR,nowH,ansNum,1), ansNum++;
    }
    else{
      scanInt(qL),
      nowH-=(qL%MAXH);
      if(nowH<0)
        nowH+=MAXH;
    }
  }

  sort(query,query+tot);
  long cnt, NotOver;
  for(int i=0;i<tot;i++)
    if(query[i].type)
      cnt=query[i].R-query[i].L+1,
      NotOver=queryBIT(query[i].R)-queryBIT(query[i].L-1),
      ans[ query[i].ID ]=sumh[query[i].R]-sumh[query[i].L-1]+(MAXH-query[i].H)*cnt-(cnt-NotOver)*MAXH;
    else
      update(query[i].L);

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