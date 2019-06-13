// 參考文章有多處需要勘誤，見詳解
// 模板(極值/區間和)，支援可以單點查詢/單點修改/區間查詢/區間修改
// 網址參考：
// 區間極值查詢和更新請參照：https://zhuanlan.zhihu.com/p/29937723
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5;
int N, Q, M;
int maxtr[MAXN]={};
int mintr[MAXN]={};
int sumtr[MAXN]={};
int addtr[MAXN]={}; // <- lazy_update，但zkw式本身就是自下而上根本無法彰顯效果...

// ---單點修改---
// 和SegmentTree相比：不需要先做TopDown找到葉子才BottomUp更新到Root
void Update_node(int pos,int d){
  pos+=M;
  maxtr[pos]+=d,
  mintr[pos]+=d,
  sumtr[pos]+=d;
  for(int tmp; pos>1; pos>>=1){
    sumtr[pos>>1]+=d; // <- 文章需要勘誤部分
    // --- pos^1=鄰近的兄弟點 ---
    tmp=min(mintr[pos],mintr[pos^1]), mintr[pos]-=tmp,  mintr[pos^1]-=tmp,  mintr[pos>>1]+=tmp;
    tmp=max(maxtr[pos],maxtr[pos^1]), maxtr[pos]-=tmp,  maxtr[pos^1]-=tmp,  maxtr[pos>>1]+=tmp;
  }
}

// ---單點(極值)查詢---(會併到『區間查詢內』的額外處理部分)
void Query_node(int pos){
  int maxN=0, minN=0;
  for(int idx=pos+M; idx; idx>>=1)
    maxN+=maxtr[idx],
    minN+=mintr[idx];
}

// ---區間修改--- 有特殊情況需要討論(文章證明不需額外處理)
void Update_part(int nL,int nR,int d){
  int tmp, len=1; // <-  一開始都是從底層開始網上更新，底層的間隔長度=1，每往上一層就加倍
  int lc=0, rc=0; // <-  就是 nL 節點和 nR 節點分別走過的節點中所包含的更新區間的長度
  //  左右邊界外擴1
  for(nL+=M-1,nR+=M+1; nL^nR^1; nL>>=1,nR>>=1,len<<=1){ // <- 當左右節點是兄弟節點時就停止遞迴

    //在這裏的 add 就是標記數組了
    if(~nL&1) // <-當前節點屬於父結點的左子樹，代表右子樹屬於更新區間內
      addtr[nL^1]+=d, mintr[nL^1]+=d, maxtr[nL^1]+=d, lc+=len;
    if(nR&1)  // <-當前節點屬於父結點的右子樹，代表左子樹屬於更新區間內
      addtr[nR^1]+=d, mintr[nR^1]+=d, maxtr[nR^1]+=d, rc+=len;

    sumtr[nL>>1]+=d*lc, // <-當前節點的父結點數值必須加上由從底層和右子樹(如果存在)的增量
    sumtr[nR>>1]+=d*rc; // <-當前節點的父結點數值必須加上由從底層和左子樹(如果存在)的增量

    tmp=min(mintr[nL],mintr[nL^1]), mintr[nL]-=tmp, mintr[nL^1]-=tmp, mintr[nL>>1]+=tmp;
    tmp=min(mintr[nR],mintr[nR^1]), mintr[nR]-=tmp, mintr[nR^1]-=tmp, mintr[nR>>1]+=tmp;

    tmp=max(maxtr[nL],maxtr[nL^1]), maxtr[nL]-=tmp, maxtr[nL^1]-=tmp, maxtr[nL>>1]+=tmp;
    tmp=max(maxtr[nR],maxtr[nR^1]), maxtr[nR]-=tmp, maxtr[nR^1]-=tmp, maxtr[nR>>1]+=tmp;
  }
  for(lc+=rc; nL>1; nL>>=1){ // <- 繼續更新直到Root，文章需要勘誤部分
    sumtr[nL>>1]+=d*lc;
    tmp=min(mintr[nL],mintr[nL^1]), mintr[nL]-=tmp, mintr[nL^1]-=tmp, mintr[nL>>1]+=tmp;
    tmp=max(maxtr[nL],maxtr[nL^1]), maxtr[nL]-=tmp, maxtr[nL^1]-=tmp, maxtr[nL>>1]+=tmp;
  }
}

// ---區間和查詢---
int Query_RangeSum(int qL,int qR){
  int lc=0, rc=0;
  int len=1,sumN=0;
  for(qL+=M-1,qR+=M+1; qL^qR^1; qL>>=1,qR>>=1,len<<=1){
    if(qL&1^1)
      sumN+=sumtr[qL^1]+len*addtr[qL^1],lc+=len;
    if(qR&1)
      sumN+=sumtr[qR^1]+len*addtr[qR^1],rc+=len;

    if(addtr[qL>>1])
      sumN+=addtr[qL>>1]*lc;
    if(addtr[qR>>1])
      sumN+=addtr[qR>>1]*rc;
  }
  for(lc+=rc,qL>>=1; qL; qL>>=1)
    if(addtr[qL])
      sumN+=addtr[qL]*lc;
  return sumN;
}

