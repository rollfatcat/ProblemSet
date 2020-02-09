// 主席樹＝持久化線段樹
// 原文說明：https://www.jianshu.com/p/e1d46a714fa8
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000 // 1e5 < 131072(1<<17)

// 因为節點每次至多更新O(logn)個，所以數组範圍應該在原來的20-50倍左右。
int tot=0; // 計數器，代表目前全部的節點數
int rt[MAXN*20],   //   rt[x]:第x次操作做時的根節點號碼
    lson[MAXN*20], // lson[x]:節點x的左節點
    rson[MAXN*20], // rson[x]:節點x的右節點
    sumv[MAXN*20], // sumv[x]:節點x的總和
    lazy[MAXN*20]; // lazy[x]:節點x的懶散標記
int qL, qR, qK;

void push_up(int x){
  sumv[x]=sumv[ lson[x] ]+sumv[ rson[x] ];
}
void push_down(int x,int len){
  if(lazy[x]){
    sumv[ lson[x] ]+=(len>>1)*lazy[x];
    sumv[ rson[x] ]+=(len-(len>>1))*lazy[x];
    lazy[ lson[x] ]+=(len>>1)*lazy[x];
    lazy[ rson[x] ]+=(len-(len>>1))*lazy[x];
    lazy[x]=0;
  }
}
void buildtree(int &x,int nL,int nR){
  x=++tot;
  lazy[x]=0;
  if(nL==nR){ // 到達葉節點時讀取原始資料(單點資訊)
    scanf("%d",&sumv[x]);
    return;
  }
  int nM=nL+nR>>1;
  buildtree(lson[x],  nL,nM);
  buildtree(rson[x],nM+1,nR);
  push_up(x);
}
void update(int nL,int nR,int &x,int last){
  x=++tot;
  lson[x]=lson[last];
  rson[x]=rson[last];
  sumv[x]=sumv[last];
  lazy[x]=lazy[last];
  if(qL<=nL and nR<=qR){
    sumv[x]+=(nR-nL+1)*qK;
    lazy[x]+=qK;
    return;
  }
  push_down(x,nR-nL+1);
  int nM=nL+nR>>1;
  if(qL<=nM) update(  nL,nM,lson[x],lson[last]);
  if(qR>nM ) update(nM+1,nR,rson[x],rson[last]);
  push_up(x);
}
int query(int nL,int nR,int x){
  if(qL<=nL and nR<=qR)
    return sumv[x];

  push_down(x,nR-nL+1);
  int nM=nL+nR>>1, sum=0;
  if(qL<=nM) sum+=query(  nL,nM,lson[x]);
  if(qR>nM ) sum+=query(nM+1,nR,rson[x]);
  push_up(x);
  return sum;
}

int main(){
  int N, Q, opt;

  scanf("%d %d",&N,&Q);
  buildtree(rt[0],1,N);

  //
  for(int i=1;i<=Q;i++){ // 根據現在版本查詢區間和
    scanf("%d",&opt);
    if(opt==1){
      rt[i]=rt[i-1];
      scanf("%d %d",&qL,&qR);
      printf("%d\n",query(1,N,rt[i]));
    }
    else if(opt==2){ // 新增修改的節點
      scanf("%d %d %d",&qL,&qR,&qK);
      int pre_tot=tot;
      update(1,N,rt[i],rt[i-1]);
      for(int i=pre_tot+1;i<=tot;i++)
        printf("%d %d %d %d\n",i,lson[i],rson[i],sumv[i]);
    }
    else{ // 版本回朔
      scanf("%d",&opt);
      rt[i]=rt[opt];
    }
  }
}
/*
10 8
1 2 3 4 5 6 7 8 9 10
2 6 7 2
1 6 7
2 3 5 4
1 3 5
2 1 9 5
1 1 9
3 3
1 1 10
17
24
106
71
*/