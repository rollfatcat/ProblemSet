// 文件說明：https://blog.csdn.net/cillyb/article/details/75946694
// 注意：說明S[x]的圖片有問題，更新路徑上的節點是錯誤的。
/* 原題型：ZOJ-2112 / BZOJ-1901
 *『動態』區間第Ｋ大數，支援單點更新 => 無法用劃分/歸併樹解法
 * 和靜態的差異在於更新：不改變已經建好的樹，而是另建一批樹srot，用来紀錄更新，
 * 兩批樹的數量是一樣的，都是由原始數據的個數決定(這和主席樹實作方式有關)。
 * 而这批線段樹，我们用樹狀樹组来維護，也就是樹狀數組的每個節點都是一棵線段數
 * 初始化時srot[0]...srot[5](樹狀數組的每個節點)这些都與 root[0]相同(也就是每个節點建了一棵空樹)。
 * 對於C 2 6 這個操作， 我们要將原資料位置2紀錄的數字改為6，
 * 即是更新到達葉節點2的路徑上紀錄的sumn[]-1＋到達葉節點2的路徑上紀錄的sumn[]+1即可
 * 樹狀數組的維護方式：i+lowbit(i)為 i的父節點，修改i，就要把i的所有父節點都修改
 * 更新位置2，2在樹狀數組中出現的位置是 2、2+lowbit(2)=4 這兩個位置
 * 因此要更新的是srot[2]和srot[4]这两个節點中的樹
 */

#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)

const int MAXN=32002;
const int MAXQ= 5002;
const int MAXM=37002; // 32000+5000
int lson[MAXM<<5]; // 空間的估算：__lg(MAXN)+1+4=21
int rson[MAXM<<5];
int sumn[MAXM<<5];
int root[MAXN];
int srot[MAXN]; // 新增的根節點數量需要和原先線段樹的個數相同
int org[MAXM];
int srt[MAXM];
int use[MAXN];
int tot, qP, qL, qR, qK;
struct EVENT{ bool type; int qL,qR,qK; } event[5001];

void build(int nL,int nR,int &now){
  now=++tot;
  sumn[now]=0;
  if(nL==nR) return;
  int nM=nL+nR>>1;
  build(  nL,nM,lson[now]);
  build(nM+1,nR,rson[now]);
}
void update(int nL,int nR,int &now,int pre){
  now=++tot;
  lson[now]=lson[pre];
  rson[now]=rson[pre];
  sumn[now]=sumn[pre]+qK;
  if(nL==nR) return;
  int nM=nL+nR>>1;
  if(qP<=nM) update(  nL,nM,lson[now],lson[pre]);
  else       update(nM+1,nR,rson[now],rson[pre]);
}
int query(int nL,int nR,int vL,int vR,int k){
  if(nL==nR) return nL;
  int nM=nL+nR>>1;
  int cnt=sumn[ lson[vR] ]-sumn[ lson[vL] ];// 這裡只計算 root 的總和
  // 用BIT方式加總srot那邊的樹群
  for(int x=qR;x;x-=lowbit(x))
    cnt+=sumn[ lson[use[x]] ];
  for(int x=qL;x;x-=lowbit(x))
    cnt-=sumn[ lson[use[x]] ];
  // 判斷往左還是往右，遞迴之前先把下次會用到的位置複製過去(根據左右決定複製的號碼)
  if(k<=cnt){
    for(int x=qR; x; x-=lowbit(x))
      use[x]=lson[use[x]];
    for(int x=qL; x; x-=lowbit(x))
      use[x]=lson[use[x]];
    return query(  nL,nM,lson[vL],lson[vR],k);
  }
  else{
    for(int x=qR; x; x-=lowbit(x))
      use[x]=rson[use[x]];
    for(int x=qL; x; x-=lowbit(x))
      use[x]=rson[use[x]];
    return query(nM+1,nR,rson[vL],rson[vR],k-cnt);
  }
}
int main(){
  char opt[10];
  int N, Q, uN, tN;

  while(scanf("%d%d",&N,&Q)==2){
    for(int i=1;i<=N;i++)
      scanf("%d",&org[i]),
      srt[i]=org[i];
    // 建點時要預先把所有的節點讀入(包含要更新的數字)
    uN=N;
    for(int i=1;i<=Q;i++){
      scanf("%s",opt),
      event[i].type=opt[0]=='Q';
      if(event[i].type)
        scanf("%d%d%d",&event[i].qL,&event[i].qR,&event[i].qK);
      else // (qL,qR,qK)=(要修改的位置,x,修改後的數值)
        scanf("%d%d",&event[i].qL,&event[i].qK),
        ++uN, srt[uN]=org[uN]=event[i].qK;
    }
    sort(srt+1,srt+1+uN);
    uN=unique(srt+1,srt+1+uN)-srt-1;
    tot=0,
    build(1,uN,root[0]);
    // 離散化處理
    for(int i=1;i<=N;i++)
      qP=lower_bound(srt+1,srt+1+uN,org[i])-srt, qK=1,
      update(1,uN,root[i],root[i-1]);
    for(int i=1;i<=N;i++)
      srot[i]=root[0];
    // 根據指令執行
    for(int i=1;i<=Q;i++){
      if(event[i].type){ //query
        qL=event[i].qL-1,
        qR=event[i].qR;
        // 複製等下會用到的線段樹節點(不同棵但都屬於同一個位置)
        for(int j=qL; j; j-=lowbit(j))
          use[j]=srot[j];
        for(int j=qR; j; j-=lowbit(j))
          use[j]=srot[j];
        printf("%d\n",srt[ query(1,uN,root[qL],root[qR],event[i].qK) ] );
      }
      else{ //modify
        // 更新樹狀數組的線段樹srot[]
        for(int j=event[i].qL;j<=N;j+=lowbit(j))
          qP=lower_bound(srt+1,srt+1+uN,org[event[i].qL] )-srt, qK=-1,
          update(1,uN,srot[j],srot[j]);
        for(int j=event[i].qL;j<=N;j+=lowbit(j))
          qP=lower_bound(srt+1,srt+1+uN,event[i].qK )-srt, qK=1,
          update(1,uN,srot[j],srot[j]);
        // 更新原始資料的紀錄
        org[ event[i].qL ]=event[i].qK;
      }
    }

  }
}
/*
5 3
3 2 1 4 7
Q 1 4 3
C 2 6
Q 2 5 3

5 3
1 2 3 4 5
Q 1 4 2
C 2 6
Q 1 4 2
*/