// ---區間最小值查詢---
int Query_RangeMin(int qL,int qR){
  int L=0, R=0, minN=0;
  // ---單點查詢額外處理，避免qL和qR永遠都不會是左右子樹的情況---
  if(qL==qR){
    for(int idx=qL+M; idx; idx>>=1)
      minN+=mintr[idx];
    return minN;
  }
  // ---區間最小值查詢：範圍不需要往外擴1，避免查到不相關的點---
  for(qL+=M,qR+=M; qL^qR^1; qL>>=1,qR>>=1){
    // 累加當前的值求得到該區間為止的最小值
    L+=mintr[qL],
    R+=mintr[qR];
    if(qL&1^1) L=min(L,mintr[qL^1]);
    if(qR&1)   R=min(R,mintr[qR^1]);
  }
  // ---判斷是左右節點時沒有加到的部分要追加回去---
  minN=min(L+mintr[qL],R+mintr[qR]);  // <- 文章需要勘誤的部分
  for(qL>>=1; qL; qL>>=1) // 累加到跟節點
    minN+=mintr[qL];
  return minN;
}
// ---區間最大值查詢---
int Query_RangeMax(int qL,int qR){
  int L=0, R=0, maxN=0;
  // ---單點查詢額外處理，避免qL和qR永遠都不會是左右子樹的情況---
  if(qL==qR){
    for(int idx=qL+M; idx; idx>>=1)
      maxN+=maxtr[idx];
    return maxN;
  }
  // ---區間最大值查詢：不需要外擴1，避免查到不相關的點---
  for(qL+=M,qR+=M; qL^qR^1; qL>>=1,qR>>=1){
    L+=maxtr[qL],
    R+=maxtr[qR];
    if(qL&1^1) L=max(L,maxtr[qL^1]);
    if(qR&1)   R=max(R,maxtr[qR^1]);
  }
  maxN=max(L+maxtr[qL],R+maxtr[qR]); // <- 文章需要勘誤的部分
  for(qL>>=1; qL; qL>>=1)
    maxN+=maxtr[qL];
  return maxN;
}

// ---主程式---
int main(){
  scanf("%d",&N);
  // ---建樹---
  M=1<<(__lg(N)+1); // <- 找到一個大於N的2^k
  sumtr[M]=0, maxtr[M]=0, mintr[M]=1<<30; // <- 本來是該初始化全部的葉子不過偷懶只初始化這個點
  for(int i=M+1;i<=M+N;i++)
    scanf("%d",&sumtr[i]),  maxtr[i]=mintr[i]=sumtr[i];
  // ---極值的儲存方式是差分---
  /* 該點的訊息是自己與父結點的差值 : tree[i]-=min(tree[i],tree[i^1])
   * 計算該區間內的極值是 tree[i]+tree[i>>1]+...+tree[root]
   * 目的是區間修改時的複雜度下降
   * 在區間修改時，如果某個子樹的所有葉子都在这個修改區間内，我们只需要修改該子樹根结點即可
   */
  for(int i=M-1; i; i--){
    sumtr[i]=sumtr[i<<1]+sumtr[i<<1|1];

    maxtr[i]=max(maxtr[i<<1],maxtr[i<<1|1]),
    maxtr[i<<1]-=maxtr[i], maxtr[i<<1|1]-=maxtr[i]; // <- 支援可修改版本

    mintr[i]=min(mintr[i<<1],mintr[i<<1|1]),
    mintr[i<<1]-=mintr[i], mintr[i<<1|1]-=mintr[i]; // <- 支援可修改版本
  }

  for(scanf("%d",&Q); Q--;){
    int act, a, b, c;
    scanf("%d %d %d %d",&act,&a,&b,&c);

    if(act==1){ // act=1：更新，(a,b,c)=(st,ed,diff)
      if(a==b)  Update_node(a,c);
      else      Update_part(a,b,c);
    }
    else if(act==2){ // act=2：查詢，(a,b,c)=(type,st,ed)
      if(a==1) printf("%d\n",Query_RangeSum(b,c)); // type=1：區間和
      if(a==2) printf("%d\n",Query_RangeMin(b,c)); // type=2：區間最小值
      if(a==3) printf("%d\n",Query_RangeMax(b,c)); // type=3：區間最大值
    }
  }
}
/*
7
6 1 2 7 4 5 3
30
1 1 4 1
1 3 6 1
1 3 3 1
2 2 3 5
2 2 5 6
2 2 4 6
*/
/*
6 1 2 7 4 5 3
7 2 3 8 4 5 3
7 2 4 9 5 6 3
7 2 5 9 5 6 3
*/